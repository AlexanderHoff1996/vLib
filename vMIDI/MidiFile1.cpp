#include "MidiFile1.h"

//=============================================================================
vmidi::MidiFileData::MidiFileData()
{

}

vmidi::MidiFileData::~MidiFileData()
{

}

//=============================================================================
void vmidi::MidiFileData::addData(std::vector<uint8_t> theData)
{
	data = theData;
}

//=============================================================================
void vmidi::MidiFileData::getHeaderFromData(std::vector<uint8_t>::iterator position)
{
	// Bytes 0 - 3 ['M', 'T', 'h', 'd']
	for (auto i {position}; i < position + 4; ++i)
	{
		headerIdentifier.push_back(*i);
	}

	/**********************************************************************
	| Remember that midi is in "big-endian", while x86 is "little-endian" |
	| so the byte order should be reversed for multi-byte values          |
	|                                                                     |
	| Note though that the following values are very small                |
	| and they don't actually use more than one byte                      |
	**********************************************************************/

	// Bytes 4 to 7 is the length of the header (should be 6 bytes: 00 00 00 06)
	headerLength = (*(position + 4) << 24 | *(position + 5) << 16 |
		*(position + 6) << 8 | *(position + 7));

	// Bytes 8 - 9 is the format of the midi file (00 00, 00 01 or 00 02)
	SharedData::setFormat(*(position + 8) << 8 | *(position + 9));
	format = SharedData::getFormat();

	// Bytes 10 - 11 is the number of tracks (MTrk's) in the midi file
	SharedData::setNumOfTracks((*(position + 10) << 8 | *(position + 11)));
	numOfTracks = SharedData::getNumOfTracks();

	/*************************************************************************************
	| DIVISION (TIMING)                                                                  |
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

	// Bytes 12 - 13 is the division (timing) of the midi file
	SharedData::setDivision(*(position + 12) << 8 | *(position + 13));
	division = SharedData::getDivision();

	// Check if bit 15 is set (0x8000 is 1000 0000 0000 0000 in binary)s
	uint16_t check = (0x8000 & division);

	SharedData::setTiming(check == 0 ? "Metrical" : "Timecode");
	timing = SharedData::getTiming();
}

//=============================================================================
uint32_t vmidi::MidiFileData::getTrackLengthFromData(std::vector<uint8_t>::iterator position)
{
	// The length of a midi track
	uint32_t trackLength = (*(position) << 24 | *(position + 1) << 16 |
		*(position + 2) << 8 | *(position + 3));

	return trackLength;
}

//=============================================================================
std::vector<uint8_t>& vmidi::MidiFileData::getData()
{
	return data;
}

//=============================================================================
std::vector<uint8_t> vmidi::MidiFileData::getHeaderIdentifier()
{
	return headerIdentifier;
}

uint32_t vmidi::MidiFileData::getHeaderLength()
{
	return headerLength;
}

uint16_t vmidi::MidiFileData::getFormat()
{
	return format;
}

uint16_t vmidi::MidiFileData::getNumOfTracks()
{
	return numOfTracks;
}

uint16_t vmidi::MidiFileData::getDivision()
{
	return division;
}

std::string vmidi::MidiFileData::getTiming()
{
	return timing;
}

float vmidi::MidiFileData::getCurrentTime()
{
	return currentTime;
}


//=============================================================================
vmidi::MidiFile::MidiFile(std::string path)
{
	filename = path;

	// Open the midi file (for reading)
	open();

	// Add the data from the midi file to the MidiFileData object
	// (which is also called data)
	data.addData(getDataFromFile());

	// Check that it's a valid midi file
	if (!isValid())
	{
		throw std::runtime_error("Error: File could not be loaded!");
	}

	else
	{
		// Loop through the midi data
		loopThroughData();
	}
}

vmidi::MidiFile::~MidiFile()
{

}

//=============================================================================
void vmidi::MidiFile::loopThroughData()
{
	std::vector<uint8_t>::iterator position {data.getData().begin()};

	SharedData::setTrackNumber(-1);

	// Go through all the midi data
	while (position < data.getData().end())
	{
		// Header
		if (position == data.getData().begin())
		{
			data.getHeaderFromData(position);

			position += 14;
			continue;
		}

		// Track
		if (*position == 'M' && *(position + 1) == 'T' &&
			*(position + 2) == 'r' && *(position + 3) == 'k')
		{
			SharedData::setTrackNumber(SharedData::getTrackNumber() + 1);

			auto trackLength {data.getTrackLengthFromData(position + 4)};
			std::vector<uint8_t> trackData = {position, position + 8 + trackLength};

			position += 8 + trackLength;

			// Add a track with all the data
			tracks.push_back(std::make_unique<MidiTrack>(trackData, trackLength));

			// The current value of SharedData::trackNumber is copied 
			// to another variable in the MidiTrack constructor
			continue;
		}

		else
		{
			position++;
		}
	}

	// After adding all tracks and events, calculate the total length
	// (n minutes, seconds and milliseconds) of the midi file
	calculateTotalTime();
}

//=============================================================================
std::vector<uint8_t> vmidi::MidiFile::getDataFromFile()
{
	// The vector of data that will be returned
	std::vector<uint8_t> data;

	// Temporary vector to store bytes as regular chars
	std::vector<char> plainCharVector;

	// Go through the whole file (one byte/character at a time)
	for (int i {0}; file; ++i)
	{
		// Set the position in the midi file
		file.seekg(i);

		// Get the byte from the current position
		// in the midi file and add it to data
		plainCharVector.push_back('0');
		file.get(plainCharVector[i]);

		// Add the byte to data
		data.push_back(static_cast<uint8_t>(plainCharVector[i]));
	}

	return data;
}

//=============================================================================
int vmidi::MidiFile::getFormat()
{
	return data.getFormat();
}

int vmidi::MidiFile::getDivision()
{
	return data.getDivision();
}

std::string vmidi::MidiFile::getTiming()
{
	return data.getTiming();
}

size_t vmidi::MidiFile::getNumTracks()
{
	return data.getNumOfTracks();
}

std::string vmidi::MidiFile::getSequenceName()
{
	return SharedData::getSequenceName();
}

//=============================================================================
void vmidi::MidiFile::calculateTotalTime()
{
	int timeInMs {0};
	int timeInS  {0};
	int timeInM  {0};

	for (int i {0}; i < getNumTracks(); ++i)
	{
		for (int j {0}; j < getTrack(i)->getNumEvents(); ++j)
		{
			if (totalTimeInMs < getTrack(i)->getEvent(j)->getTimestampInMs() &&
				(getTrack(i)->getEvent(j)->getSpecificType() == "Note On") ||
				(getTrack(i)->getEvent(j)->getSpecificType() == "Note Off"))
			{
				totalTimeInMs = getTrack(i)->getEvent(j)->getTimestampInMs();
			}
		}
	}

	timeInMs = static_cast<int>(std::round(totalTimeInMs));
	timeInMs %= 1000;

	timeInS = static_cast<int>(std::round(totalTimeInMs));
	timeInS -= timeInMs;
	timeInS /= 1000;
	timeInS %= 60;

	timeInM = static_cast<int>(std::round(totalTimeInMs));
	timeInM -= timeInMs;
	timeInM /= 60000;

	totalTime[0] = timeInM;
	totalTime[1] = timeInS;
	totalTime[2] = timeInMs;
}

float vmidi::MidiFile::getTotalTimeInMs()
{
	return totalTimeInMs;
}

std::vector<int> vmidi::MidiFile::getTotalTime()
{
	return totalTime;
}

//=============================================================================
vmidi::MidiTrack* vmidi::MidiFile::getTrack(int n)
{
	return tracks[n].get();
}

vmidi::MidiTrack* vmidi::MidiFile::getFirstTrack()
{
	return tracks[0].get();
}

vmidi::MidiTrack* vmidi::MidiFile::getFinalTrack()
{
	return tracks[tracks.size() - 1].get();
}

//=============================================================================
void vmidi::MidiFile::open()
{
	std::filesystem::path path {filename};
	file.open(path, std::ios::binary);

	// Check if the midi file could be loaded
	if (!file || path.extension() != ".mid")
	{
		throw std::runtime_error("Error: File could not be loaded!");
	}
}

//=============================================================================
bool vmidi::MidiFile::isValid()
{
	/**********************************************************************************************
	| The first 14 bytes in a midi file is the header chunk                                       |
	| and the header chunk must begin with "MThd"                                                 |
	|                                                                                             |
	| After the header chunk there must be at least one track chunk                               |
	| and track chunks begin with "MTrk"                                                          |
	|                                                                                             |
	| Also if the file is shorter than 18 characters (or bytes)                                   |
	| then it's impossible for it to be a valid midi file (header(14) + MTrk(4) = 18)             |
	| It's added first so this doesn't cause an out of range error                                |
	|                                                                                             |
	| Finally we check if the file ends with an "End of Track" midi meta event                    |
	| Three bytes with the the first two having the hex values "FF", "2F", the last byte is 0     |
	| string.size() - 2 is actually the last value, I believe an extra byte gets added at the end |
	**********************************************************************************************/

	if (data.getData().size() < 18 ||

		// M = 77, T = 84, h = 104, d = 100
		// M = 77, T = 84, r = 114, k = 107

		data.getData()[0] != 77 || data.getData()[1] != 84 ||
		data.getData()[2] != 104 || data.getData()[3] != 100 ||
		data.getData()[14] != 77 || data.getData()[15] != 84 ||
		data.getData()[16] != 114 || data.getData()[17] != 107 ||

		data.getData()[data.getData().size() - 4] != 0xFF ||
		data.getData()[data.getData().size() - 3] != 0x2F ||
		data.getData()[data.getData().size() - 2] != 0)
	{
		return false;
	}

	else
	{
		return true;
	}
}

