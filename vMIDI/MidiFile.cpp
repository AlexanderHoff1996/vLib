#include "MidiFile.h"

//=============================================================================
vMIDI::MidiFile::MidiFile(std::string path)
{
	file.open(path);
	
	Data::getFromFile(file);
	Data::setSharedData();
	Data::writeToTracks(tracks);

	calculateTotalTime();
}

vMIDI::MidiFile::~MidiFile()
{

}

//=============================================================================
vMIDI::MidiTrack* vMIDI::MidiFile::getTrack(unsigned int n)
{
	return tracks[n].get();
}

vMIDI::MidiTrack* vMIDI::MidiFile::getFirstTrack()
{
	return tracks[0].get();
}

vMIDI::MidiTrack* vMIDI::MidiFile::getFinalTrack()
{
	return tracks[tracks.size() - 1].get();
}

//=============================================================================
int vMIDI::MidiFile::getFormat()
{
	return SharedData::getFormat();
}

int vMIDI::MidiFile::getTiming()
{
	return SharedData::getTiming();
}

std::string vMIDI::MidiFile::getTimingType()
{
	return SharedData::getTimingType();
}

size_t vMIDI::MidiFile::getNumTracks()
{
	return SharedData::getNumberOfTracks();
}

std::string vMIDI::MidiFile::getSequenceName()
{
	return SharedData::getSequenceName();
}

