#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <iostream>

#include "SharedData.h"

namespace vmidi {   // Beginning of vmidi namespace
//=============================================================================

class MidiEventData
{
public:
	MidiEventData();
	~MidiEventData();

	void					addData(std::vector<uint8_t>& trackData);
	std::vector<uint8_t>&	getData();

	void					setLength(std::vector<uint32_t>& eventLength);
	std::vector<uint32_t>&	getLength();

	void					setDeltaTime(std::vector<uint32_t> eventDeltaTime);
	std::vector<uint32_t>	getDeltaTime();
	
	void					setType(std::string eventType);
	std::string				getType();
	
	void					setSpecificType(std::string specificEventType);
	std::string				getSpecificType();
	
	void					setFormat(uint16_t midiFormat);
	uint16_t				getFormat();
	
	void					setDivision(uint16_t midiDivision);
	uint16_t				getDivision();

	void					setTiming(std::string midiTiming);
	std::string				getTiming();

	void					setTrackNumber(int trackN);
	int						getTrackNumber();

	void					setCurrentTempo(float currTempo);
	float					getCurrentTempo();

	void					setCurrentTime(float currTime);
	float					getCurrentTime();

	void		getChannelFromData(std::vector<uint8_t>::iterator position);
	void		getChannelFromData(uint8_t runningStatusByte);
	void		getNoteFromData(std::vector<uint8_t>::iterator position);
	void		getVelocityFromData(std::vector<uint8_t>::iterator position);
	void		getPressureFromData(std::vector<uint8_t>::iterator position);
	void		getControllerFromData(std::vector<uint8_t>::iterator position);
	void		getControllerValueFromData(std::vector<uint8_t>::iterator position);
	void		getProgramFromData(std::vector<uint8_t>::iterator position);
	void		getPitchBendFromData(std::vector<uint8_t>::iterator position);

	void		getSequenceNumberFromData(std::vector<uint8_t>::iterator position);
	void		getTextFromData(std::vector<uint8_t>::iterator position);
	void		getCopyrightFromData(std::vector<uint8_t>::iterator position);
	void		getTrackNameFromData(std::vector<uint8_t>::iterator position);
	void		getInstrumentNameFromData(std::vector<uint8_t>::iterator position);
	void		getDeviceNameFromData(std::vector<uint8_t>::iterator position);
	void		getEndOfTrackFromData(std::vector<uint8_t>::iterator position);
	void		getSMPTEOffsetFromData(std::vector<uint8_t>::iterator position);

	void		getLyricFromData(std::vector<uint8_t>::iterator position);
	void		getMarkerFromData(std::vector<uint8_t>::iterator position);
	void		getCuePointFromData(std::vector<uint8_t>::iterator position);
	void		getProgramNameFromData(std::vector<uint8_t>::iterator position);
	void		getMidiChannelPrefixFromData(std::vector<uint8_t>::iterator position);
	void		getMidiPortFromData(std::vector<uint8_t>::iterator position);
	void		getTempoFromData(std::vector<uint8_t>::iterator position);
	void		getTimeSignatureFromData(std::vector<uint8_t>::iterator position);
	void		getKeySignatureFromData(std::vector<uint8_t>::iterator position);
	void		getSequencerSpecificEventFromData(std::vector<uint8_t>::iterator position);

	int						getChannel();
	int						getNoteNumber();
	std::string				getNoteName();
	int						getVelocity();
	int						getPressure();
	std::string				getController();
	int						getControllerValue();
	int						getProgram();
	int						getPitchBend();
	int						getSequenceNumber();
	std::string				getText();
	std::string				getCopyright();
	std::string				getTrackName();
	std::string				getInstrumentName();
	std::string				getDeviceName();
	int						getEndOfTrack();
	int						getSMPTEOffset();
	std::string				getLyric();
	int						getMarker();
	int						getCuePoint();
	std::string				getProgramName();
	int						getMidiChannelPrefix();
	int						getMidiPort();
	int						getTempo();
	std::vector<uint32_t>	getTimeSignature();
	std::string				getKeySignature();
	int						getSequencerSpecificEvent();

private:
	// All data will be stored in this vector
	std::vector<uint8_t> data;

	// The delta time of the event
	// [deltatime, bytes]
	std::vector<uint32_t> deltaTime;

	// The type of event (midi, meta, sysex)
	std::string type;

	// The specific event type (note on, note off, track name, etc)
	std::string specificType;

