#include "Data.h"

//=============================================================================
void vMIDI::Data::getFromFile(File& file)
{
	// This will extract the data from the file stream,
	// so don't use it again after this

	std::vector<char> tempChar;
	std::vector<uint8_t> tempUint;

	for (int i {0}; file.getStream(); ++i)
	{
		file.getStream().seekg(i);

		tempChar.push_back('0');
		file.getStream().get(tempChar[i]);

		data.push_back(static_cast<uint8_t>(tempChar[i]));
	}
}

//=============================================================================
// Header
void vMIDI::Data::setSharedData()
{
	position = data.begin();
	header();
}

//=============================================================================
// Tracks
void vMIDI::Data::writeToTracks(std::vector<std::unique_ptr<MidiTrack>>& trks)
{
	tracks = &trks;

	if (position != data.begin() + 14)
		position = data.begin() + 14;

	for (int i {0}; i < SharedData::getNumberOfTracks(); ++i)
	{
		if (*position == 'M' &&
			*(position + 1) == 'T' &&
			*(position + 2) == 'r' &&
			*(position + 3) == 'k')
		{
			track(i);
		}
	}
}

//=============================================================================
void vMIDI::Data::header()
{
	// MThd
	position += 4;

	// Header length value
	position += 4;

	// Format (00 00, 00 01 or 00 02)
	SharedData::setFormat((*position << 8 | *(position + 1)));
	position += 2;

	// Number of tracks
	SharedData::setNumberOfTracks((*position << 8 | *(position + 1)));
	position += 2;

	/*************************************************************************************
	| TIMING (OR DIVISION)                                                               |
	|                                                                                    |
	| byte 1    byte 2                                                                   |
	| 1000 0000 0000 0000                                                                |
	| The 1 here represents bit 15 (from the right)                                      |
	| If it's set to 0, the midi file uses metrical timing (bars and beats)              |
	| If it's set to 1, the midi file uses timecode (hours, minutes, seconds and frames) |
	|                                                                                    |
	| If metrical timing                                                                 |
	| The other 15 bits is the number of pulses per quarter-note (ppqn)                  |
	|                                                                                    |
	| If timecode                                                                        |
	| The first 8 bits (the first byte, from the left) is the fps (24, 25, 29 or 30)     |
	| The other 8 bits (the second byte, from the left) is the sub-frame resolution      |
	| (sub-divisions of a frame)                                                         |
	*************************************************************************************/

	// Timing
	SharedData::setTiming((*position << 8 | *(position + 1)));
	position += 2;

	// If bit 15 is set (0x8000 is 1000 0000 0000 0000 in binary),
	// set type (metrical or timecode)
	SharedData::setTimingType(
		(0x8000 & SharedData::getTiming()) == 0 ? "Metrical" : "Timecode");
}

