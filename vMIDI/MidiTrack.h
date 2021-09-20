#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#include "MidiEvent.h"
#include "SharedData.h"

namespace vmidi {   // Beginning of vmidi namespace
//=============================================================================

class MidiTrackData
{
public:
	MidiTrackData();
	~MidiTrackData();

	void					addData(std::vector<uint8_t>& trackData);
	std::vector<uint8_t>&	getData();
	
	void					setLength(uint32_t& trackLength);
	uint32_t&				getLength();

	void					setFormat(uint16_t midiFormat);
	uint16_t				getFormat();
	
	void					setDivision(uint16_t midiDivision);
	uint16_t				getDivision();

	void					setTiming(std::string midiTiming);
	std::string				getTiming();

	void					setTrackNumber(int trackN);
	int						getTrackNumber();

	std::string				getTrackName();

	void					setCurrentTempo(float currTempo);
	float					getCurrentTempo();

	void getIdentifierFromData(std::vector<uint8_t>::iterator position);

	// The delta time or length of an event
	std::vector<uint32_t> getDeltaTimeOrLengthFromData(std::vector<uint8_t>::iterator position);

	// In some places "variable length quantites" are used
	// That's values consisting of anywhere from 1 to 4 bytes
	int getVariableLengthQuantity(std::vector<uint8_t>::iterator position);

	// The type of event (midi, meta, sysex)
	std::string getEventTypeFromData(std::vector<uint8_t>::iterator position);

	// The specific event type (note on, note off, track name, etc)
	std::string getSpecificEventTypeFromData(std::vector<uint8_t>::iterator position,
		std::string& eventType, std::vector<uint32_t>& deltaTime);

	// The length of an event
	std::vector<uint32_t> getEventLengthFromData(std::vector<uint8_t>::iterator position,
		std::string& specificEventType);

private:
	// All data will be stored in this vector
	std::vector<uint8_t> data;

	// All tracks start with an identifer (the 4 bytes 'M', 'T', 'r', and 'k')
	std::vector<uint8_t> identifier;

	// Length of track
	uint32_t length {0};

	// The format of the midi file (0, 1 or 2)
	uint16_t format {0};

	// Division (timing)
	uint16_t division {0};

	// Metrical (bar.beat) or timecode (hrs.mins.secs.frames)
	std::string timing;

	// Which track this is
	int trackNumber {0};

	// Name of the track
	std::string trackName;

	float currentTempo {0.f};
};


//=============================================================================
class MidiTrack
{
public:
	MidiTrack(std::vector<uint8_t>& trackData, uint32_t& trackLength);
	~MidiTrack();

	// Get the number of events in the track
	size_t getNumEvents();

	// Returns a pointer to midi event n in the track
	vmidi::MidiEvent* getEvent(int n);

	// Returns a pointer to the first midi event in the track 
	vmidi::MidiEvent* getFirstEvent();

	// Returns a pointer to the last (final) midi event in the track
	vmidi::MidiEvent* getFinalEvent();

	// Get the name of the track
	std::string getTrackName();

private:
	MidiTrackData data;

	// Loop through the track data
	void loopThroughData();

	// This vector stores all the midi events
	std::vector<std::unique_ptr<MidiEvent>> events;
};

//=============================================================================
}   // End of vmidi namespace
