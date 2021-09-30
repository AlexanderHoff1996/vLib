#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#include "MidiTrack1.h"
#include "SharedData1.h"

namespace vmidi {   // Beginning of vmidi namespace
//=============================================================================

class MidiFileData
{
public:
	MidiFileData();
	~MidiFileData();

	void					addData(std::vector<uint8_t> theData);
	std::vector<uint8_t>&	getData();

	std::vector<uint8_t>	getHeaderIdentifier();
	uint32_t				getHeaderLength();
	uint16_t				getFormat();
	uint16_t				getNumOfTracks();
	uint16_t				getDivision();
	std::string				getTiming();
	float					getCurrentTime();

	// Get all the header data and populate the private variables below
	void getHeaderFromData(std::vector<uint8_t>::iterator position);

	// The length of a track
	// From "MTrk", to the character right before the next "MTrk",
	// or until the end of the file
	uint32_t getTrackLengthFromData(std::vector<uint8_t>::iterator position);

private:
	// All data will be stored in this vector
	std::vector<uint8_t> data;

	// All headers start with an identifer (the 4 bytes 'M', 'T', 'h', and 'd')
	std::vector<uint8_t> headerIdentifier;
	
	// Number of bytes the header uses (after the first 8 bytes (MThd and chunklength))
	// Since a header chunk is 14 bytes (for now), this will be the following 6 bytes
	// It will still be read, since it might change in the future
	uint32_t headerLength {6};

	// The following three values should be 2 byte (16 bit) values

	// The format of the midi file (0, 1 or 2)
	uint16_t format {0};

	// The number of tracks in the midi file
	uint16_t numOfTracks {0};

	// Division (timing)
	uint16_t division {0};

	// Metrical (bar.beat) or timecode (hrs.mins.secs.frames)
	std::string timing;

	// This will be increased with every delta time that is not 0
	float currentTime {0.f};
};


//=============================================================================
class MidiFile
{
public:
	MidiFile(std::string path);
	~MidiFile();

	// Get the format of the midi file (0, 1 or 2)
	int getFormat();

	// Get the division of the midi file (0 or 1)
	int getDivision();
	
	// Get the timing (metrical or timecode)
	std::string getTiming();

	size_t getNumTracks();

	std::string getSequenceName();

	float getTotalTimeInMs();
	std::vector<int> getTotalTime();

	vmidi::MidiTrack* getTrack(int n);
	vmidi::MidiTrack* getFirstTrack();
	vmidi::MidiTrack* getFinalTrack();

	void saveDataToTextFile();

private:
	MidiFileData data;

	// Loop through the midi data
	void loopThroughData();

	// Get all the data from the midi file
	std::vector<uint8_t> getDataFromFile();

	// The midi file
	std::ifstream file {"", std::ios::binary};
	std::string filename;

	// To open the file for reading
	void open();

	// Check that it's a valid midi file
	bool isValid();

	void calculateTotalTime();
	float totalTimeInMs {0};
	std::vector<int> totalTime {0, 0, 0};	// min, s, ms

	// This vector stores all the midi tracks
	std::vector<std::unique_ptr<MidiTrack>> tracks;
};

//=============================================================================
}   // End of vmidi namespace