//=============================================================================
void vMIDI::Data::track(int trackNumber)
{
	tracks->push_back(std::make_unique<MidiTrack>());
	auto& track {tracks->back()};

	// MTrk
	position += 4;

	// Length
	uint32_t trackLength = (*position << 24 | *(position + 1) << 16 |
		*(position + 2) << 8 | *(position + 3));
	position += 4;

	// Reset currentTime at the start of each track
	currentTime	= 0;

	/*************************************************************************
	| All tracks in a midi file start at 0,                                  |
	| even if the actual midi clips shown inside a track in a DAW doesn't    |
	|                                                                        |
	| The first delta time will just be from the start (0) to                |
	| however long it is until the first event of the track                  |
	| (that is not a meta event that should start at 0, like the track name) |
	| This could be many seconds, or even minutes                            |
	*************************************************************************/

	auto begin {position};
	auto end {position + trackLength};

	int ij {0};

	// Events
	while (position != end)
	{
		track->addEvent();
		auto event {tracks->back()->getFinalEvent()};

		// Delta time
		deltaTimeVector = getDeltaTimeOrLength();
		event->setDeltaTime(deltaTimeVector[0]);
		position += deltaTimeVector[1];

		currentTime += deltaTimeVector[0];

		//=============================================================================
		// Running status (only midi events, not sysex or meta)
		// If the status byte (this byte) is less than 0x80,
		// then it must be running status, which means
		// this event uses the same status byte as last event
		// and it's the same (specific) type of event as the last

		// If running status, set to previous (specific) event type
		if (*position < 0x80)
		{
			event->setRunningStatus(true);
			statusByte = prevStatusByte;
		}
			
		else
		{
			event->setRunningStatus(false);
			statusByte = *position;
			prevStatusByte = statusByte;
		}

		//=============================================================================
		bool isTempoEvent {
			((*position == 0xFF && *(position + 1) == 0x51 && *(position + 2) == 0x03)
			|| (statusByte == 0xFF && *position == 0x51 && *(position + 1) == 0x03))};

		// Only run the code below if there has been at least
		// one tempo event prior to this,
		// and this isn't a tempo event (FF 51 03)
		if (!TempoTrack::tempoChanges.empty() && !isTempoEvent)
		{
			setEventTime();
		}

		//=============================================================================
		// MIDI events

		if (statusByte >= 0x80 && statusByte <= 0x8F)		noteOff();
		else if (statusByte >= 0x90 && statusByte <= 0x9F)	noteOn();
		else if (statusByte >= 0xA0 && statusByte <= 0xAF)	polyphonicPressure();
		else if (statusByte >= 0xB0 && statusByte <= 0xBF)	controller();
		else if (statusByte >= 0xC0 && statusByte <= 0xCF)	programChange();
		else if (statusByte >= 0xD0 && statusByte <= 0xDF)	channelPressure();
		else if (statusByte >= 0xE0 && statusByte <= 0xEF)	pitchBend();

		//=============================================================================
		// SysEx events

		else if (statusByte == 0xF0)	singleSysex();
		else if (statusByte == 0xF7)	escapeSequence();

		//=============================================================================
		// Meta events

		else if (statusByte == 0xFF)
		{
			event->setType(Type::Meta);
			event->setTypeName("Meta");

			// FF
			position++;

			switch (*position)
			{
			case 0x0:	sequenceNumber();					break;
			case 0x1:	text();								break;
			case 0x2:	copyright();						break;
			case 0x3:	sequenceOrTrackName(trackNumber);	break;
			case 0x4:	instrumentName();					break;
			case 0x5:	lyric();							break;
			case 0x6:	marker();							break;
			case 0x7:	cuePoint();							break;
			case 0x8:	programName();						break;
			case 0x9:	deviceName();						break;
			case 0x20:	midiChannelPrefix();				break;
			case 0x21:	midiPort();							break;
			case 0x2F:	endOfTrack();						break;
			case 0x51:	tempo();							break;
			case 0x54:	smpteOffset();						break;
			case 0x58:	timeSignature();					break;
			case 0x59:	keySignature();						break;
			case 0x7F:	sequencerSpecificEvent();			break;
			
			default:
				throw std::runtime_error("Error: Not a Meta event!");
				break;
			}
		}

		else
			throw std::runtime_error("Error: Not an event!");

		ij++;
	}
}

//=============================================================================
/******************************************************************************
| Delta-time or length of various events (variable length, 1 to 4 bytes)      |
|                                                                             |
| The top bit of each byte (first from left) is set to 1 if the number        |
| continues on the next byte, or 0 If it's the last byte in the number        |
|                                                                             |
| The top bit is not part of the actual delta time value                      |
| Only the other (lower) 7 bits of each byte are                              |
|                                                                             |
| The largest value in 1 byte is therefore 127 and not 255                    |
| 128 needs another byte, which means the first byte                          |
| must have its top bit set                                                   |
|                                                                             |
| Let's pretend that a byte is only 7 bits (and not 8)...                     |
|                                                                             |
| 1 byte  (min) (1):                   000 0001                               |
| 1 byte  (max) (127/0x7F):            111 1111                               |
| 2 bytes (min) (128/0x80):            000 0001  000 0000                     |
| 2 bytes (max) (16 383/0x3FFF):       111 1111  111 1111                     |
| 3 bytes (min) (16 384/0x4000):       000 0001  000 0000  000 0000           |
| 3 bytes (max) (2 097 151/1F FFF):    111 1111  111 1111  111 1111           |
| 4 bytes (min) (2 097 152/20 000):    000 0001  000 0000  000 0000  000 0000 |
| 4 bytes (max) (268 435 455/FFF FFF): 111 1111  111 1111  111 1111  111 1111 |
|                                                                             |
| 128 = 81 00 (in midi "top bit + 7 bits" bytes)                              |
| 81 & 7F = 1     00 & 7F  = 0                                                |
| 1 << 7  = 80    00       = 0 (no bit shifting)                              |
|                                                                             |
| 80 | 0 = 80                                                                 |
| So, 81 00 is just 80 (or 128 in dec)                                        |
|                                                                             |
| 129 = 81 01                                                                 |
| 81 & 7F = 1     01 & 7F  = 1                                                |
| 1 << 7  = 80    01       = 0                                                |
|                                                                             |
| 80 | 1 = 81                                                                 |
| So, 81 01 is 81 (or 129 in dec)                                             |
******************************************************************************/

