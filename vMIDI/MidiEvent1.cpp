#include "MidiEvent1.h"

//=============================================================================
vmidi::MidiEventData::MidiEventData()
{

}

vmidi::MidiEventData::~MidiEventData()
{

}

//=============================================================================
void vmidi::MidiEventData::addData(std::vector<uint8_t>& theData)
{
	data = theData;
}

std::vector<uint8_t>& vmidi::MidiEventData::getData()
{
	return data;
}

//=============================================================================
void vmidi::MidiEventData::setLength(std::vector<uint32_t>& eventLength)
{
	length = eventLength;
}

std::vector<uint32_t>& vmidi::MidiEventData::getLength()
{
	return length;
}

//=============================================================================
void vmidi::MidiEventData::setFormat(uint16_t midiFormat)
{
	format = midiFormat;
}

uint16_t vmidi::MidiEventData::getFormat()
{
	return format;
}

void vmidi::MidiEventData::setDivision(uint16_t midiDivision)
{
	division = midiDivision;
}

uint16_t vmidi::MidiEventData::getDivision()
{
	return division;
}

void vmidi::MidiEventData::setTiming(std::string midiTiming)
{
	timing = midiTiming;
}

std::string vmidi::MidiEventData::getTiming()
{
	return timing;
}

void vmidi::MidiEventData::setTrackNumber(int trackN)
{
	trackNumber = trackN;
}

int vmidi::MidiEventData::getTrackNumber()
{
	return trackNumber;
}

//=============================================================================
void vmidi::MidiEventData::setDeltaTime(std::vector<uint32_t> eventDeltaTime)
{
	deltaTime = eventDeltaTime;
}

std::vector<uint32_t> vmidi::MidiEventData::getDeltaTime()
{
	return deltaTime;
}

void vmidi::MidiEventData::setType(std::string eventType)
{
	type = eventType;
}

std::string vmidi::MidiEventData::getType()
{
	return type;
}

void vmidi::MidiEventData::setSpecificType(std::string specificEventType)
{
	specificType = specificEventType;
}

std::string vmidi::MidiEventData::getSpecificType()
{
	return specificType;
}

//=============================================================================
void vmidi::MidiEventData::setCurrentTempo(float currTempo)
{
	currentTempo = currTempo;
}

float vmidi::MidiEventData::getCurrentTempo()
{
	return currentTempo;
}

void vmidi::MidiEventData::setCurrentTime(float currTime)
{
	SharedData::addToCurrentTime(currTime);
	currentTime = SharedData::getCurrentTime();
}

float vmidi::MidiEventData::getCurrentTime()
{
	return currentTime;
}

//=============================================================================
int vmidi::MidiEventData::getChannel()
{
		return channel;
}

int vmidi::MidiEventData::getNoteNumber()
{
		return noteNumber;
}

std::string vmidi::MidiEventData::getNoteName()
{
	return noteName;
}

int vmidi::MidiEventData::getVelocity()
{
		return velocity;
}

int vmidi::MidiEventData::getPressure()
{
	if (!pressure)
		throw std::runtime_error("Error: No pressure!");

	else
		return *pressure;
}

std::string vmidi::MidiEventData::getController()
{
	if (!controller)
		throw std::runtime_error("Error: No controller!");

	else
		return *controller;
}

int vmidi::MidiEventData::getControllerValue()
{
	if (!controllerValue)
		throw std::runtime_error("Error: No controller value!");

	else
		return *controllerValue;
}

int vmidi::MidiEventData::getProgram()
{
	if (!program)
		throw std::runtime_error("Error: No program!");

	else
		return *program;
}

int vmidi::MidiEventData::getPitchBend()
{
	if (!pitchBend)
		throw std::runtime_error("Error: No pitch bend!");

	else
		return *pitchBend;
}

int vmidi::MidiEventData::getSequenceNumber()
{
	if (!sequenceNumber)
		throw std::runtime_error("Error: No sequence number!");

	else
		return *sequenceNumber;
}

std::string vmidi::MidiEventData::getText()
{
	if (!text)
		throw std::runtime_error("Error: No text!");

	else
		return *text;
}

std::string vmidi::MidiEventData::getCopyright()
{
	if (!copyright)
		throw std::runtime_error("Error: No copyright!");

	else
		return *copyright;
}

std::string vmidi::MidiEventData::getTrackName()
{
	if (!trackName)
		throw std::runtime_error("Error: No track name!");

	else
		return *trackName;
}

std::string vmidi::MidiEventData::getInstrumentName()
{
	if (!instrumentName)
		throw std::runtime_error("Error: No instrument name!");

	else
		return *instrumentName;
}

