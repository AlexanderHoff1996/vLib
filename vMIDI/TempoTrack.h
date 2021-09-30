#pragma once

#include "TempoChange.h"

#include <string>
#include <vector>
#include <memory>

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
struct TempoTrack
{
	static float getTempoAtTime(float time)
	{
		float tempo {0.f};

		for (auto& iter : tempoChanges)
		{
			if (time >= iter->getStartTime() &&
				time <= iter->getEndTime())
			{
				tempo = iter->getTempo();
				break;
			}
		}

		return tempo;
	}

	static float getTempoAtTimeBPM(float time)
	{
		float tempo {0.f};

		for (auto& iter : tempoChanges)
		{
			if (time >= iter->getStartTime() &&
				time <= iter->getEndTime())
			{
				tempo = iter->getTempoBPM();
				break;
			}
		}

		return tempo;
	}

	//=============================================================================
	// Timestamp in ms =

	// startTimeOfCurrentTempoInMs +
	// (((timestamp - startTimeOfCurrentTempo) * timePerPPQN) / 1000)

	static float getTimeInMs(float time)
	{
		float timeInMs {0.f};

		for (auto& iter : tempoChanges)
		{
			if (time >= iter->getStartTime() &&
				time <= iter->getEndTime())
			{
				timeInMs = (iter->getStartTimeMs() +
					(((time - iter->getStartTime()) *
					iter->getTimePerPPQN()) / 1000));
				break;
			}
		}

		return timeInMs;
	}

	//=============================================================================
	// Tempo changes
	static inline std::vector<std::unique_ptr<TempoChange>> tempoChanges;
};

//  _______________
// | NAMESPACE END |
//  ***************
}