std::vector<uint32_t> vMIDI::Data::getDeltaTimeOrLength()
{
	// First value is the delta time or length
	// Second value is the number of bytes it uses
	std::vector<uint32_t> vector {0, 0};

	vector[1] = getVariableLengthQuantity();

	// Set the delta time depending on how many bytes it uses
	switch (vector[1])
	{
	case 1:
		vector[0] = *position;
		break;

	case 2:
		vector[0] = ((*(position) & 0x7F) << 7) | (*(position + 1) & 0x7F);
		break;

	case 3:
		vector[0] = ((*(position) & 0x7F) << 14) | ((*(position + 1) & 0x7F) << 7) |
			(*(position + 2) & 0x7F);
		break;

	case 4:
		vector[0] = ((*(position) & 0x7F) << 21) | ((*(position + 1) & 0x7F) << 14) |
			((*(position + 2) & 0x7F) << 7) | (*(position + 3) & 0x7F);
		break;
	}

	return vector;
}

int vMIDI::Data::getVariableLengthQuantity()
{
	int bytes {1};

	// 0x80 is 1000 0000 in binary
	for (int i {0}; (((0x80 & *(position + i)) != 0) && (bytes == i + 1)); ++i)
	{
		bytes++;
	}

	return bytes;
}

//=============================================================================
float vMIDI::Data::getTimePerPPQN(float tempoValue)
{
	// Time (microseconds) per PPQN (Pulses Per Quarter Note) =
	// Tempo value (microseconds per quarter note) /
	// PPQN (Pulses Per Quarter Note, or division)

	// Example at 120 BPM (tempo value of 500 000 microseconds)
	// and 96 PPQN:

	// 500 000 / 96 = 
	// 5208.333 microseconds =
	// 5.208333 milliseconds =
	// 0.005208333 seconds

	return tempoValue / SharedData::getTiming();
}

//=============================================================================
float vMIDI::Data::getTempoInBPM(float tempoValue)
{
	// Tempo is in microseconds per	quarter note
	// and we want to turn it into beats per minute

	// BPM (Beats Per Minute) = 60 000 000 / the 3 byte tempo value
	// Example: 60 000 000 / 500 000 = 120 BPM

	float tempoInBPM {60000000.f / tempoValue};

	// Round it (or you might get values like 119.9998)
	const float floor {std::floor(tempoInBPM)};
	const float ceiling {std::ceil(tempoInBPM)};

	if (tempoInBPM - floor < 0.01f)
		tempoInBPM = floor;

	else if (tempoInBPM - floor > 0.99f)
		tempoInBPM = ceiling;

	return tempoInBPM;
}

//=============================================================================
void vMIDI::Data::setEventTime()
{
	auto event {tracks->back()->getFinalEvent()};

	auto tempo {TempoTrack::getTempoAtTime(currentTime)};
	auto timePerPPQN {getTimePerPPQN(tempo)};

	event->setTimePerPPQN(timePerPPQN);
	event->setDeltaTimeInMs((deltaTimeVector[0] * timePerPPQN) / 1000);
	event->setDeltaTimeInS(event->getDeltaTimeInMs() / 1000);
	event->setTimestamp(currentTime);
	event->setTimestampInMs(TempoTrack::getTimeInMs(currentTime));
	event->setTimestampInS(event->getTimestampInMs() / 1000);
}

//=============================================================================
std::string vMIDI::Data::getNoteName()
{
	std::string noteName;

	for (int i {0}; i < noteNames.size(); ++i)
	{
		if (*position == i)
			noteName = noteNames[i];
	}

	return noteName;
}

//=============================================================================
// MIDI events

void vMIDI::Data::noteOff()
{
	/*******************
	| Note Off         |
	| 8n note velocity |
	*******************/

	auto event {tracks->back()->getFinalEvent()};

	event->setType(Type::MIDI);
	event->setTypeName("MIDI");
	event->setSpecificType(SpecificType::NoteOff);
	event->setSpecificTypeName("Note Off");

	event->setChannel(statusByte % 0x80);
	if (!event->getRunningStatus())
		position++;

	event->setNote(static_cast<Note>(*position));
	event->setNoteNumber(*position);
	event->setNoteName(getNoteName());
	position++;

	event->setVelocity(*position);
	position++;
}