std::string vmidi::MidiEventData::getDeviceName()
{
	if (!deviceName)
		throw std::runtime_error("Error: No device name!");

	else
		return *deviceName;
}

int vmidi::MidiEventData::getEndOfTrack()
{
	if (!endOfTrack)
		throw std::runtime_error("Error: Not end of track!");

	else
		return *endOfTrack;
}

int vmidi::MidiEventData::getSMPTEOffset()
{
	if (!smpteOffset)
		throw std::runtime_error("Error: No SMPTE offset!");

	else
		return *smpteOffset;
}

std::string vmidi::MidiEventData::getLyric()
{
	if (!lyric)
		throw std::runtime_error("Error: No lyric!");

	else
		return *lyric;
}

int vmidi::MidiEventData::getMarker()
{
	if (!marker)
		throw std::runtime_error("Error: No marker!");

	else
		return *marker;
}

int vmidi::MidiEventData::getCuePoint()
{
	if (!cuePoint)
		throw std::runtime_error("Error: No cue point!");

	else
		return *cuePoint;
}

std::string vmidi::MidiEventData::getProgramName()
{
	if (!programName)
		throw std::runtime_error("Error: No program name!");

	else
		return *programName;
}

int vmidi::MidiEventData::getMidiChannelPrefix()
{
	if (!midiChannelPrefix)
		throw std::runtime_error("Error: No midi channel prefix!");

	else
		return *midiChannelPrefix;
}

int vmidi::MidiEventData::getMidiPort()
{
	if (!midiPort)
		throw std::runtime_error("Error: No midi port!");

	else
		return *midiPort;
}

int vmidi::MidiEventData::getTempo()
{
	if (!tempo)
		throw std::runtime_error("Error: No tempo!");

	else
		return *tempo;
}

std::vector<uint32_t> vmidi::MidiEventData::getTimeSignature()
{
	if (!timeSignature)
		throw std::runtime_error("Error: No time signature!");

	else
		return *timeSignature;
}

std::string vmidi::MidiEventData::getKeySignature()
{
	if (!keySignature)
		throw std::runtime_error("Error: No key signature!");

	else
		return *keySignature;
}

int vmidi::MidiEventData::getSequencerSpecificEvent()
{
	if (!sequencerSpecificEvent)
		throw std::runtime_error("Error: No sequencer specific event!");

	else
		return *sequencerSpecificEvent;
}

//=============================================================================
void vmidi::MidiEventData::getChannelFromData(
	std::vector<uint8_t>::iterator position)
{
	if (specificType == "Note Off")
		channel = *position % 0x80;

	else if (specificType == "Note On")
		channel = *position % 0x90;

	else if (specificType == "Polyphonic Pressure")
		channel = *position % 0xA0;

	else if (specificType == "Controller")
		channel = *position % 0xB0;

	else if (specificType == "Program Change")
		channel = *position % 0xC0;

	else if (specificType == "Channel Pressure")
		channel = *position % 0xD0;

	else if (specificType == "Pitch Bend")
		channel = *position % 0xE0;
}

void vmidi::MidiEventData::getChannelFromData(uint8_t runningStatusByte)
{
	if (specificType == "Note Off")
		channel = runningStatusByte % 0x80;

	else if (specificType == "Note On")
		channel = runningStatusByte % 0x90;

	else if (specificType == "Polyphonic Pressure")
		channel = runningStatusByte % 0xA0;

	else if (specificType == "Controller")
		channel = runningStatusByte % 0xB0;

	else if (specificType == "Program Change")
		channel = runningStatusByte % 0xC0;

	else if (specificType == "Channel Pressure")
		channel = runningStatusByte % 0xD0;

	else if (specificType == "Pitch Bend")
		channel = runningStatusByte % 0xE0;
}