	// 0. Total event length (excluding delta time),
	// 1. Variable length (only some events)
	// 2. Number of bytes 1. uses (only some events)
	std::vector<uint32_t> length;

	// The format of the midi file (0, 1 or 2)
	uint16_t format {0};

	// Division (timing)
	uint16_t division {0};

	// Metrical (bar.beat) or timecode (hrs.mins.secs.frames)
	std::string timing;

	// Which track this event is on
	int trackNumber {0};

	float currentTime  {0};
	float currentTempo {0};

	int										channel					{0};
	int										noteNumber				{0};	
	std::string								noteName				{0};	
	int										velocity				{0};
	std::unique_ptr<int>					pressure				{nullptr};
	std::unique_ptr<std::string>			controller				{nullptr};
	std::unique_ptr<int>					controllerValue			{nullptr};
	std::unique_ptr<int>					program					{nullptr};
	std::unique_ptr<int>					pitchBend				{nullptr};
	std::unique_ptr<int>					sequenceNumber			{nullptr};
	std::unique_ptr<std::string>			text					{nullptr};
	std::unique_ptr<std::string>			copyright				{nullptr};
	std::unique_ptr<std::string>			trackName				{nullptr};
	std::unique_ptr<std::string>			instrumentName			{nullptr};
	std::unique_ptr<std::string>			deviceName				{nullptr};
	std::unique_ptr<int>					endOfTrack				{nullptr};
	std::unique_ptr<int>					smpteOffset				{nullptr};
	std::unique_ptr<std::string>			lyric					{nullptr};
	std::unique_ptr<int>					marker					{nullptr};
	std::unique_ptr<int>					cuePoint				{nullptr};
	std::unique_ptr<std::string>			programName				{nullptr};
	std::unique_ptr<int>					midiChannelPrefix		{nullptr};
	std::unique_ptr<int>					midiPort				{nullptr};
	std::unique_ptr<int>					tempo					{nullptr};
	std::unique_ptr<std::vector<uint32_t>>	timeSignature			{nullptr};
	std::unique_ptr<std::string>			keySignature			{nullptr};
	std::unique_ptr<int>					sequencerSpecificEvent	{nullptr};
};


//=============================================================================
class MidiEvent
{
public:
	MidiEvent(std::vector<uint8_t>& eventData, std::vector<uint32_t>& eventLength,
		std::vector<uint32_t>& eventDeltaTime, std::string& eventType,
		std::string& specificEventType);
	
	~MidiEvent();

	// The delta time (time since last event, or 0 if beginning) of the event
	uint32_t getDeltaTime();

	// The type of event (midi, meta, sysex)
	std::string getType();

	// The the specific event type (note on, note off, track name, etc)
	std::string getSpecificType();

	// The length of the event
	uint32_t getLength();

	float					getCurrentTempo();
	float					getCurrentTempoInBPM();
	float					getTimePerPPQN();
	float					getDeltaTimeInMs();
	float					getDeltaTimeInS();
	float					getTimestamp();
	float					getTimestampInMs();
	float					getTimestampInS();
	int						getChannel();
	int						getNoteNumber();
	std::string				getNoteName();
	int						getVelocity();
	int						getPressure();
	std::string				getController();
	int						getControllerValue();
	int						getProgram();
	int						getPitchBend();
	int						getSequenceNumber();
	std::string				getText();
	std::string				getCopyright();
	std::string				getTrackName();
	std::string				getInstrumentName();
	std::string				getDeviceName();
	int						getEndOfTrack();
	int						getSMPTEOffset();
	std::string				getLyric();
	int						getMarker();
	int						getCuePoint();
	std::string				getProgramName();
	int						getMidiChannelPrefix();
	int						getMidiPort();
	float					getTempo();
	std::vector<uint32_t>	getTimeSignature();
	std::string				getKeySignature();
	int						getSequencerSpecificEvent();

private:
	MidiEventData data;

	// Go through the event data
	void goThroughData();

	void calculateTempoInBPM(float& tempoValue);
	void calculateTimePerPPQN();
	void calculateDeltaTimeInS();
	void calculateDeltaTimeInMs();
	void calculateTimestampInMs();
	void calculateTimestampInS();

	float currentTempoInBPM	{0.f};
	float timePerPPQN		{0.f};
	float deltaTimeInMs		{0.f};
	float deltaTimeInS		{0.f};
	float timestampInMs		{0.f};
	float timestampInS		{0.f};
	float tempo				{0.f};
};

//=============================================================================
}   // End of vmidi namespace