void vMIDI::Data::noteOn()
{
	/*******************
	| Note On          |
	| 9n note velocity |
	*******************/

	auto event {tracks->back()->getFinalEvent()};

	event->setType(Type::MIDI);
	event->setTypeName("MIDI");
	event->setSpecificType(SpecificType::NoteOn);
	event->setSpecificTypeName("Note On");

	event->setChannel(statusByte % 0x90);
	if (!event->getRunningStatus())
		position++;

	event->setNote(static_cast<Note>(*position));
	event->setNoteNumber(*position);
	event->setNoteName(getNoteName());
	position++;

	event->setVelocity(*position);
	position++;
}

void vMIDI::Data::polyphonicPressure()
{
	/**********************
	| Polyphonic Pressure |
	| An note pressure    |
	**********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setType(Type::MIDI);
	event->setTypeName("MIDI");
	event->setSpecificType(SpecificType::PolyphonicPressure);
	event->setSpecificTypeName("Polyphonic Pressure");

	event->setChannel(statusByte % 0xA0);
	if (!event->getRunningStatus())
		position++;

	event->setNote(static_cast<Note>(*position));
	event->setNoteNumber(*position);
	event->setNoteName(getNoteName());
	position++;

	event->setPressure(*position);
	position++;
}

void vMIDI::Data::controller()
{
	/**********************
	| Controller          |
	| Bn controller value |
	**********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setType(Type::MIDI);
	event->setTypeName("MIDI");
	event->setSpecificType(SpecificType::Controller);
	event->setSpecificTypeName("Controller");

	event->setChannel(statusByte % 0xB0);
	if (!event->getRunningStatus())
		position++;

	std::string controller;

	switch (*position)
	{
	// Control Change messages
	case 0:
		controller = "Bank Select";
		break;
	case 1:
		controller = "Modulation Wheel";
		break;
	case 2:
		controller = "Breath Controller";
		break;
	case 4:
		controller = "Foot Controller";
		break;
	case 5:
		controller = "Portamento Time";
		break;
	case 6:
		controller = "Data Entry";
		break;
	case 7:
		controller = "Channel Volume";
		break;
	case 8:
		controller = "Balance";
		break;
	case 10:
		controller = "Pan";
		break;
	case 11:
		controller = "Expression Controller";
		break;
	case 12:
		controller = "Effect Control 1";
		break;
	case 13:
		controller = "Effect Control 2";
		break;
	case 16:
		controller = "General Purpose Controller 1";
		break;
	case 17:
		controller = "General Purpose Controller 2";
		break;
	case 18:
		controller = "General Purpose Controller 3";
		break;
	case 19:
		controller = "General Purpose Controller 4";
		break;

	// Control Change LSB messages
	case 32:
		controller = "Bank Select controller = LSB)";
		break;
	case 33:
		controller = "Modulation Wheel controller = LSB)";
		break;
	case 34:
		controller = "Breath Controller controller = LSB)";
		break;
	case 36:
		controller = "Foot Controller controller = LSB)";
		break;
	case 37:
		controller = "Portamento Time controller = LSB)";
		break;
	case 38:
		controller = "Data Entry controller = LSB)";
		break;
	case 40:
		controller = "Channel Volume controller = LSB)";
		break;
	case 42:
		controller = "Pan controller = LSB)";
		break;
	case 43:
		controller = "Expression Controller controller = LSB)";
		break;
	case 44:
		controller = "Effect Control 1 controller = LSB)";
		break;
	case 45:
		controller = "Effect Control 2 controller = LSB)";
		break;
	case 48:
		controller = "General Purpose Controller 1 controller = LSB)";
		break;
	case 49:
		controller = "General Purpose Controller 2 controller = LSB)";
		break;
	case 50:
		controller = "General Purpose Controller 3 controller = LSB)";
		break;
	case 51:
		controller = "General Purpose Controller 4 controller = LSB)";
		break;

	// Switches
	case 64:
		controller = "Sustain";
		break;
	case 65:
		controller = "Portamento";
		break;
	case 66:
		controller = "Sostenuto";
		break;
	case 67:
		controller = "Soft Pedal";
		break;
	case 68:
		controller = "Legato";
		break;
	case 69:
		controller = "Hold 2";
		break;

	// Extra controllers
	case 70:
		controller = "Sound Controller 1";		// Default: Sound Variation
		break;
	case 71:
		controller = "Sound Controller 2";		// Default: Timbre/Harmonic Content
		break;
	case 72:
		controller = "Sound Controller 3";		// Default: Release Time
		break;
	case 73:
		controller = "Sound Controller 4";		// Default: Attack Time
		break;
	case 74:
		controller = "Sound Controller 5";		// Default: Brightness
		break;
	case 75:
		controller = "Sound Controller 6";		// Default: Decay Time
		break;
	case 76:
		controller = "Sound Controller 7";		// Default: Vibrato Rate
		break;
	case 77:
		controller = "Sound Controller 8";		// Default: Vibrato Depth
		break;
	case 78:
		controller = "Sound Controller 9";		// Default: Vibrato Delay
		break;
	case 79:
		controller = "Sound Controller 10";		// Default: Undefined
		break;
	case 80:
		controller = "General Purpose Controller 5";
		break;
	case 81:
		controller = "General Purpose Controller 6";
		break;
	case 82:
		controller = "General Purpose Controller 7";
		break;
	case 83:
		controller = "General Purpose Controller 8";
		break;
	case 84:
		controller = "Portamento Control";
		break;
	case 88:
		controller = "High Resolution Velocity Prefix";
		break;
	case 91:
		controller = "Effects 1 Depth";		// Default: Reverb Send Level
		break;
	case 92:
		controller = "Effects 2 Depth";		// Tremolo Depth
		break;
	case 93:
		controller = "Effects 3 Depth";		// Default: Chorus Send Level
		break;
	case 94:
		controller = "Effects 4 Depth";		// Celeste Depth
		break;
	case 95:
		controller = "Effects 5 Depth";		// Phaser Depth
		break;

	// Other controllers
	case 96:
		controller = "Data Increment";
		break;
	case 97:
		controller = "Data Decrement";
		break;
	case 98:
		controller = "Non Registered Parameter Number controller = LSB)";
		break;
	case 99:
		controller = "Non Registered Parameter Number controller = MSB)";
		break;
	case 100:
		controller = "Registered Parameter Number controller = LSB)";
		break;
	case 101:
		controller = "Registered Parameter Number controller = MSB)";
		break;

	// Channel Mode messages
	case 120:
		controller = "All Sound Off";
		break;
	case 121:
		controller = "Reset All Controllers";
		break;
	case 122:
		controller = "Local Control";
		break;
	case 123:
		controller = "All Notes Off";
		break;
	case 124:
		controller = "Omni Mode Off";
		break;
	case 125:
		controller = "Omni Mode On";
		break;
	case 126:
		controller = "Mono Mode On";
		break;
	case 127:
		controller = "Poly Mode On";
		break;
	}

	event->setController(controller);
	position++;

	event->setControllerValue(*position);
	position++;
}

void vMIDI::Data::programChange()
{
	/*****************
	| Program Change |
	| Cn program     |
	*****************/

	auto event {tracks->back()->getFinalEvent()};

	event->setType(Type::MIDI);
	event->setTypeName("MIDI");
	event->setSpecificType(SpecificType::ProgramChange);
	event->setSpecificTypeName("Program Change");

	event->setChannel(statusByte % 0xC0);
	if (!event->getRunningStatus())
		position++;

	event->setProgram(*position);
	position++;
}