void vmidi::MidiEventData::getNoteFromData(
	std::vector<uint8_t>::iterator position)
{
	if ((specificType == "Note Off") || (specificType == "Note On") ||
		(specificType == "Polyphonic Pressure"))
	{
		// Notes are numbered from 0 (0x00) to 127 (0x7F)

		noteNumber = *position;

		const std::array<std::string, 128> notes
		{
			"C-2", "C#/Db-2", "D-2", "D#/Eb-2", "E-2", "F-2",
			"F#/Gb-2", "G-2", "G#/Ab-2", "A-2", "A#/Bb-2", "B-2",

			"C-1", "C#/Db-1", "D-1", "D#/Eb-1", "E-1", "F-1",
			"F#/Gb-1", "G-1", "G#/Ab-1", "A-1", "A#/Bb-1", "B-1",

			"C0", "C#/Db0", "D0", "D#/Eb0", "E0", "F0",
			"F#/Gb0", "G0", "G#/Ab0", "A0", "A#/Bb0", "B0",

			"C1", "C#/Db1", "D1", "D#/Eb1", "E1", "F1",
			"F#/Gb1", "G1", "G#/Ab1", "A1", "A#/Bb1", "B1",

			"C2", "C#/Db2", "D2", "D#/Eb2", "E2", "F2",
			"F#/Gb2", "G2", "G#/Ab2", "A2", "A#/Bb2", "B2",

			"C3", "C#/Db3", "D3", "D#/Eb3", "E3", "F3",
			"F#/Gb3", "G3", "G#/Ab3", "A3", "A#/Bb3", "B3",

			"C4", "C#/Db4", "D4", "D#/Eb4", "E4", "F4",
			"F#/Gb4", "G4", "G#/Ab4", "A4", "A#/Bb4", "B4",

			"C5", "C#/Db5", "D5", "D#/Eb5", "E5", "F5",
			"F#/Gb5", "G5", "G#/Ab5", "A5", "A#/Bb5", "B5",

			"C6", "C#/Db6", "D6", "D#/Eb6", "E6", "F6",
			"F#/Gb6", "G6", "G#/Ab6", "A6", "A#/Bb6", "B6",

			"C7", "C#/Db7", "D7", "D#/Eb7", "E7", "F7",
			"F#/Gb7", "G7", "G#/Ab7", "A7", "A#/Bb7", "B7",

			"C8", "C#/Db8", "D8", "D#/Eb8", "E8", "F8",
			"F#/Gb8", "G8"
		};

		for (int i {0}; i < notes.size(); ++i)
		{
			if (*position == i)
			{
				noteName = notes[i];
			}
		}
	}
}

void vmidi::MidiEventData::getVelocityFromData(
	std::vector<uint8_t>::iterator position)
{
	velocity = *position;
}

void vmidi::MidiEventData::getPressureFromData(
	std::vector<uint8_t>::iterator position)
{
	pressure = std::make_unique<int>();

	*pressure = *position;
}

