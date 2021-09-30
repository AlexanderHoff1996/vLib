#pragma once

#include "TempoTrack.h"
#include "Types.h"
#include "Notes.h"

#include <string>
#include <vector>
#include <iostream>

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class MidiEvent
{
public:
	MidiEvent();
	~MidiEvent();

	//=============================================================================
	// The delta time (time since last event, or 0 if beginning) of the event
	uint32_t getDeltaTime();

	// The type of event (midi, meta, sysex)
	Type getType();
	std::string getTypeName();

	// The specific event type (note on, note off, track name, etc)
	SpecificType getSpecificType();
	std::string getSpecificTypeName();

	int						getChannel();
	Note					getNote();
	int						getNoteNumber();
	std::string				getNoteName();
	int						getVelocity();
	int						getPressure();
	std::string				getController();
	int						getControllerValue();
	int						getProgram();
	uint16_t				getPitchBend();
	uint16_t				getSequenceNumber();
	std::string				getText();
	std::string				getCopyright();
	std::string				getTrackName();
	std::string				getInstrumentName();
	std::string				getLyric();
	std::string				getMarker();
	std::string				getCuePoint();
	std::string				getProgramName();
	std::string				getDeviceName();
	int						getMidiChannelPrefix();
	int						getMidiPort();
	float					getTempo();
	std::vector<uint32_t>	getSMPTEOffset();
	std::vector<uint32_t>	getTimeSignature();
	std::string				getKeySignature();
	std::vector<uint32_t>	getSequencerSpecificEvent();

	float					getTempoAtEvent();
	float					getTempoAtEventBPM();
	float					getTimePerPPQN();
	float					getDeltaTimeInMs();
	float					getDeltaTimeInS();
	float					getTimestamp();
	float					getTimestampInMs();
	float					getTimestampInS();

	bool					getRunningStatus();

	//=============================================================================
	void setDeltaTime				(uint32_t deltaTime);
	
	void setType					(Type type);
	void setTypeName				(std::string typeName);
	void setSpecificType			(SpecificType specificType);
	void setSpecificTypeName		(std::string specificTypeName);

	void setChannel					(uint8_t channel);
	void setNote					(Note note);
	void setNoteNumber				(uint8_t noteNumber);
	void setNoteName				(std::string noteName);
	void setVelocity				(uint8_t velocity);
	void setPressure				(uint8_t pressure);
	void setController				(std::string controller);
	void setControllerValue			(uint8_t controllerValue);
	void setProgram					(uint8_t program);
	void setPitchBend				(uint16_t pitchBend);
	void setSequenceNumber			(uint16_t sequenceNumber);
	void setText					(std::string text);
	void setCopyright				(std::string copyright);
	void setTrackName				(std::string trackName);
	void setInstrumentName			(std::string instrumentName);
	void setLyric					(std::string lyric);
	void setMarker					(std::string marker);
	void setCuePoint				(std::string cuePoint);
	void setProgramName				(std::string programName);
	void setDeviceName				(std::string deviceName);
	void setMidiChannelPrefix		(uint8_t midiChannelPrefix);
	void setMidiPort				(uint8_t midiPort);
	void setTempo					(float tempo);
	void setSMPTEOffset				(std::vector<uint32_t> smpteOffset);
	void setTimeSignature			(std::vector<uint32_t> timeSignature);
	void setKeySignature			(std::string keySignature);
	void setSequencerSpecificEvent	(std::vector<uint32_t> sequencerSpecificEvent);

	void setTempoAtEvent			(float tempoAtEvent);
	void setTimePerPPQN				(float timePerPPQN);
	void setTempoAtEventBPM			(float tempoAtEventBPM);
	void setDeltaTimeInMs			(float deltaTimeInMs);
	void setDeltaTimeInS			(float deltaTimeInS);
	void setTimestamp				(float timestamp);
	void setTimestampInMs			(float timestampInMs);
	void setTimestampInS			(float timestampInS);
	
	void setRunningStatus			(bool runningStatus);

private:
	uint32_t								deltaTime				{0};

	Type									type					{Type::None};
	std::string								typeName;
	SpecificType							specificType			{SpecificType::None};
	std::string								specificTypeName;

	uint8_t									channel					{0};
	Note									note					{Note::None};
	uint8_t									noteNumber				{0};
	std::string								noteName				{0};
	uint8_t									velocity				{0};
	std::unique_ptr<uint8_t>				pressure				{nullptr};
	std::unique_ptr<std::string>			controller				{nullptr};
	std::unique_ptr<uint8_t>				controllerValue			{nullptr};
	std::unique_ptr<uint8_t>				program					{nullptr};
	std::unique_ptr<uint16_t>				pitchBend				{nullptr};
	std::unique_ptr<uint16_t>				sequenceNumber			{nullptr};
	std::unique_ptr<std::string>			text					{nullptr};
	std::unique_ptr<std::string>			copyright				{nullptr};
	std::unique_ptr<std::string>			trackName				{nullptr};
	std::unique_ptr<std::string>			instrumentName			{nullptr};
	std::unique_ptr<std::string>			lyric					{nullptr};
	std::unique_ptr<std::string>			marker					{nullptr};
	std::unique_ptr<std::string>			cuePoint				{nullptr};
	std::unique_ptr<std::string>			programName				{nullptr};
	std::unique_ptr<std::string>			deviceName				{nullptr};
	std::unique_ptr<uint8_t>				midiChannelPrefix		{nullptr};
	std::unique_ptr<uint8_t>				midiPort				{nullptr};
	std::unique_ptr<float>					tempo					{nullptr};
	std::unique_ptr<std::vector<uint32_t>>	smpteOffset				{nullptr};
	std::unique_ptr<std::vector<uint32_t>>	timeSignature			{nullptr};
	std::unique_ptr<std::string>			keySignature			{nullptr};
	std::unique_ptr<std::vector<uint32_t>>	sequencerSpecificEvent	{nullptr};

	float tempoAtEvent		{0.f};
	float tempoAtEventBPM	{0.f};
	float timePerPPQN		{0.f};
	float deltaTimeInMs		{0.f};
	float deltaTimeInS		{0.f};
	float timestamp			{0.0f};
	float timestampInMs		{0.f};
	float timestampInS		{0.f};

	bool runningStatus		{false};
};

//  _______________
// | NAMESPACE END |
//  ***************
}