void vMIDI::Data::channelPressure()
{
	/*******************
	| Channel Pressure |
	| Dn pressure      |
	*******************/

	auto event {tracks->back()->getFinalEvent()};

	event->setType(Type::MIDI);
	event->setTypeName("MIDI");
	event->setSpecificType(SpecificType::ChannelPressure);
	event->setSpecificTypeName("Channel Pressure");

	event->setChannel(statusByte % 0xD0);
	if (!event->getRunningStatus())
		position++;

	event->setPressure(*position);
	position++;
}

void vMIDI::Data::pitchBend()
{
	/*************
	| Pitch Bend |
	| En lsb msb |
	*************/

	auto event {tracks->back()->getFinalEvent()};

	event->setType(Type::MIDI);
	event->setTypeName("MIDI");
	event->setSpecificType(SpecificType::PitchBend);
	event->setSpecificTypeName("Pitch Bend");

	event->setChannel(statusByte % 0xE0);
	if (!event->getRunningStatus())
		position++;

	// The two bytes (lsb and msb) should together form a 14 bit value

	// lsb bits 0 to 6 are the first 7 bits of the number
	// msb bits 0 to 6 are the remaining 7 bits of the number

	event->setPitchBend((*(position + 1) << 7 | *(position)));
}

//=============================================================================
// SysEx events