void vmidi::MidiEventData::getControllerFromData(
	std::vector<uint8_t>::iterator position)
{
	controller = std::make_unique<std::string>();

	switch (*position)
	{
		// Control Change messages
	case 0:
		*controller = "Bank Select";
		break;
	case 1:
		*controller = "Modulation Wheel";
		break;
	case 2:
		*controller = "Breath Controller";
		break;
	case 4:
		*controller = "Foot Controller";
		break;
	case 5:
		*controller = "Portamento Time";
		break;
	case 6:
		*controller = "Data Entry";
		break;
	case 7:
		*controller = "Channel Volume";
		break;
	case 8:
		*controller = "Balance";
		break;
	case 10:
		*controller = "Pan";
		break;
	case 11:
		*controller = "Expression Controller";
		break;
	case 12:
		*controller = "Effect Control 1";
		break;
	case 13:
		*controller = "Effect Control 2";
		break;
	case 16:
		*controller = "General Purpose Controller 1";
		break;
	case 17:
		*controller = "General Purpose Controller 2";
		break;
	case 18:
		*controller = "General Purpose Controller 3";
		break;
	case 19:
		*controller = "General Purpose Controller 4";
		break;

		// Control Change LSB messages
	case 32:
		*controller = "Bank Select (LSB)";
		break;
	case 33:
		*controller = "Modulation Wheel (LSB)";
		break;
	case 34:
		*controller = "Breath Controller (LSB)";
		break;
	case 36:
		*controller = "Foot Controller (LSB)";
		break;
	case 37:
		*controller = "Portamento Time (LSB)";
		break;
	case 38:
		*controller = "Data Entry (LSB)";
		break;
	case 40:
		*controller = "Channel Volume (LSB)";
		break;
	case 42:
		*controller = "Pan (LSB)";
		break;
	case 43:
		*controller = "Expression Controller (LSB)";
		break;
	case 44:
		*controller = "Effect Control 1 (LSB)";
		break;
	case 45:
		*controller = "Effect Control 2 (LSB)";
		break;
	case 48:
		*controller = "General Purpose Controller 1 (LSB)";
		break;
	case 49:
		*controller = "General Purpose Controller 2 (LSB)";
		break;
	case 50:
		*controller = "General Purpose Controller 3 (LSB)";
		break;
	case 51:
		*controller = "General Purpose Controller 4 (LSB)";
		break;

		// Switches
	case 64:
		*controller = "Sustain";
		break;
	case 65:
		*controller = "Portamento";
		break;
	case 66:
		*controller = "Sostenuto";
		break;
	case 67:
		*controller = "Soft Pedal";
		break;
	case 68:
		*controller = "Legato";
		break;
	case 69:
		*controller = "Hold 2";
		break;

		// Extra controllers
	case 70:
		*controller = "Sound Controller 1";		// Default: Sound Variation
		break;
	case 71:
		*controller = "Sound Controller 2";		// Default: Timbre/Harmonic Content
		break;
	case 72:
		*controller = "Sound Controller 3";		// Default: Release Time
		break;
	case 73:
		*controller = "Sound Controller 4";		// Default: Attack Time
		break;
	case 74:
		*controller = "Sound Controller 5";		// Default: Brightness
		break;
	case 75:
		*controller = "Sound Controller 6";		// Default: Decay Time
		break;
	case 76:
		*controller = "Sound Controller 7";		// Default: Vibrato Rate
		break;
	case 77:
		*controller = "Sound Controller 8";		// Default: Vibrato Depth
		break;
	case 78:
		*controller = "Sound Controller 9";		// Default: Vibrato Delay
		break;
	case 79:
		*controller = "Sound Controller 10";	// Default: Undefined
		break;
	case 80:
		*controller = "General Purpose Controller 5";
		break;
	case 81:
		*controller = "General Purpose Controller 6";
		break;
	case 82:
		*controller = "General Purpose Controller 7";
		break;
	case 83:
		*controller = "General Purpose Controller 8";
		break;
	case 84:
		*controller = "Portamento Control";
		break;
	case 88:
		*controller = "High Resolution Velocity Prefix";
		break;
	case 91:
		*controller = "Effects 1 Depth";		// Default: Reverb Send Level
		break;
	case 92:
		*controller = "Effects 2 Depth";		// Tremolo Depth
		break;
	case 93:
		*controller = "Effects 3 Depth";		// Default: Chorus Send Level
		break;
	case 94:
		*controller = "Effects 4 Depth";		// Celeste Depth
		break;
	case 95:
		*controller = "Effects 5 Depth";		// Phaser Depth
		break;

		// Other controllers
	case 96:
		*controller = "Data Increment";
		break;
	case 97:
		*controller = "Data Decrement";
		break;
	case 98:
		*controller = "Non Registered Parameter Number (LSB)";
		break;
	case 99:
		*controller = "Non Registered Parameter Number (MSB)";
		break;
	case 100:
		*controller = "Registered Parameter Number (LSB)";
		break;
	case 101:
		*controller = "Registered Parameter Number (MSB)";
		break;

		// Channel Mode messages
	case 120:
		*controller = "All Sound Off";
		break;
	case 121:
		*controller = "Reset All Controllers";
		break;
	case 122:
		*controller = "Local Control";
		break;
	case 123:
		*controller = "All Notes Off";
		break;
	case 124:
		*controller = "Omni Mode Off";
		break;
	case 125:
		*controller = "Omni Mode On";
		break;
	case 126:
		*controller = "Mono Mode On";
		break;
	case 127:
		*controller = "Poly Mode On";
		break;
	}
}

void vmidi::MidiEventData::getControllerValueFromData(
	std::vector<uint8_t>::iterator position)
{
	controllerValue = std::make_unique<int>();

	*controllerValue = *position;
}

void vmidi::MidiEventData::getProgramFromData(
	std::vector<uint8_t>::iterator position)
{
	program = std::make_unique<int>();

	*program = *position;
}

void vmidi::MidiEventData::getPitchBendFromData(
	std::vector<uint8_t>::iterator position)
{
	pitchBend = std::make_unique<int>();

	/*************
	| Pitch Bend |
	| En lsb msb |
	*************/

	// The two bytes (lsb and msb) should together form a 14 bit value

	// lsb bits 0 to 6 are the first 7 bits of the number
	// msb bits 0 to 6 are the remaining 7 bits of the number

	*pitchBend = (*(position + 1) << 7 | *(position));
}


void vmidi::MidiEventData::getSequenceNumberFromData(
	std::vector<uint8_t>::iterator position)
{
	sequenceNumber = std::make_unique<int>();

	/******************
	| Sequence Number |
	| FF 00 02 ss ss  |
	*******************/

	// ss ss (combined) should be a 16 bit number
	*sequenceNumber = (*(position + 3) << 8 | *(position + 4));
}

void vmidi::MidiEventData::getTextFromData(
	std::vector<uint8_t>::iterator position)
{
	text = std::make_unique<std::string>();

	/********************
	| Text              |
	| FF 01 length text |
	********************/

	position += 1 + length[2] + 1;

	for (auto i {position}; i < data.end(); ++i)
	{
		*text += *i;
	}
}

void vmidi::MidiEventData::getCopyrightFromData(
	std::vector<uint8_t>::iterator position)
{
	copyright = std::make_unique<std::string>();

	/********************
	| Copyright         |
	| FF 02 length text |
	********************/

	position += 1 + length[2] + 1;

	for (auto i {position}; i < data.end(); ++i)
	{
		*copyright += *i;
	}
}

