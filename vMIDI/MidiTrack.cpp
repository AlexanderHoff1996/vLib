#include "MidiTrack.h"

//=============================================================================
vMIDI::MidiTrack::MidiTrack()
{

}

vMIDI::MidiTrack::~MidiTrack()
{

}

//=============================================================================
vMIDI::MidiEvent* vMIDI::MidiTrack::getEvent(unsigned int n)
{
	return events[n].get();
}

vMIDI::MidiEvent* vMIDI::MidiTrack::getFirstEvent()
{
	return events[0].get();
}

vMIDI::MidiEvent* vMIDI::MidiTrack::getFinalEvent()
{
	return events[events.size() - 1].get();
}

//=============================================================================
size_t vMIDI::MidiTrack::getNumEvents()
{
	return events.size();
}

std::string vMIDI::MidiTrack::getTrackName()
{
	return trackName;
}

//=============================================================================
void vMIDI::MidiTrack::setTrackName(std::string trackName)
{
	this->trackName = trackName;
}

//=============================================================================
void vMIDI::MidiTrack::addEvent()
{
	events.push_back(std::make_unique<MidiEvent>());
}