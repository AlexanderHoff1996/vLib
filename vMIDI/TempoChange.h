#pragma once

#include <limits>

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class TempoChange
{
public:
	TempoChange(float tempo, float tempoBPM, float timePerPPQN,
		float startTime, float startTimeMs)
	{
		this->tempo			= tempo;
		this->tempoBPM		= tempoBPM;
		this->timePerPPQN	= timePerPPQN;
		this->startTime		= startTime;
		this->startTimeMs	= startTimeMs;
		this->startTimeS	= startTimeMs / 1000;
	}

	void setEndTime(float endTime)
	{
		this->endTime = endTime;
	}

	void setEndTimeMs(float endTimeMs)
	{
		this->endTimeMs = endTimeMs;
	}

	void setTimePerPPQN(float timePerPPQN)
	{
		this->timePerPPQN = timePerPPQN;
	}

	float getTempo()		{return tempo;}
	float getTempoBPM()		{return tempoBPM;}
	float getTimePerPPQN()	{return timePerPPQN;}
	float getStartTime()	{return startTime;}
	float getEndTime()		{return endTime;}
	float getStartTimeMs()	{return startTimeMs;}
	float getEndTimeMs()	{return endTimeMs;}
	float getStartTimeS()	{return startTimeS;}
	float getEndTimeS()		{return endTimeS;}

private:
	// Tempo in microseconds per quarter note
	float tempo {0.f};

	// Tempo in Beats Per Minute
	float tempoBPM {0.f};

	// Time per Pulses Per Quarter Note
	float timePerPPQN {0.f};

	// Start time (use currentTime in Data)
	float startTime {0.f};

	// End time (use currentTime - 1 in Data)
	// It's initialized with the largest possible value
	// in case there is only one tempo change,
	// and endTime never gets set
	float endTime {std::numeric_limits<float>::max()};

	// Start and end times in milliseconds
	float startTimeMs {0.f};
	float endTimeMs {std::numeric_limits<float>::max()};

	// Start and end times in seconds
	float startTimeS {0.f};
	float endTimeS {std::numeric_limits<float>::max()};
};

//  _______________
// | NAMESPACE END |
//  ***************
}