void vmidi::MidiEventData::getTrackNameFromData(
	std::vector<uint8_t>::iterator position)
{
	trackName = std::make_unique<std::string>();

	/********************
	| Track Name        |
	| FF 03 length text |
	********************/

	position += 1 + length[2] + 1;

	for (auto i {position}; i < data.end(); ++i)
	{
		*trackName += *i;
	}
}

void vmidi::MidiEventData::getInstrumentNameFromData(
	std::vector<uint8_t>::iterator position)
{
	instrumentName = std::make_unique<std::string>();

	/********************
	| Instrument Name   |
	| FF 04 length text |
	********************/

	position += 1 + length[2] + 1;

	for (auto i {position}; i < data.end(); ++i)
	{
		*instrumentName += *i;
	}
}

void vmidi::MidiEventData::getDeviceNameFromData(
	std::vector<uint8_t>::iterator position)
{
	deviceName = std::make_unique<std::string>();
}

void vmidi::MidiEventData::getEndOfTrackFromData(
	std::vector<uint8_t>::iterator position)
{
	endOfTrack = std::make_unique<int>();
}

void vmidi::MidiEventData::getSMPTEOffsetFromData(
	std::vector<uint8_t>::iterator position)
{
	smpteOffset = std::make_unique<int>();
}


void vmidi::MidiEventData::getLyricFromData(
	std::vector<uint8_t>::iterator position)
{
	lyric = std::make_unique<std::string>();

	/********************
	| Lyric             |
	| FF 04 length text |
	********************/

	position += 1 + length[2] + 1;

	for (auto i {position}; i < data.end(); ++i)
	{
		*lyric += *i;
	}
}

void vmidi::MidiEventData::getMarkerFromData(
	std::vector<uint8_t>::iterator position)
{
	marker = std::make_unique<int>();

	/********************
	| Marker            |
	| FF 06 length text |
	********************/

	position += 1 + length[2] + 1;

	for (auto i {position}; i < data.end(); ++i)
	{
		*marker += *i;
	}
}

void vmidi::MidiEventData::getCuePointFromData(
	std::vector<uint8_t>::iterator position)
{
	cuePoint = std::make_unique<int>();

	/********************
	| Cue Point         |
	| FF 07 length text |
	********************/

	position += 1 + length[2] + 1;

	for (auto i {position}; i < data.end(); ++i)
	{
		*cuePoint += *i;
	}
}

void vmidi::MidiEventData::getProgramNameFromData(
	std::vector<uint8_t>::iterator position)
{
	programName = std::make_unique<std::string>();

	/********************
	| Program Name      |
	| FF 07 length text |
	********************/

	position += 1 + length[2] + 1;

	for (auto i {position}; i < data.end(); ++i)
	{
		*programName += *i;
	}
}

void vmidi::MidiEventData::getMidiChannelPrefixFromData(
	std::vector<uint8_t>::iterator position)
{
	midiChannelPrefix = std::make_unique<int>();

	*midiChannelPrefix = *(position + 3);
}

void vmidi::MidiEventData::getMidiPortFromData(
	std::vector<uint8_t>::iterator position)
{
	midiPort = std::make_unique<int>();

	*midiPort = *(position + 3);
}

void vmidi::MidiEventData::getTempoFromData(
	std::vector<uint8_t>::iterator position)
{
	tempo = std::make_unique<int>();

	// The tempo is how many milliseconds each quarter note should be
	
	// Example: a value of 500 000 (microseconds) means a quarter note should be
	// 0,5 seconds, so a whole 4/4 bar would last for 2 seconds

	*tempo = (*(position + 3) << 16 | *(position + 4) << 8 | *(position + 5));
}

void vmidi::MidiEventData::getTimeSignatureFromData(
	std::vector<uint8_t>::iterator position)
{
	timeSignature = std::make_unique<std::vector<uint32_t>>();
	timeSignature->push_back(0);
	timeSignature->push_back(0);
	timeSignature->push_back(0);
	timeSignature->push_back(0);

	// Numerator
	timeSignature->at(0) = *(position + 3);

	// Denominator
	// 0 = 1, 1 = 1/2, 2 = 1/4, 3 = 1/8, 4 = 1/16,
	// 5 = 1/32, 6 = 1/64, 7 = 1/128, 8 = 1/256
	switch (*(position + 4))
	{
	case 0:
		timeSignature->at(1) = 1;
		break;

	case 1:
		timeSignature->at(2) = 2;
		break;

	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		timeSignature->at(1) = static_cast<int>(std::pow(2, *(position + 4)));
		break;

	default:
		timeSignature->at(1) = *(position + 4);
	}

	// Number of midi clocks between metronome clicks
	timeSignature->at(2) = *(position + 5);

	// Number of notated 32nd-notes in a
	// midi quarter-note (24 midi clocks), this is usually 8
	timeSignature->at(3) = *(position + 6);
}

