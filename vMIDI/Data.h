#pragma once

#include "MidiFile.h"
#include "MidiTrack.h"
#include "MidiEvent.h"

#include "File.h"
#include "SharedData.h"
#include "TempoTrack.h"
#include "TempoChange.h"

#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
struct Data
{
	static void getFromFile(File& file);
	static void setSharedData();
	static void writeToTracks(std::vector<std::unique_ptr<MidiTrack>>& trks);

	//=============================================================================
	// Data

	static inline std::vector<uint8_t> data;				// Stores data of whole midi file
	static inline std::vector<uint8_t>::iterator position;	// Iterator to a byte in data

	static inline std::vector<std::unique_ptr<MidiTrack>>* tracks {nullptr};

	//=============================================================================
	static void header();
	static void track(int trackNumber);

	// Current time in microseconds,
	// This will be updated every event
	static inline float currentTime {0.f};

	// These will be updated every event
	static inline uint8_t statusByte	 {0};
	static inline uint8_t prevStatusByte {0};
	static inline std::vector<uint32_t> deltaTimeVector;

	//=============================================================================
	static std::vector<uint32_t> getDeltaTimeOrLength();
	static int getVariableLengthQuantity();
	static float getTimePerPPQN(float tempoValue);
	static float getTempoInBPM(float tempoValue);
	static std::string getNoteName();

	static void setEventTime();

	//=============================================================================
	static void noteOff();
	static void noteOn();
	static void polyphonicPressure();
	static void controller();
	static void programChange();
	static void channelPressure();
	static void pitchBend();
	
	static void singleSysex();
	static void escapeSequence();
	
	static void sequenceNumber();
	static void text();
	static void copyright();
	static void sequenceOrTrackName(int trackNumber);
	static void instrumentName();
	static void lyric();
	static void marker();
	static void cuePoint();
	static void programName();
	static void deviceName();
	static void midiChannelPrefix();
	static void midiPort();
	static void endOfTrack();
	static void tempo();
	static void smpteOffset();
	static void timeSignature();
	static void keySignature();
	static void sequencerSpecificEvent();
	
};

//  _______________
// | NAMESPACE END |
//  ***************
}