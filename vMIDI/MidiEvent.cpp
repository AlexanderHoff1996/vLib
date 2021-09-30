#include "MidiEvent.h"

//=============================================================================
vMIDI::MidiEvent::MidiEvent()
{

}

vMIDI::MidiEvent::~MidiEvent()
{

}

//=============================================================================
uint32_t vMIDI::MidiEvent::getDeltaTime()
{
	return deltaTime;
}

vMIDI::Type vMIDI::MidiEvent::getType()
{
	return type;
}

std::string vMIDI::MidiEvent::getTypeName()
{
	return typeName;
}

vMIDI::SpecificType vMIDI::MidiEvent::getSpecificType()
{
	return specificType;
}

std::string vMIDI::MidiEvent::getSpecificTypeName()
{
	return specificTypeName;
}

//=============================================================================
int vMIDI::MidiEvent::getChannel()
{
	return channel;
}

vMIDI::Note vMIDI::MidiEvent::getNote()
{
	return note;
}

int vMIDI::MidiEvent::getNoteNumber()
{
	return noteNumber;
}

std::string vMIDI::MidiEvent::getNoteName()
{
	return noteName;
}

int vMIDI::MidiEvent::getVelocity()
{
	return velocity;
}

int vMIDI::MidiEvent::getPressure()
{
	if (pressure)
		return *pressure;

	else
		return 0;
}

std::string vMIDI::MidiEvent::getController()
{
	if (controller)
		return *controller;

	else
		return "";
}

int vMIDI::MidiEvent::getControllerValue()
{
	if (controllerValue)
		return *controllerValue;

	else
		return 0;
}

int vMIDI::MidiEvent::getProgram()
{
	if (program)
		return *program;

	else
		return 0;
}

uint16_t vMIDI::MidiEvent::getPitchBend()
{
	if (pitchBend)
		return *pitchBend;

	else
		return 0;
}

uint16_t vMIDI::MidiEvent::getSequenceNumber()
{
	if (sequenceNumber)
		return *sequenceNumber;

	else
		return 0;
}

std::string vMIDI::MidiEvent::getText()
{
	if (text)
		return *text;

	else
		return "";
}

std::string vMIDI::MidiEvent::getCopyright()
{ 
	if (copyright)
		return *copyright;

	else
		return "";
}

std::string vMIDI::MidiEvent::getTrackName()
{
	if (trackName)
		return *trackName;

	else
		return "";
}

std::string vMIDI::MidiEvent::getInstrumentName()
{
	if (instrumentName)
		return *instrumentName;

	else
		return "";
}

std::string vMIDI::MidiEvent::getLyric()
{
	if (lyric)
		return *lyric;

	else
		return "";
}

std::string vMIDI::MidiEvent::getMarker()
{
	if (marker)
		return *marker;

	else
		return "";
}

std::string vMIDI::MidiEvent::getCuePoint()
{
	if (cuePoint)
		return *cuePoint;

	else
		return "";
}
std::string vMIDI::MidiEvent::getProgramName()
{
	if (programName)
		return *programName;

	else
		return "";
}

std::string vMIDI::MidiEvent::getDeviceName()
{
	if (deviceName)
		return *deviceName;

	else
		return "";
}

int vMIDI::MidiEvent::getMidiChannelPrefix()
{
	if (midiChannelPrefix)
		return *midiChannelPrefix;

	else
		return 0;
}

int vMIDI::MidiEvent::getMidiPort()
{
	if (midiPort)
		return *midiPort;

	else
		return 0;
}

float vMIDI::MidiEvent::getTempo()
{
	if (tempo)
		return *tempo;

	else
		return 0.0f;
}

std::vector<uint32_t> vMIDI::MidiEvent::getSMPTEOffset()
{
	if (smpteOffset)
		return *smpteOffset;

	else
	{
		std::vector<uint32_t> empty;
		return empty;
	}
}

std::vector<uint32_t> vMIDI::MidiEvent::getTimeSignature()
{
	if (timeSignature)
		return *timeSignature;

	else
	{
		std::vector<uint32_t> empty;
		return empty;
	}
}

std::string vMIDI::MidiEvent::getKeySignature()
{
	if (keySignature)
		return *keySignature;

	else
		return "";
}

std::vector<uint32_t> vMIDI::MidiEvent::getSequencerSpecificEvent()
{
	if (sequencerSpecificEvent)
		return *sequencerSpecificEvent;

	else
	{
		std::vector<uint32_t> empty;
		return empty;
	}
}

//=============================================================================
float vMIDI::MidiEvent::getTempoAtEvent()
{
	return TempoTrack::getTempoAtTime(timestamp);
}

float vMIDI::MidiEvent::getTempoAtEventBPM()
{
	return TempoTrack::getTempoAtTimeBPM(timestamp);
}

float vMIDI::MidiEvent::getTimePerPPQN()
{
	return timePerPPQN;
}

float vMIDI::MidiEvent::getDeltaTimeInMs()
{
	return deltaTimeInMs;
}

float vMIDI::MidiEvent::getDeltaTimeInS()
{
	return deltaTimeInS;
}

float vMIDI::MidiEvent::getTimestamp()
{
	return timestamp;
}

float vMIDI::MidiEvent::getTimestampInMs()
{
	return timestampInMs;
}

float vMIDI::MidiEvent::getTimestampInS()
{
	return timestampInS;
}

//=============================================================================
bool vMIDI::MidiEvent::getRunningStatus()
{
	return runningStatus;
}

//=============================================================================
void vMIDI::MidiEvent::setDeltaTime(uint32_t deltaTime)
{
	this->deltaTime = deltaTime;
}

void vMIDI::MidiEvent::setType(Type type)
{
	this->type = type;
}