void vmidi::MidiEventData::getKeySignatureFromData(
	std::vector<uint8_t>::iterator position)
{
	keySignature = std::make_unique<std::string>();

	// Number of flats (-) or sharps (+)
	// Example: -2 = 2 flats, 0 = key of C, 3 = 3 sharps
	// There are no actual negative values though
	// Instead count from 256 and backwards (256 = 0, 255 = -1, 254 = -2 etc)
	switch (*(position + 3))
	{
	case 0:
		*keySignature = (*(position + 4) == 0 ? "C Major" : "A Minor");
		break;
	
	case 255:
		*keySignature = (*(position + 4) == 0 ? "F Major" : "D Minor");
		break;
	
	case 254:
		*keySignature = (*(position + 4) == 0 ? "Bb Major" : "G Minor");
		break;
	
	case 253:
		*keySignature = (*(position + 4) == 0 ? "Eb Major" : "C Minor");
		break;
	
	case 252:
		*keySignature = (*(position + 4) == 0 ? "Ab Major" : "F Minor");
		break;
	
	case 251:
		*keySignature = (*(position + 4) == 0 ? "Db Major" : "Bb Minor");
		break;
	
	case 250:
		*keySignature = (*(position + 4) == 0 ? "Gb Major" : "Eb Minor");
		break;
	
	case 249:
		*keySignature = (*(position + 4) == 0 ? "Cb Major" : "G# Minor");
		break;

	case 1:
		*keySignature = (*(position + 4) == 0 ? "G Major" : "E Minor");
		break;

	case 2:
		*keySignature = (*(position + 4) == 0 ? "D Major" : "B Minor");
		break;

	case 3:
		*keySignature = (*(position + 4) == 0 ? "A Major" : "F# Minor");
		break;

	case 4:
		*keySignature = (*(position + 4) == 0 ? "E Major" : "C# Minor");
		break;

	case 5:
		*keySignature = (*(position + 4) == 0 ? "B Major" : "G# Minor");
		break;

	case 6:
		*keySignature = (*(position + 4) == 0 ? "F# Major" : "D# Minor");
		break;

	case 7:
		*keySignature = (*(position + 4) == 0 ? "C# Major" : "Bb Minor");
		break;

	default:
		*keySignature = "C Major";
		break;
	}
}

void vmidi::MidiEventData::getSequencerSpecificEventFromData(
	std::vector<uint8_t>::iterator position)
{
	sequencerSpecificEvent = std::make_unique<int>();
}


//=============================================================================
vmidi::MidiEvent::MidiEvent(std::vector<uint8_t>& eventData,
	std::vector<uint32_t>& eventLength, std::vector<uint32_t>& eventDeltaTime,
	std::string& eventType, std::string& specificEventType)
{
	// Add the track data
	data.addData(eventData);

	// Set some variables
	data.setLength(eventLength);
	data.setFormat(SharedData::getFormat());
	data.setDivision(SharedData::getDivision());
	data.setTiming(SharedData::getTiming());
	data.setTrackNumber(SharedData::getTrackNumber());
	data.setDeltaTime(eventDeltaTime);
	data.setType(eventType);
	data.setSpecificType(specificEventType);
	data.setCurrentTempo(SharedData::getCurrentTempo());
	data.setCurrentTime(static_cast<float>(data.getDeltaTime()[0]));

	

	// Go through the event data
	goThroughData();

	if (data.getCurrentTempo() != 0)
	{
		calculateTimePerPPQN();
		calculateTempoInBPM(currentTempoInBPM);

		if (data.getSpecificType() == "Tempo" && data.getTempo() != 0)
		{
			calculateTempoInBPM(tempo);
		}

		if (data.getDeltaTime()[0] != 0)
		{
			calculateDeltaTimeInMs();
			calculateDeltaTimeInS();
		}

		if (SharedData::getCurrentTime() > 0)
		{
			calculateTimestampInMs();
			calculateTimestampInS();
		}
	}
}

vmidi::MidiEvent::~MidiEvent()
{

}