void vMIDI::Data::singleSysex()
{
	/********************
	| SysEx Single      |
	| F0 length message |
	********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setType(Type::SysEx);
	event->setTypeName("SysEx");
	event->setSpecificType(SpecificType::SingleSysEx);
	event->setSpecificTypeName("Single SysEx");
}

void vMIDI::Data::escapeSequence()
{
	/******************
	| Escape Sequence |
	| F7 length bytes |
	******************/

	auto event {tracks->back()->getFinalEvent()};

	event->setType(Type::SysEx);
	event->setTypeName("SysEx");
	event->setSpecificType(SpecificType::EscapeSequence);
	event->setSpecificTypeName("Escape Sequence");
}

//=============================================================================
// Meta events

// These all have the status byte FF
// position should be at the byte right after FF

void vMIDI::Data::sequenceNumber()
{
	/******************
	| Sequence Number |
	| FF 00 02 sn sn  |
	*******************/

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::SequenceNumber);
	event->setSpecificTypeName("Sequence Number");

	// 00 02
	position += 2;

	// "sn sn" (combined) is a 2 byte (16 bit) number
	event->setSequenceNumber((*position << 8 | *(position + 1)));
	position += 2;
}

void vMIDI::Data::text()
{
	/********************
	| Text              |
	| FF 01 length text |
	********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::Text);
	event->setSpecificTypeName("Text");

	// 01
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	std::string text {position, position + length[0]};
	position += length[0];

	event->setText(text);
}

void vMIDI::Data::copyright()
{
	/********************
	| Copyright         |
	| FF 02 length text |
	********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::Copyright);
	event->setSpecificTypeName("Copyright");

	// 02
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	std::string text {position, position + length[0]};
	position += length[0];

	event->setCopyright(text);
	SharedData::setCopyright(text);
}

void vMIDI::Data::sequenceOrTrackName(int trackNumber)
{
	/**********************
	| Sequence/Track Name |
	| FF 03 length text   |
	**********************/

	auto& track {tracks->back()};
	auto event {tracks->back()->getFinalEvent()};

	// 03
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	std::string text {position, position + length[0]};
	position += length[0];

	// Sequence name
	if (trackNumber == 0 &&
		(SharedData::getFormat() == 0 || SharedData::getFormat() == 1))
	{
		SharedData::setSequenceName(text);
	}

	// Track name
	// Always set this, even when it's technically the sequence name
	event->setSpecificType(SpecificType::TrackName);
	event->setSpecificTypeName("Track Name");

	event->setTrackName(text);
	track->setTrackName(text);
}

void vMIDI::Data::instrumentName()
{
	/********************
	| Instrument Name   |
	| FF 04 length text |
	********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::InstrumentName);
	event->setSpecificTypeName("Instrument Name");

	// 04
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	std::string text {position, position + length[0]};
	position += length[0];

	event->setInstrumentName(text);
}

void vMIDI::Data::lyric()
{
	/********************
	| Lyric             |
	| FF 05 length text |
	********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::Lyric);
	event->setSpecificTypeName("Lyric");

	// 05
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	std::string text {position, position + length[0]};
	position += length[0];

	event->setLyric(text);
}

void vMIDI::Data::marker()
{
	/********************
	| Marker            |
	| FF 06 length text |
	********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::Marker);
	event->setSpecificTypeName("Marker");

	// 06
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	std::string text {position, position + length[0]};
	position += length[0];

	event->setMarker(text);
}

void vMIDI::Data::cuePoint()
{
	/********************
	| Cue Point         |
	| FF 07 length text |
	********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::CuePoint);
	event->setSpecificTypeName("Cue Point");

	// 07
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	std::string text {position, position + length[0]};
	position += length[0];

	event->setCuePoint(text);
}

void vMIDI::Data::programName()
{
	/********************
	| Program Name      |
	| FF 07 length text |
	********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::ProgramChange);
	event->setSpecificTypeName("Program Name");

	// 08
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	std::string text {position, position + length[0]};
	position += length[0];

	event->setProgramName(text);
}

void vMIDI::Data::deviceName()
{
	/********************
	| Device Name       |
	| FF 08 length text |
	********************/

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::DeviceName);
	event->setSpecificTypeName("Device Name");

	// 09
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	std::string text {position, position + length[0]};
	position += length[0];

	event->setDeviceName(text);
}