//=============================================================================
void vmidi::MidiFile::saveDataToTextFile()
{
	std::string txtFilename {filename.erase(filename.find('.')) + ".txt"};
	std::ofstream txtFile(txtFilename, std::ios::binary);

	txtFile << "FORMAT          " << getFormat() << std::endl;
	txtFile << "TRACKS          " << getNumTracks() << std::endl;
	txtFile << "DIVISION        " << getDivision() << std::endl;
	txtFile << "TIMING          " << getTiming() << std::endl;
	
	if ((getFormat() == 0 || getFormat() == 1)
		&& !getSequenceName().empty())
	{
		txtFile << "SEQUENCE NAME   " << getSequenceName() << std::endl;
	}

	// Total length (ms) (float)
	txtFile << "LENGTH (ms)     " << getTotalTimeInMs() << " ms" << std::endl;


	// Total length (min:sec.ms) (int)

	int timeInM  {getTotalTime()[0]};
	int timeInS  {getTotalTime()[1]};
	int timeInMs {getTotalTime()[2]};

	txtFile << "LENGTH          ";

	if (timeInM < 10)	txtFile << "0" << timeInM;
	else				txtFile << timeInM;

	txtFile << ":";

	if (timeInS < 10)	txtFile << "0" << timeInS;
	else				txtFile << timeInS;

	txtFile << ".";

	if (timeInMs < 10)							txtFile << "00" << timeInMs << std::endl;
	else if (timeInMs >= 10 && timeInMs < 100)	txtFile << "0" << timeInMs << std::endl;
	else										txtFile << timeInMs << std::endl;


	txtFile << std::endl;


	for (int i {0}; i < getNumTracks(); ++i)
	{
		txtFile << "TRACK " << i << std::endl;

		if (getFormat() == 1 && i != 0)
		{
			txtFile << "        NAME: " <<
				getTrack(i)->getTrackName() << std::endl;
			txtFile << std::endl;
		}

		else if (getFormat() == 1 && i == 0)
		{
			txtFile << "        TEMPO TRACK" << std::endl;
			txtFile << std::endl;
		}

		for (int j {0}; j < getTrack(i)->getNumEvents(); ++j)
		{
			txtFile << "        EVENT " << j << std::endl;
			txtFile << "                DELTATIME                   " <<
				getTrack(i)->getEvent(j)->getDeltaTime() << std::endl;
			
			txtFile << "                DELTATIME (ms)              " <<
				getTrack(i)->getEvent(j)->getDeltaTimeInMs() << " ms" << std::endl;
			
			txtFile << "                DELTATIME (s)               " <<
				getTrack(i)->getEvent(j)->getDeltaTimeInS() << " s" << std::endl;

			txtFile << "                TIMESTAMP                   " <<
				getTrack(i)->getEvent(j)->getTimestamp() << std::endl;
			
			txtFile << "                TIMESTAMP (ms)              " <<
				getTrack(i)->getEvent(j)->getTimestampInMs() << " ms" << std::endl;

			txtFile << "                TIMESTAMP (s)               " <<
				getTrack(i)->getEvent(j)->getTimestampInS() << " s" << std::endl;
			
			txtFile << "                CURRENT TEMPO               " <<
				getTrack(i)->getEvent(j)->getCurrentTempo() << std::endl;

			txtFile << "                CURRENT TEMPO (BPM)         " <<
				getTrack(i)->getEvent(j)->getCurrentTempoInBPM() << " BPM" << std::endl;
			
			txtFile << "                TIME PER PPQN               " <<
				getTrack(i)->getEvent(j)->getTimePerPPQN() << " \xB5s" << std::endl;

			txtFile << std::endl;
			
			txtFile << "                TYPE                        " <<
				getTrack(i)->getEvent(j)->getType() << std::endl;
			
			txtFile << "                SPECIFIC TYPE               " <<
				getTrack(i)->getEvent(j)->getSpecificType() << std::endl;

			txtFile << std::endl;

			// Midi events
			if (getTrack(i)->getEvent(j)->getSpecificType() == "Note Off" ||
				getTrack(i)->getEvent(j)->getSpecificType() == "Note On")
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;
				
				txtFile << "                NOTE NUMBER                 " <<
					getTrack(i)->getEvent(j)->getNoteNumber() << std::endl;

				txtFile << "                NOTE NAME                   " <<
					getTrack(i)->getEvent(j)->getNoteName() << std::endl;
				    
				txtFile << "                VELOCITY                    " <<
					getTrack(i)->getEvent(j)->getVelocity() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Polyphonic Pressure")
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;

				txtFile << "                NOTE NUMBER                 " <<
					getTrack(i)->getEvent(j)->getNoteNumber() << std::endl;

				txtFile << "                NOTE NAME                   " <<
					getTrack(i)->getEvent(j)->getNoteName() << std::endl;

				txtFile << "                PRESSURE                    " <<
					getTrack(i)->getEvent(j)->getPressure() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Controller")
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;

				txtFile << "                CONTROLLER                  " <<
					getTrack(i)->getEvent(j)->getController() << std::endl;

				txtFile << "                VALUE                       " <<
					getTrack(i)->getEvent(j)->getControllerValue() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Program Change")
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;

				txtFile << "                PROGRAM                     " <<
					getTrack(i)->getEvent(j)->getProgram() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Channel Pressure")
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;

				txtFile << "                PRESSURE                    " <<
					getTrack(i)->getEvent(j)->getPressure() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Pitch Bend")
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;

				txtFile << "                PITCH BEND                  " <<
					getTrack(i)->getEvent(j)->getPitchBend() << std::endl << std::endl;
			}

			// SysEx events
			else if (getTrack(i)->getEvent(j)->getSpecificType() == "SysExSingle")
			{

			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "SysExEscape")
			{

			}

			// Meta events
			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Sequence Number")
			{
				txtFile << "                SEQUENCE NUMBER             " <<
					getTrack(i)->getEvent(j)->getSequenceNumber();
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Text")
			{
				txtFile << "                TEXT                        " <<
					getTrack(i)->getEvent(j)->getText() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Copyright")
			{
				txtFile << "                COPYRIGHT                   " <<
					SharedData::getCopyright() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Track Name")
			{
				txtFile << "                TRACK NAME                  " <<
					getTrack(i)->getEvent(j)->getTrackName() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Instrument Name")
			{
				txtFile << "                INSTRUMENT NAME             " <<
					getTrack(i)->getEvent(j)->getInstrumentName() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Lyric")
			{
				txtFile << "                LYRIC                       " <<
					getTrack(i)->getEvent(j)->getLyric() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Marker")
			{
				txtFile << "                MARKER                      " <<
					getTrack(i)->getEvent(j)->getMarker() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Cue Point")
			{
				txtFile << "                CUE POINT                   " <<
					getTrack(i)->getEvent(j)->getCuePoint() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Program Name")
			{
				txtFile << "                PROGRAM NAME                " <<
					getTrack(i)->getEvent(j)->getProgramName() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Device Name")
			{
				txtFile << "                DEVICE NAME                 " <<
					SharedData::getDeviceName() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "MIDI Channel Prefix")
			{
				txtFile << "                MIDI CHANNEL PREFIX         " <<
					getTrack(i)->getEvent(j)->getMidiChannelPrefix() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "MIDI Port")
			{
				txtFile << "                MIDI PORT                   " <<
					getTrack(i)->getEvent(j)->getMidiPort() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "End of Track")
			{
				txtFile << "                END OF TRACK" << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Tempo")
			{
				txtFile << "                TEMPO                       " <<
					getTrack(i)->getEvent(j)->getTempo() << " BPM" << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "SMPTE Offset")
			{
				txtFile << "                SMPTE OFFSET                " <<
					getTrack(i)->getEvent(j)->getSMPTEOffset() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Time Signature")
			{
				txtFile << "                TIME SIGNATURE              " <<
					getTrack(i)->getEvent(j)->getTimeSignature()[0] <<
					"/" << getTrack(i)->getEvent(j)->getTimeSignature()[1] << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Key Signature")
			{
				txtFile << "                KEY SIGNATURE               " <<
					getTrack(i)->getEvent(j)->getKeySignature() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == "Sequencer Specific Event")
			{
				txtFile << "                SEQUENCER SPECIFIC EVENT    " <<
					getTrack(i)->getEvent(j)->getSequencerSpecificEvent() << std::endl << std::endl;
			}

			else
			{
				txtFile << "NOT AN EVENT!" << std::endl;
			}
		}

		txtFile << std::endl;
	}
}