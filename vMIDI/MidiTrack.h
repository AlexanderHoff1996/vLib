#pragma once

#include "MidiEvent.h"

#include <string>
#include <vector>

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class MidiTrack
{
public:

	MidiTrack();
	~MidiTrack();

	MidiEvent* getEvent(unsigned int n);
	MidiEvent* getFirstEvent();
	MidiEvent* getFinalEvent();

	size_t getNumEvents();
	std::string getTrackName();
	
	void setTrackName(std::string trackName);

	void addEvent();

private:
	int trackNumber {0};
	std::string trackName;

	std::vector<std::unique_ptr<MidiEvent>> events;
};

//  _______________
// | NAMESPACE END |
//  ***************
}