void vMIDI::Data::midiChannelPrefix()
{
	/**********************
	| MIDI Channel Prefix |
	| FF 20 01 ch         |
	**********************/

	// ch is the midi channel (0-15)

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::MidiChannelPrefix);
	event->setSpecificTypeName("MIDI Channel Prefix");

	// 20 01
	position += 2;

	event->setMidiChannelPrefix(*position);
	position++;
}

void vMIDI::Data::midiPort()
{
	/**************
	| MIDI Port   |
	| FF 21 01 pt |
	**************/

	// pt is the port (0-127)

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::MidiPort);
	event->setSpecificTypeName("MIDI Port");

	// 21 01
	position += 2;

	event->setMidiPort(*position);
	position++;
}

void vMIDI::Data::endOfTrack()
{
	/***************
	| End of Track |
	| FF 2f 00     |
	****************/

	// Every track must end with this event

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::EndOfTrack);
	event->setSpecificTypeName("End of Track");

	// 2F 00
	position += 2;
}

void vMIDI::Data::tempo()
{
	/********************
	| Tempo             |
	| FF 51 03 te te te |
	********************/

	// "te te te" (combined) is a 24-bit value specifying the
	// tempo as the number of microseconds per quarter note

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::Tempo);
	event->setSpecificTypeName("Tempo");

	// 51, 03
	position += 2;

	// Timestamp in ms =
	// previousTimestampInMs +
	// (((timestamp - previousTimestamp) * timePerPPQN) / 1000)

	// End of previous tempo
	if (!TempoTrack::tempoChanges.empty())
	{
		// Set the final microsecond that uses the previous tempo
		// to the last microsecond (1 microsecond before the current time)

		auto& prevTempo {TempoTrack::tempoChanges.back()};
		auto prevEndTime {currentTime - 1};

		prevTempo->setEndTime(prevEndTime);
		prevTempo->setEndTimeMs(prevTempo->getStartTimeMs() +
			(((prevEndTime - prevTempo->getStartTime()) *
				prevTempo->getTimePerPPQN()) / 1000));
	}
	
	// Beginning of new tempo
	float tempo(static_cast<float>(*position << 16 |
		*(position + 1) << 8 | *(position + 2)));

	float tempoInBPM {getTempoInBPM(tempo)};
	auto timePerPPQN {getTimePerPPQN(tempo)};

	event->setTempo(tempo);
	event->setTimePerPPQN(timePerPPQN);
	event->setDeltaTimeInMs((deltaTimeVector[0] * timePerPPQN) / 1000);
	event->setDeltaTimeInS(event->getDeltaTimeInMs() / 1000);
	event->setTimestamp(currentTime);

	if (!TempoTrack::tempoChanges.empty())
	{
		auto& prevTempo {TempoTrack::tempoChanges.back()};

		event->setTimestampInMs((prevTempo->getEndTimeMs()) +
			(((currentTime - prevTempo->getEndTime()) * timePerPPQN) / 1000));
	}

	else
		event->setTimestampInMs((currentTime * timePerPPQN) / 1000);

	event->setTimestampInS(event->getTimestampInMs() / 1000);

	// Add the new tempo change
	TempoTrack::tempoChanges.push_back(std::make_unique<TempoChange>(
		tempo, tempoInBPM, timePerPPQN, currentTime, event->getTimestampInMs()));

	// 3 byte tempo value
	position += 3;
}

void vMIDI::Data::smpteOffset()
{
	/**************************
	| SMPTE Offset            |
	| FF 54 05 hr mn se fr ff |
	**************************/

	// hr = hour(s), encoded as "0frhhhhh" (fr = framerate, hhhhh = hour(0-23))
	// mn = minute(s)
	// se = second(s)
	// fr = frame(s) (0-23, 24, 28, 29)
	// ff = fractional frame(s), in 100ths of a frame

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::SMPTEOffset);
	event->setSpecificTypeName("SMPTE Offset");

	// 54 05
	position += 2;

	std::vector<uint32_t> smpteOffset;
	smpteOffset.push_back(0);
	smpteOffset.push_back(0);
	smpteOffset.push_back(0);
	smpteOffset.push_back(0);
	smpteOffset.push_back(0);

	// hr
	smpteOffset[0] = *position;
	position++;

	// mn
	smpteOffset[1] = *position;
	position++;

	// se
	smpteOffset[2] = *position;
	position++;

	// fr
	smpteOffset[3] = *position;
	position++;

	// ff
	smpteOffset[4] = *position;
	position++;

	event->setSMPTEOffset(smpteOffset);
}