//=============================================================================
void vMIDI::MidiFile::calculateTotalTime()
{
	int timeInMs {0};
	int timeInS {0};
	int timeInM {0};

	for (int i {0}; i < SharedData::getNumberOfTracks(); ++i)
	{
		for (int j {0}; j < getTrack(i)->getNumEvents(); ++j)
		{
			if (totalTimeInMs < getTrack(i)->getEvent(j)->getTimestampInMs() &&
				(getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::NoteOn) ||
				(getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::NoteOff))
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

float vMIDI::MidiFile::getTotalTimeInMs()
{
	return totalTimeInMs;
}

std::vector<int> vMIDI::MidiFile::getTotalTime()
{
	return totalTime;
}

//=============================================================================
void vMIDI::MidiFile::saveDataToTextFile()
{
	std::string filename {file.getPath().string()};
	std::string txtFilename {filename.erase(filename.find('.')) + ".txt"};
	
	writeToTextFile(txtFilename);
}

void vMIDI::MidiFile::saveDataToTextFile(std::string filename)
{
	if (!filename.ends_with(".txt"))
		filename += ".txt";

	writeToTextFile(filename);
}

void vMIDI::MidiFile::writeToTextFile(std::string filename)
{
	std::ofstream txtFile(filename, std::ios::binary);

	txtFile << "FORMAT          " << getFormat() << std::endl;
	txtFile << "TRACKS          " << getNumTracks() << std::endl;
	txtFile << "TIMING          " << getTiming() << std::endl;
	txtFile << "TIMING (TYPE)   " << getTimingType() << std::endl;

	if ((getFormat() == 0 || getFormat() == 1)
		&& !getSequenceName().empty())
	{
		txtFile << "SEQUENCE NAME   " << getSequenceName() << std::endl;
	}

	// Total length (ms) (float)
	txtFile << "LENGTH (ms)     " << getTotalTimeInMs() << " ms" << std::endl;


	// Total length (min:sec.ms) (int)

	int timeInM {getTotalTime()[0]};
	int timeInS {getTotalTime()[1]};
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

			txtFile << "                TEMPO AT EVENT              " <<
				getTrack(i)->getEvent(j)->getTempoAtEvent() << std::endl;

			txtFile << "                TEMPO AT EVENT (BPM)        " <<
				getTrack(i)->getEvent(j)->getTempoAtEventBPM() << " BPM" << std::endl;

			txtFile << "                TIME PER PPQN               " <<
				getTrack(i)->getEvent(j)->getTimePerPPQN() << " \xB5s" << std::endl;

			txtFile << std::endl;

			txtFile << "                TYPE                        " <<
				getTrack(i)->getEvent(j)->getTypeName() << std::endl;

			txtFile << "                SPECIFIC TYPE               " <<
				getTrack(i)->getEvent(j)->getSpecificTypeName() << std::endl;

			if (getTrack(i)->getEvent(j)->getType() == Type::MIDI)
			{
				txtFile << std::endl;

				std::string runningStatus {"False"};

				if (getTrack(i)->getEvent(j)->getRunningStatus())
					runningStatus = "True";

				txtFile << "                RUNNING STATUS              " <<
					runningStatus << std::endl;
			}

			txtFile << std::endl;

			// Midi events
			if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::NoteOff ||
				getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::NoteOn)
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

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::PolyphonicPressure)
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

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::Controller)
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;

				txtFile << "                CONTROLLER                  " <<
					getTrack(i)->getEvent(j)->getController() << std::endl;

				txtFile << "                VALUE                       " <<
					getTrack(i)->getEvent(j)->getControllerValue() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::ProgramChange)
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;

				txtFile << "                PROGRAM                     " <<
					getTrack(i)->getEvent(j)->getProgram() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::ChannelPressure)
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;

				txtFile << "                PRESSURE                    " <<
					getTrack(i)->getEvent(j)->getPressure() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::PitchBend)
			{
				txtFile << "                CHANNEL                     " <<
					getTrack(i)->getEvent(j)->getChannel() << std::endl;

				txtFile << "                PITCH BEND                  " <<
					getTrack(i)->getEvent(j)->getPitchBend() << std::endl << std::endl;
			}

			// SysEx events
			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::SingleSysEx)
			{

			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::EscapeSequence)
			{

			}

			// Meta events
			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::SequenceNumber)
			{
				txtFile << "                SEQUENCE NUMBER             " <<
					getTrack(i)->getEvent(j)->getSequenceNumber();
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::Text)
			{
				txtFile << "                TEXT                        " <<
					getTrack(i)->getEvent(j)->getText() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::Copyright)
			{
				txtFile << "                COPYRIGHT                   " <<
					SharedData::getCopyright() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::TrackName)
			{
				txtFile << "                TRACK NAME                  " <<
					getTrack(i)->getEvent(j)->getTrackName() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::InstrumentName)
			{
				txtFile << "                INSTRUMENT NAME             " <<
					getTrack(i)->getEvent(j)->getInstrumentName() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::Lyric)
			{
				txtFile << "                LYRIC                       " <<
					getTrack(i)->getEvent(j)->getLyric() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::Marker)
			{
				txtFile << "                MARKER                      " <<
					getTrack(i)->getEvent(j)->getMarker() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::CuePoint)
			{
				txtFile << "                CUE POINT                   " <<
					getTrack(i)->getEvent(j)->getCuePoint() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::ProgramName)
			{
				txtFile << "                PROGRAM NAME                " <<
					getTrack(i)->getEvent(j)->getProgramName() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::DeviceName)
			{
				txtFile << "                DEVICE NAME                 " <<
					SharedData::getDeviceName() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::MidiChannelPrefix)
			{
				txtFile << "                MIDI CHANNEL PREFIX         " <<
					getTrack(i)->getEvent(j)->getMidiChannelPrefix() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::MidiPort)
			{
				txtFile << "                MIDI PORT                   " <<
					getTrack(i)->getEvent(j)->getMidiPort() << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::EndOfTrack)
			{
				txtFile << "                END OF TRACK" << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::Tempo)
			{
				txtFile << "                TEMPO                       " <<
					getTrack(i)->getEvent(j)->getTempo() << std::endl;
				txtFile << "                TEMPO (BPM)                 " <<
					getTrack(i)->getEvent(j)->getTempoAtEventBPM() << " BPM" << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::TimeSignature)
			{
				txtFile << "                TIME SIGNATURE              " <<
					getTrack(i)->getEvent(j)->getTimeSignature()[0] <<
					"/" << getTrack(i)->getEvent(j)->getTimeSignature()[1] << std::endl << std::endl;
			}

			else if (getTrack(i)->getEvent(j)->getSpecificType() == SpecificType::KeySignature)
			{
				txtFile << "                KEY SIGNATURE               " <<
					getTrack(i)->getEvent(j)->getKeySignature() << std::endl << std::endl;
			}

			else
			{
				txtFile << "NOT AN EVENT!" << std::endl;
			}
		}

		txtFile << std::endl;
	}
}