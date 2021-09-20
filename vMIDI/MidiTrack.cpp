#include "MidiTrack.h"

//=============================================================================
vmidi::MidiTrackData::MidiTrackData()
{

}

vmidi::MidiTrackData::~MidiTrackData()
{

}

//=============================================================================
void vmidi::MidiTrackData::addData(std::vector<uint8_t>& theData)
{
	data = theData;
}

std::vector<uint8_t>& vmidi::MidiTrackData::getData()
{
	return data;
}

//=============================================================================
void vmidi::MidiTrackData::getIdentifierFromData(
	std::vector<uint8_t>::iterator position)
{
	// Bytes 0 - 3:	The identifier (MTrk)
	for (auto i {position}; i < position + 4; ++i)
	{
		identifier.push_back(*i);
	}
	
	// Bytes 4 - 7, the length of the following data (after the header)),
	// is already set using setLength()
}

//=============================================================================
void vmidi::MidiTrackData::setLength(uint32_t& trackLength)
{
	length = trackLength;
}

uint32_t& vmidi::MidiTrackData::getLength()
{
	return length;
}

//=============================================================================
void vmidi::MidiTrackData::setFormat(uint16_t midiFormat)
{
	format = midiFormat;
}

uint16_t vmidi::MidiTrackData::getFormat()
{
	return format;
}

void vmidi::MidiTrackData::setDivision(uint16_t midiDivision)
{
	division = midiDivision;
}

uint16_t vmidi::MidiTrackData::getDivision()
{
	return division;
}

void vmidi::MidiTrackData::setTiming(std::string midiTiming)
{
	timing = midiTiming;
}

std::string vmidi::MidiTrackData::getTiming()
{
	return timing;
}

void vmidi::MidiTrackData::setTrackNumber(int trackN)
{
	trackNumber = trackN;
}

int vmidi::MidiTrackData::getTrackNumber()
{
	return trackNumber;
}

//=============================================================================
std::string vmidi::MidiTrackData::getTrackName()
{
	return trackName;
}

void vmidi::MidiTrackData::setCurrentTempo(float currTempo)
{
	currentTempo = currTempo;
}

