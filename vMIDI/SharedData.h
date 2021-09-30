#pragma once

#include <cstdint>
#include <string>

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class SharedData
{
public:
	static uint16_t		getFormat()			{return format;}
	static uint16_t		getNumberOfTracks()	{return numberOfTracks;}
	static uint16_t		getTiming()			{return timing;}
	static std::string	getTimingType()		{return timingType;}
	static std::string	getSequenceName()	{return sequenceName;}
	static std::string	getCopyright()		{return copyright;}
	static std::string	getDeviceName()		{return deviceName;}

	static void setFormat			(uint16_t frmt)			{format = frmt;}
	static void setNumberOfTracks	(uint16_t ntrks)		{numberOfTracks = ntrks;}
	static void setTiming			(uint16_t timng)		{timing = timng;}
	static void setTimingType		(std::string timngType)	{timingType = timngType;}
	static void setSequenceName		(std::string seqName)	{sequenceName = seqName;}
	static void setCopyright		(std::string copyrght)	{copyright = copyrght;}
	static void setDeviceName		(std::string devName)	{deviceName = devName;}

private:
	static inline uint16_t		format			{0};
	static inline uint16_t		numberOfTracks	{0};
	static inline uint16_t		timing			{0};
	static inline std::string	timingType;
	static inline std::string	sequenceName;
	static inline std::string	copyright;
	static inline std::string	deviceName;
};

//  _______________
// | NAMESPACE END |
//  ***************
}