void vMIDI::Data::timeSignature()
{
	/**************************
	| Time Signature          |
	| FF 58 04 nu de cl fr no |
	**************************/

	// nu = numerator
	// de = denominator
	// cl = number of midi clocks between metronome clicks
	// no = number of notated 32nd-notes in a midi quarter note (24 midi clocks)

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::TimeSignature);
	event->setSpecificTypeName("Time Signature");

	// 58, 04
	position += 2;

	std::vector<uint32_t> timeSignature;
	timeSignature.push_back(0);
	timeSignature.push_back(0);
	timeSignature.push_back(0);
	timeSignature.push_back(0);

	// Numerator
	timeSignature[0] = *position;
	position++;

	// Denominator
	// 0 = 1, 1 = 1/2, 2 = 1/4, 3 = 1/8, 4 = 1/16,
	// 5 = 1/32, 6 = 1/64, 7 = 1/128, 8 = 1/256
	switch (*position)
	{
	case 0:
		timeSignature[1] = 1;
		break;

	case 1:
		timeSignature[2] = 2;
		break;

	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		timeSignature[1] = static_cast<int>(std::pow(2, *position));
		break;

	default:
		timeSignature[1] = *position;
	}

	position++;

	// Number of midi clocks between metronome clicks
	timeSignature[2] = *position;
	position++;

	// Number of notated 32nd-notes in a
	// midi quarter-note (24 midi clocks), this is usually 8
	timeSignature[3] = *position;
	position++;

	event->setTimeSignature(timeSignature);
}

void vMIDI::Data::keySignature()
{
	/*****************
	| Key Signature  |
	| FF 59 02 sf mm |
	*****************/

	// sf = number of sharps of flats
	// mm = major(0) or minor(1) key

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::KeySignature);
	event->setSpecificTypeName("Key Signature");

	// 59, 02
	position += 2;

	std::string keySignature;

	// Number of flats (-) or sharps (+)
	// Example: -2 = 2 flats, 0 = key of C, 3 = 3 sharps
	// There are no actual negative values though
	// Instead count from 256 and backwards (256 = 0, 255 = -1, 254 = -2 etc)
	switch (*position)
	{
	case 0:
		keySignature = (*(position + 1) == 0 ? "C Major" : "A Minor");
		break;

	case 255:
		keySignature = (*(position + 1) == 0 ? "F Major" : "D Minor");
		break;

	case 254:
		keySignature = (*(position + 1) == 0 ? "Bb Major" : "G Minor");
		break;

	case 253:
		keySignature = (*(position + 1) == 0 ? "Eb Major" : "C Minor");
		break;

	case 252:
		keySignature = (*(position + 1) == 0 ? "Ab Major" : "F Minor");
		break;

	case 251:
		keySignature = (*(position + 1) == 0 ? "Db Major" : "Bb Minor");
		break;

	case 250:
		keySignature = (*(position + 1) == 0 ? "Gb Major" : "Eb Minor");
		break;

	case 249:
		keySignature = (*(position + 1) == 0 ? "Cb Major" : "G# Minor");
		break;

	case 1:
		keySignature = (*(position + 1) == 0 ? "G Major" : "E Minor");
		break;

	case 2:
		keySignature = (*(position + 1) == 0 ? "D Major" : "B Minor");
		break;

	case 3:
		keySignature = (*(position + 1) == 0 ? "A Major" : "F# Minor");
		break;

	case 4:
		keySignature = (*(position + 1) == 0 ? "E Major" : "C# Minor");
		break;

	case 5:
		keySignature = (*(position + 1) == 0 ? "B Major" : "G# Minor");
		break;

	case 6:
		keySignature = (*(position + 1) == 0 ? "F# Major" : "D# Minor");
		break;

	case 7:
		keySignature = (*(position + 1) == 0 ? "C# Major" : "Bb Minor");
		break;

	default:
		keySignature = "C Major";
		break;
	}

	event->setKeySignature(keySignature);
	position += 2;
}

void vMIDI::Data::sequencerSpecificEvent()
{
	/***************************
	| Sequencer Specific Event |
	| FF 7F length data        |
	***************************/

	// This event can be used to store some sequencer-specific data

	auto event {tracks->back()->getFinalEvent()};

	event->setSpecificType(SpecificType::SequencerSpecificEvent);
	event->setSpecificTypeName("Sequencer Specific Event");

	// 7F
	position++;

	auto length {getDeltaTimeOrLength()};
	position += length[1];

	event->setSequencerSpecificEvent(std::vector<uint32_t>(length[0]));
	position += length[0];
}