float vmidi::MidiTrackData::getCurrentTempo()
{
	return currentTempo;
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

std::vector<uint32_t> vmidi::MidiTrackData::getDeltaTimeOrLengthFromData(
	std::vector<uint8_t>::iterator position)
{
	// First value is the delta time or length
	// Second value is the number of bytes it uses
	std::vector<uint32_t> vector {0, 0};

	vector[1] = getVariableLengthQuantity(position);

	// Set the delta time depending on how many bytes it uses
	switch (vector[1])
	{
	case 1:
		vector[0] = *(position);
		break;

	case 2:
		// 1. byte1 = (*(position) & 0x7F)
		// 2. byte1 = byte1 << 7
		// 3. byte2 = (*(position + 1) & 0x7F)
		// 4. value = byte1 | byte2

		// (No bit shift on last byte)

		// Or in one statement
		vector[0] = (((*(position) & 0x7F) << 7) | (*(position + 1) & 0x7F));
		break;

	case 3:
		vector[0] = (((*(position) & 0x7F) << 14) | ((*(position + 1) & 0x7F) << 7) |
			(*(position + 2) & 0x7F));
		break;

	case 4:
		vector[0] = (((*(position) & 0x7F) << 21) | ((*(position + 1) & 0x7F) << 14) |
			((*(position + 2) & 0x7F) << 7) | (*(position + 3) & 0x7F));
		break;
	}

	return vector;
}

int vmidi::MidiTrackData::getVariableLengthQuantity(
	std::vector<uint8_t>::iterator position)
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
std::string vmidi::MidiTrackData::getEventTypeFromData(
	std::vector<uint8_t>::iterator position)
{
	std::string eventType;

	// Midi event
	if (*position >= 0x80 && *position <= 0xEF)
	{
		eventType = "Midi";

		// Reset running status
		SharedData::setRunningStatus(0);
	}

	// Midi event (running status)
	else if (*position < 0x80)
	{
		eventType = "Midi (running status)";
	}

	// SysEx event
	else if (*position == 0xF0 || *position == 0xF7)
	{
		eventType = "SysEx";

		// Reset running status
		SharedData::setRunningStatus(0);
	}

	// Meta event
	else if (*position == 0xFF)
	{
		eventType = "Meta";

		// Reset running status
		SharedData::setRunningStatus(0);
	}

	else
	{
		throw std::runtime_error("Error: Not an event!");
	}

	return eventType;
}

//=============================================================================
std::string vmidi::MidiTrackData::getSpecificEventTypeFromData(
	std::vector<uint8_t>::iterator position, std::string& eventType,
	std::vector<uint32_t>& deltaTime)
{
	// The delta time is used for running status midi events
	// With deltaTime[1] you get the number of bytes it uses

	std::string specificEventType;

	if (eventType == "Midi")
	{
		if (*position >= 0x80 && *position <= 0x8F)
			specificEventType = "Note Off";

		else if (*position >= 0x90 && *position <= 0x9F)
			specificEventType = "Note On";

		else if (*position >= 0xA0 && *position <= 0xAF)
			specificEventType = "Polyphonic Pressure";

		else if (*position >= 0xB0 && *position <= 0xBF)
			specificEventType = "Controller";

		else if (*position >= 0xC0 && *position <= 0xCF)
			specificEventType = "Program Change";

		else if (*position >= 0xD0 && *position <= 0xDF)
			specificEventType = "Channel Pressure";

		else if (*position >= 0xE0 && *position <= 0xEF)
			specificEventType = "Pitch Bend";
	}

	else if (eventType == "Midi (running status)")
	{
		// Beginning of the midi event before this one
		// It can only be the same specific type of event (note on, note off, etc)
		auto positionOfPreviousMidiEvent {position - deltaTime[1] - 3};

		// Set running status to the previous event
		if (SharedData::getRunningStatus() == 0)
		{
			SharedData::setRunningStatus(*positionOfPreviousMidiEvent);
		}

		if (SharedData::getRunningStatus() >= 0x80 &&
			SharedData::getRunningStatus() <= 0x8F)
			specificEventType = "Note Off";

		else if (SharedData::getRunningStatus() >= 0x90 &&
			SharedData::getRunningStatus() <= 0x9F)
			specificEventType = "Note On";

		else if (SharedData::getRunningStatus() >= 0xA0 &&
			SharedData::getRunningStatus() <= 0xAF)
			specificEventType = "Polyphonic Pressure";

		else if (SharedData::getRunningStatus() >= 0xB0 &&
			SharedData::getRunningStatus() <= 0xBF)
			specificEventType = "Controller";

		else if (SharedData::getRunningStatus() >= 0xC0 &&
			SharedData::getRunningStatus() <= 0xCF)
			specificEventType = "Program Change";

		else if (SharedData::getRunningStatus() >= 0xD0 &&
			SharedData::getRunningStatus() <= 0xDF)
			specificEventType = "Channel Pressure";

		else if (SharedData::getRunningStatus() >= 0xE0 &&
			SharedData::getRunningStatus() <= 0xEF)
			specificEventType = "Pitch Bend";
	}

	else if (eventType == "SysEx")
	{
		if (*position == 0xF0)
			specificEventType = "Single";

		else if (*position == 0xF7)
			specificEventType = "Escape";
	}

	else if (eventType == "Meta")
	{
		if (*(position + 1) == 0x00)
			specificEventType = "Sequence Number";

		else if (*(position + 1) == 0x01)
			specificEventType = "Text";

		else if (*(position + 1) == 0x02)
			specificEventType = "Copyright";

		else if (*(position + 1) == 0x03)
			specificEventType = "Track Name";

		else if (*(position + 1) == 0x04)
			specificEventType = "Instrument Name";

		else if (*(position + 1) == 0x05)
			specificEventType = "Lyric";

		else if (*(position + 1) == 0x06)
			specificEventType = "Marker";

		else if (*(position + 1) == 0x07)
			specificEventType = "Cue Point";

		else if (*(position + 1) == 0x08)
			specificEventType = "Program Name";

		else if (*(position + 1) == 0x09)
			specificEventType = "Device Name";

		else if (*(position + 1) == 0x20)
			specificEventType = "MIDI Channel Prefix";

		else if (*(position + 1) == 0x21)
			specificEventType = "MIDI Port";

		else if (*(position + 1) == 0x2F)
			specificEventType = "End of Track";

		else if (*(position + 1) == 0x51)
			specificEventType = "Tempo";

		else if (*(position + 1) == 0x54)
			specificEventType = "SMPTE Offset";

		else if (*(position + 1) == 0x58)
			specificEventType = "Time Signature";

		else if (*(position + 1) == 0x59)
			specificEventType = "Key Signature";

		else if (*(position + 1) == 0x7F)
			specificEventType = "Sequencer Specific Event";
	}

	else
	{
		throw std::runtime_error("Error: Not an event!");
	}

	return specificEventType;
}

//=============================================================================
std::vector<uint32_t> vmidi::MidiTrackData::getEventLengthFromData(
	std::vector<uint8_t>::iterator position, std::string& specificEventType)
{
	// 1. Total event length (excluding delta time),
	// 2. Variable length (only some events)
	// 3. Number of bytes 2. uses (only some events)
	std::vector<uint32_t> eventLength {0, 0, 0};

	// Used for events with variable length quantities
	std::vector<uint32_t> varEventLength;


	// Midi events

	if (specificEventType == "Note Off")
		eventLength[0] = 3;

	else if (specificEventType == "Note On")
		eventLength[0] = 3;

	else if (specificEventType == "Polyphonic Pressure")
		eventLength[0] = 3;

	else if (specificEventType == "Controller")
		eventLength[0] = 3;

	else if (specificEventType == "Program Change")
		eventLength[0] = 2;

	else if (specificEventType == "Channel Pressure")
		eventLength[0] = 2;

	else if (specificEventType == "Pitch Bend")
		eventLength[0] = 3;


	// SysEx events

	else if (specificEventType == "Single")
	{
		varEventLength = getDeltaTimeOrLengthFromData(position);
		eventLength[0] = 1 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];
	}

	else if (specificEventType == "Escape")
	{
		varEventLength = getDeltaTimeOrLengthFromData(position);
		eventLength[0] = 1 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];
	}


	// Meta events

	else if (specificEventType == "Sequence Number")
		eventLength[0] = 5;

	else if (specificEventType == "Text")
	{
		varEventLength = getDeltaTimeOrLengthFromData(position + 2);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];
	}

	else if (specificEventType == "Copyright")
	{
		/********************
		| Copyright         |
		| FF 02 length text |
		********************/

		// Everything is pretty much the same as with Sequence/Track Name

		// 0. Total event length (from FF, excluding delta time),
		// 1. length of text
		// 2. Number of bytes 1. uses

		varEventLength = getDeltaTimeOrLengthFromData(position + 2);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];

		position += 1 + eventLength[2] + 1;
		auto endPosition = position + eventLength[1];

		std::string name;

		for (auto i {position}; i < endPosition; ++i)
		{
			SharedData::setCopyright(SharedData::getCopyright() += *i);
		}
	}

	else if (specificEventType == "Track Name")
	{
		/**********************
		| Sequence/Track Name |
		| FF 03 length text   |
		**********************/

		// This is the sequence name if it's the first track in a format 0 or 1 file
		// Otherwise it's the track name

		// This event is added both here in MidiTrack and later in MidiEvent
		// The reason is that you want to be able to do midiFile.getTrack(n)->getTrackName()
		// But also all events should be added in MidiEvent
		// So for example, you can loop through all events in a track

		// 0. Total event length (from FF, excluding delta time),
		// 1. length of text
		// 2. Number of bytes 1. uses

		varEventLength = getDeltaTimeOrLengthFromData(position + 2);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];

		position += 1 + eventLength[2] + 1;
		auto endPosition = position + eventLength[1];

		std::string name;

		for (auto i {position}; i < endPosition; ++i)
		{
			if ((format == 0 || format == 1) && trackNumber == 0)
			{
				SharedData::setSequenceName(SharedData::getSequenceName() += *i);
			}

			else
			{
				trackName += *i;
			}
		}
	}

	else if (specificEventType == "Instrument Name")
	{
		varEventLength = getDeltaTimeOrLengthFromData(position + 2);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];
	}

	else if (specificEventType == "Lyric")
	{
		varEventLength = getDeltaTimeOrLengthFromData(position + 2);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];
	}

	else if (specificEventType == "Marker")
	{
		varEventLength = getDeltaTimeOrLengthFromData(position + 2);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];
	}

	else if (specificEventType == "Cue Point")
	{
		varEventLength = getDeltaTimeOrLengthFromData(position + 2);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];
	}

	else if (specificEventType == "Program Name")
	{
		varEventLength = getDeltaTimeOrLengthFromData(position + 2);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];
	}

	else if (specificEventType == "Device Name")
	{
		/********************
		| Device Name       |
		| FF 08 length text |
		********************/

		// Everything is pretty much the same as with Sequence/Track Name

		// 0. Total event length (from FF, excluding delta time),
		// 1. length of text
		// 2. Number of bytes 1. uses

		varEventLength = getDeltaTimeOrLengthFromData(position + 2);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];

		position += 1 + eventLength[2] + 1;
		auto endPosition = position + eventLength[1];

		std::string name;

		for (auto i {position}; i < endPosition; ++i)
		{
			SharedData::setDeviceName(SharedData::getDeviceName() += *i);
		}
	}

	else if (specificEventType == "MIDI Channel Prefix")
		eventLength[0] = 4;

	else if (specificEventType == "MIDI Port")
		eventLength[0] = 4;

	else if (specificEventType == "End of Track")
		eventLength[0] = 3;

	else if (specificEventType == "Tempo")
	{
		eventLength[0] = 6;

		// We need the current tempo (in microseconds per quarter note)
		// to figure out the delta time later (in MidiEvent)
		SharedData::setCurrentTempo(static_cast<float>(*(position + 3) << 16 |
			*(position + 4) << 8 | *(position + 5)));
		currentTempo = SharedData::getCurrentTempo();
	}

	else if (specificEventType == "SMPTE Offset")
		eventLength[0] = 8;

	else if (specificEventType == "Time Signature")
		eventLength[0] = 7;

	else if (specificEventType == "Key Signature")
		eventLength[0] = 5;

	else if (specificEventType == "Sequencer Specific Event")
	{
		varEventLength = getDeltaTimeOrLengthFromData(position);
		eventLength[0] = 2 + varEventLength[1] + varEventLength[0];
		eventLength[1] = varEventLength[0];
		eventLength[2] = varEventLength[1];
	}

	else
	{
		throw std::runtime_error("Error: Not an event!");
	}

	// If running status is in effect, reduce the length by 1
	// (since there's no note on/note off, etc, status byte)
	if (SharedData::getRunningStatus() != 0)
		eventLength[0]--;

	return eventLength;
}


