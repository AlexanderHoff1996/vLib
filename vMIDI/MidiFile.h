#pragma once

#include "File.h"
#include "Data.h"
#include "Types.h"
#include "MidiTrack.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class MidiFile
{
public:
	MidiFile(std::string path);
	~MidiFile();
	
	MidiTrack* getTrack(unsigned int n);
	MidiTrack* getFirstTrack();
	MidiTrack* getFinalTrack();

	int getFormat();
	int getTiming();

	size_t getNumTracks();
	
	std::string	getTimingType();
	std::string	getSequenceName();

	float getTotalTimeInMs();
	std::vector<int> getTotalTime();

	void saveDataToTextFile();
	void saveDataToTextFile(std::string filename);

private:
	File file;

	void calculateTotalTime();
	float totalTimeInMs {0};
	std::vector<int> totalTime {0, 0, 0};	// min, s, ms

	void writeToTextFile(std::string filename);

	std::vector<std::unique_ptr<MidiTrack>> tracks;
};

//  _______________
// | NAMESPACE END |
//  ***************
}