void vMIDI::MidiEvent::setTypeName(std::string typeName)
{
	this->typeName = typeName;
}

void vMIDI::MidiEvent::setSpecificType(SpecificType specificType)
{
	this->specificType = specificType;
}

void vMIDI::MidiEvent::setSpecificTypeName(std::string specificTypeName)
{
	this->specificTypeName = specificTypeName;
}

//=============================================================================
void vMIDI::MidiEvent::setChannel(uint8_t channel)
{
	this->channel = channel;
}

void vMIDI::MidiEvent::setNote(Note note)
{
	this->note = note;
}

void vMIDI::MidiEvent::setNoteNumber(uint8_t noteNumber)
{
	this->noteNumber = noteNumber;
}

void vMIDI::MidiEvent::setNoteName(std::string noteName)
{
	this->noteName = noteName;
}

void vMIDI::MidiEvent::setVelocity(uint8_t velocity)
{
	this->velocity = velocity;
}

void vMIDI::MidiEvent::setPressure(uint8_t pressure)
{
	this->pressure = std::make_unique<uint8_t>(pressure);
}

void vMIDI::MidiEvent::setController(std::string controller)
{
	this->controller = std::make_unique<std::string>(controller);
}

void vMIDI::MidiEvent::setControllerValue(uint8_t controllerValue)
{
	this->controllerValue = std::make_unique<uint8_t>(controllerValue);
}

void vMIDI::MidiEvent::setProgram(uint8_t program)
{
	this->program = std::make_unique<uint8_t>(program);
}

void vMIDI::MidiEvent::setPitchBend(uint16_t pitchBend)
{
	this->pitchBend = std::make_unique<uint16_t>(pitchBend);
}

void vMIDI::MidiEvent::setSequenceNumber(uint16_t sequenceNumber)
{
	this->sequenceNumber = std::make_unique<uint16_t>(sequenceNumber);
}

void vMIDI::MidiEvent::setText(std::string text)
{
	this->text = std::make_unique<std::string>(text);
}

void vMIDI::MidiEvent::setCopyright(std::string copyright)
{
	this->copyright = std::make_unique<std::string>(copyright);
}

void vMIDI::MidiEvent::setTrackName(std::string trackName)
{
	this->trackName = std::make_unique<std::string>(trackName);
}

void vMIDI::MidiEvent::setInstrumentName(std::string instrumentName)
{
	this->instrumentName = std::make_unique<std::string>(instrumentName);
}

void vMIDI::MidiEvent::setLyric(std::string lyric)
{
	this->lyric = std::make_unique<std::string>(lyric);
}

void vMIDI::MidiEvent::setMarker(std::string marker)
{
	this->marker = std::make_unique<std::string>(marker);
}

void vMIDI::MidiEvent::setCuePoint(std::string cuePoint)
{
	this->cuePoint = std::make_unique<std::string>(cuePoint);
}

void vMIDI::MidiEvent::setProgramName(std::string programName)
{
	this->programName = std::make_unique<std::string>(programName);
}

void vMIDI::MidiEvent::setDeviceName(std::string deviceName)
{
	this->deviceName = std::make_unique<std::string>(deviceName);
}

void vMIDI::MidiEvent::setMidiChannelPrefix(uint8_t midiChannelPrefix)
{
	this->midiChannelPrefix = std::make_unique<uint8_t>(midiChannelPrefix);
}

void vMIDI::MidiEvent::setMidiPort(uint8_t midiPort)
{
	this->midiPort = std::make_unique<uint8_t>(midiPort);
}

void vMIDI::MidiEvent::setTempo(float tempo)
{
	this->tempo = std::make_unique<float>(tempo);
}

void vMIDI::MidiEvent::setSMPTEOffset(std::vector<uint32_t> smpteOffset)
{
	this->smpteOffset = std::make_unique<std::vector<uint32_t>>(smpteOffset);
}

void vMIDI::MidiEvent::setTimeSignature(std::vector<uint32_t> timeSignature)
{
	this->timeSignature = std::make_unique<std::vector<uint32_t>>(timeSignature);
}

void vMIDI::MidiEvent::setKeySignature(std::string keySignature)
{
	this->keySignature = std::make_unique<std::string>(keySignature);
}

void vMIDI::MidiEvent::setSequencerSpecificEvent(
	std::vector<uint32_t> sequencerSpecificEvent)
{
	this->sequencerSpecificEvent = std::make_unique<
		std::vector<uint32_t>>(sequencerSpecificEvent);
}

//=============================================================================
void vMIDI::MidiEvent::setTempoAtEvent(float tempoAtEvent)
{
	this->tempoAtEvent = tempoAtEvent;
}

void vMIDI::MidiEvent::setTempoAtEventBPM(float tempoAtEventBPM)
{
	this->tempoAtEventBPM = tempoAtEventBPM;
}

void vMIDI::MidiEvent::setTimePerPPQN(float timePerPPQN)
{
	this->timePerPPQN = timePerPPQN;
}

void vMIDI::MidiEvent::setDeltaTimeInMs(float deltaTimeInMs)
{
	this->deltaTimeInMs = deltaTimeInMs;
}

void vMIDI::MidiEvent::setDeltaTimeInS(float deltaTimeInS)
{
	this->deltaTimeInS = deltaTimeInS;
}

void vMIDI::MidiEvent::setTimestamp(float timestamp)
{
	this->timestamp = timestamp;
}

void vMIDI::MidiEvent::setTimestampInMs(float timestampInMs)
{
	this->timestampInMs = timestampInMs;
}

void vMIDI::MidiEvent::setTimestampInS(float timestampInS)
{
	this->timestampInS = timestampInS;
}

//=============================================================================
void vMIDI::MidiEvent::setRunningStatus(bool runningStatus)
{
	this->runningStatus = runningStatus;
}