//=============================================================================
vmidi::MidiTrack::MidiTrack(std::vector<uint8_t>& trackData, uint32_t& trackLength)
{
	// Add the track data
	data.addData(trackData);

	// Set some variables
	data.setLength(trackLength);
	data.setFormat(SharedData::getFormat());
	data.setDivision(SharedData::getDivision());
	data.setTiming(SharedData::getTiming());
	data.setTrackNumber(SharedData::getTrackNumber());

	// Loop through the track data
	loopThroughData();
}

vmidi::MidiTrack::~MidiTrack()
{

}

//=============================================================================
void vmidi::MidiTrack::loopThroughData()
{
	std::vector<uint8_t>::iterator position {data.getData().begin()};

	// Go through all the track data
	while (position < data.getData().end())
	{
		// Track header
		if (position == data.getData().begin())
		{
			data.getIdentifierFromData(position);

			position += 8;
			continue;
		}

		// Event
		if (position >= data.getData().begin() + 8 &&
			position < data.getData().end() - 1)
		{
			auto initialPosition {position};

			// Delta time (1 to 4 bytes)
			// [delta time, number of bytes]
			auto deltaTime {data.getDeltaTimeOrLengthFromData(position)};
			position += deltaTime[1];

			// Event type
			auto eventType {data.getEventTypeFromData(position)};

			// Specific event type
			auto specificEventType {data.getSpecificEventTypeFromData(position,
				eventType, deltaTime)};

			// Length (total length of event excluding delta time)
			auto eventLength {data.getEventLengthFromData(position, specificEventType)};
			position += eventLength[0];

			// All event data (including delta time)
			std::vector<uint8_t> eventData = {initialPosition, position};

			// Add an event with all the data
			events.push_back(std::make_unique<MidiEvent>(eventData, eventLength,
				deltaTime, eventType, specificEventType));
			continue;
		}

		else
		{
			position++;
		}
	}
}

//=============================================================================
size_t vmidi::MidiTrack::getNumEvents()
{
	return events.size();
}

vmidi::MidiEvent* vmidi::MidiTrack::getEvent(int n)
{
	return events[n].get();
}

vmidi::MidiEvent* vmidi::MidiTrack::getFirstEvent()
{
	return events[0].get();
}

vmidi::MidiEvent* vmidi::MidiTrack::getFinalEvent()
{
	return events[events.size() - 1].get();
}

std::string vmidi::MidiTrack::getTrackName()
{
	return data.getTrackName();
}