//=============================================================================
void vmidi::MidiEvent::goThroughData()
{
	std::vector<uint8_t>::iterator position {data.getData().begin()};

	// Time
	position += data.getDeltaTime()[1];

	// Event data
	if (data.getType() == "Midi")
	{
		data.getChannelFromData(position);

		if (data.getSpecificType() == "Note Off" ||
			data.getSpecificType() == "Note On")
		{
			data.getNoteFromData(position + 1);
			data.getVelocityFromData(position + 2);
		}

		else if (data.getSpecificType() == "Polyphonic Pressure")
		{
			data.getNoteFromData(position + 1);
			data.getPressureFromData(position + 2);
		}

		else if (data.getSpecificType() == "Controller")
		{
			data.getControllerFromData(position + 1);
			data.getControllerValueFromData(position + 2);
		}

		else if (data.getSpecificType() == "Program Change")
			data.getProgramFromData(position + 1);

		else if (data.getSpecificType() == "Channel Pressure")
			data.getPressureFromData(position + 1);

		else if (data.getSpecificType() == "Pitch Bend")
			data.getPitchBendFromData(position + 1);
	}

	else if (data.getType() == "Midi (running status)")
	{
		data.getChannelFromData(SharedData::getRunningStatus());

		if (data.getSpecificType() == "Note Off" ||
			data.getSpecificType() == "Note On")
		{
			data.getNoteFromData(position);
			data.getVelocityFromData(position + 1);
		}

		else if (data.getSpecificType() == "Polyphonic Pressure")
		{
			data.getNoteFromData(position);
			data.getPressureFromData(position + 1);
		}

		else if (data.getSpecificType() == "Controller")
		{
			data.getControllerFromData(position);
			data.getControllerValueFromData(position + 1);
		}

		else if (data.getSpecificType() == "Program Change")
			data.getProgramFromData(position);

		else if (data.getSpecificType() == "Channel Pressure")
			data.getPressureFromData(position);

		else if (data.getSpecificType() == "Pitch Bend")
			data.getPitchBendFromData(position);
	}

	else if (data.getType() == "SysEx")
	{
		/*
		if (data.getSpecificType() == "SysExSingle)
			SysExSingle

		else if (data.getSpecificType() == "SysExEscape)
			SysExEscape
		*/
	}

	else if (data.getType() == "Meta")
	{
		if (data.getSpecificType() == "Sequence Number")
			data.getSequenceNumberFromData(position);

		else if (data.getSpecificType() == "Text")
			data.getTextFromData(position);

		else if (data.getSpecificType() == "Copyright")
			data.getCopyrightFromData(position);

		else if (data.getSpecificType() == "Track Name")
			data.getTrackNameFromData(position);

		else if (data.getSpecificType() == "Instrument Name")
			data.getInstrumentNameFromData(position);

		else if (data.getSpecificType() == "Lyric")
			data.getLyricFromData(position);

		else if (data.getSpecificType() == "Marker")
			data.getMarkerFromData(position);

		else if (data.getSpecificType() == "Cue Point")
			data.getCuePointFromData(position);

		else if (data.getSpecificType() == "Program Name")
			data.getProgramNameFromData(position);

		else if (data.getSpecificType() == "Device Name")
			data.getDeviceNameFromData(position);

		else if (data.getSpecificType() == "MIDI Channel Prefix")
			data.getMidiChannelPrefixFromData(position);

		else if (data.getSpecificType() == "MIDI Port")
			data.getMidiPortFromData(position);

		else if (data.getSpecificType() == "End of Track")
		{
			data.getEndOfTrackFromData(position);

			// When we reach the end of a track
			// we reset the time
			SharedData::setCurrentTime(0);

			/*************************************************************************
			| All tracks in a midi file start at 0,                                  |
			| even if the actual midi clips shown inside a track in a DAW doesn't    |
			|                                                                        |
			| The first delta time will just be from the start (0) to                |
			| however long it is until the first event of the track                  |
			| (that is not a meta event that should start at 0, like the track name) |
			| This could be many seconds, or even minutes                            |
			*************************************************************************/
		}

		else if (data.getSpecificType() == "Tempo")
		{
			data.getTempoFromData(position);
		}

		else if (data.getSpecificType() == "SMPTE Offset")
			data.getSMPTEOffsetFromData(position);

		else if (data.getSpecificType() == "Time Signature")
			data.getTimeSignatureFromData(position);

		else if (data.getSpecificType() == "Key Signature")
			data.getKeySignatureFromData(position);

		else if (data.getSpecificType() == "Sequencer Specific Event")
			data.getSequencerSpecificEventFromData(position);
	}

	else
	{
		throw std::runtime_error("Error: Not an event!");
	}
}

