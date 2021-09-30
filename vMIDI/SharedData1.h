#pragma once

#include <string>

namespace vmidi {   // Beginning of vmidi namespace
//=============================================================================

class SharedData
{
public:
	static void			setFormat(uint16_t midiFormat)		{format = midiFormat;}
	static uint16_t		getFormat()							{return format;}

	static void			setNumOfTracks(uint16_t nOfTracks)	{numOfTracks = nOfTracks;}
	static uint16_t		getNumOfTracks()					{return numOfTracks;}

	static void			setDivision(uint16_t midiDivision)	{division = midiDivision;}
	static uint16_t		getDivision()						{return division;}

	static void			setTiming(std::string midiTiming)	{timing = midiTiming;}
	static std::string	getTiming()							{return timing;}

	static void			setCurrentTempo(float currTempo)	{currentTempo = currTempo;}
	static float		getCurrentTempo()					{return currentTempo;}

	static void			setCurrentTime(float currTime)		{currentTime = currTime;}
	static void			addToCurrentTime(float currTime)	{currentTime += currTime;}
	static float		getCurrentTime()					{return currentTime;}

	static void			setTrackNumber(int n)				{trackNumber = n;}
	static int			getTrackNumber()					{return trackNumber;}

	static void			setRunningStatus(int status)		{runningStatus = status;}
	static uint8_t		getRunningStatus()					{return runningStatus;}

	static void			setSequenceName(std::string name)	{sequenceName = name;}
	static std::string	getSequenceName()					{return sequenceName;}

	static void			setCopyright(std::string copyr)		{copyright = copyr;}
	static std::string	getCopyright()						{return copyright;}

	static void			setDeviceName(std::string name)		{deviceName = name;}
	static std::string	getDeviceName()						{return deviceName;}

private:
	inline static uint16_t		format			{0};
	inline static uint16_t		numOfTracks		{0};
	inline static uint16_t		division		{0};
	inline static std::string	timing;

	inline static float			currentTempo	{0.f};
	inline static float			currentTime		{0.f};

	inline static int			trackNumber		{0};
	
	inline static uint8_t		runningStatus	{0};
	
	inline static std::string	sequenceName;
	inline static std::string	copyright;
	inline static std::string	deviceName;
};

//=============================================================================
}   // End of vmidi namespace