//=============================================================================
void vmidi::MidiEvent::calculateTempoInBPM(float& tempoValue)
{
	// Tempo is in microseconds per	quarter note
	// and we want to turn it into beats per minute

	// BPM (Beats Per Minute) = 60 000 000 / the 3 byte tempo value
	// Example: 60 000 000 / 500 000 = 120 BPM

	tempoValue = 60000000.f / data.getCurrentTempo();

	// Round it (or you might get values like 119.9998)
	const float floor		{std::floor(tempoValue)};
	const float ceiling	{std::ceil(tempoValue)};

	if (tempoValue - floor < 0.01)
		tempoValue = floor;

	else if (tempoValue - floor > 0.99)
		tempoValue = ceiling;
}

void vmidi::MidiEvent::calculateTimePerPPQN()
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

	timePerPPQN = data.getCurrentTempo() / data.getDivision();
}

void vmidi::MidiEvent::calculateDeltaTimeInMs()
{
	deltaTimeInMs = (data.getDeltaTime()[0] * timePerPPQN) / 1000;
}

void vmidi::MidiEvent::calculateDeltaTimeInS()
{
	deltaTimeInS = deltaTimeInMs / 1000;
}

void vmidi::MidiEvent::calculateTimestampInMs()
{
	timestampInMs = (data.getCurrentTime() * timePerPPQN) / 1000;
}

void vmidi::MidiEvent::calculateTimestampInS()
{
	timestampInS = timestampInMs / 1000;
}

//=============================================================================
uint32_t	vmidi::MidiEvent::getDeltaTime()	{return data.getDeltaTime()[0];}
std::string	vmidi::MidiEvent::getType()			{return data.getType();}
std::string	vmidi::MidiEvent::getSpecificType()	{return data.getSpecificType();}
uint32_t	vmidi::MidiEvent::getLength()		{return data.getLength()[0];}

//=============================================================================
float		vmidi::MidiEvent::getCurrentTempo()				{return data.getCurrentTempo();}
float		vmidi::MidiEvent::getCurrentTempoInBPM()		{return currentTempoInBPM;}
float		vmidi::MidiEvent::getTimePerPPQN()				{return timePerPPQN;}
float		vmidi::MidiEvent::getDeltaTimeInMs()			{return deltaTimeInMs;}
float		vmidi::MidiEvent::getDeltaTimeInS()				{return deltaTimeInS;}
float		vmidi::MidiEvent::getTimestamp()				{return data.getCurrentTime();}
float		vmidi::MidiEvent::getTimestampInMs()			{return timestampInMs;}
float		vmidi::MidiEvent::getTimestampInS()				{return timestampInS;}
int			vmidi::MidiEvent::getChannel()					{return data.getChannel();}
int			vmidi::MidiEvent::getNoteNumber()				{return data.getNoteNumber();}
std::string	vmidi::MidiEvent::getNoteName()					{return data.getNoteName();}
int			vmidi::MidiEvent::getVelocity()					{return data.getVelocity();}
int			vmidi::MidiEvent::getPressure()					{return data.getPressure();}
std::string	vmidi::MidiEvent::getController()				{return data.getController();}
int			vmidi::MidiEvent::getControllerValue()			{return data.getControllerValue();}
int			vmidi::MidiEvent::getProgram()					{return data.getProgram();}
int			vmidi::MidiEvent::getPitchBend()				{return data.getPitchBend();}
int			vmidi::MidiEvent::getSequenceNumber()			{return data.getSequenceNumber();}
std::string	vmidi::MidiEvent::getText()						{return data.getText();}
std::string	vmidi::MidiEvent::getCopyright()				{return data.getCopyright();}
std::string	vmidi::MidiEvent::getTrackName()				{return data.getTrackName();}
std::string	vmidi::MidiEvent::getInstrumentName()			{return data.getInstrumentName();}
std::string	vmidi::MidiEvent::getDeviceName()				{return data.getDeviceName();}
int			vmidi::MidiEvent::getEndOfTrack()				{return data.getEndOfTrack();}
int			vmidi::MidiEvent::getSMPTEOffset()				{return data.getSMPTEOffset();}
std::string	vmidi::MidiEvent::getLyric()					{return data.getLyric();}
int			vmidi::MidiEvent::getMarker()					{return data.getMarker();}
int			vmidi::MidiEvent::getCuePoint()					{return data.getCuePoint();}
std::string	vmidi::MidiEvent::getProgramName()				{return data.getProgramName();}
int			vmidi::MidiEvent::getMidiChannelPrefix()		{return data.getMidiChannelPrefix();}
int			vmidi::MidiEvent::getMidiPort()					{return data.getMidiPort();}
float		vmidi::MidiEvent::getTempo()					{return tempo;}
std::vector<uint32_t> vmidi::MidiEvent::getTimeSignature()	{return data.getTimeSignature();}
std::string	vmidi::MidiEvent::getKeySignature()				{return data.getKeySignature();}
int			vmidi::MidiEvent::getSequencerSpecificEvent()	{return data.getSequencerSpecificEvent();}