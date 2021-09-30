#include "File.h"

//=============================================================================
std::ifstream& vMIDI::File::getStream() {return file;}

//=============================================================================
std::filesystem::path& vMIDI::File::getPath() {return filepath;}
void vMIDI::File::setPath(std::string path)   {filepath = path;}

//=============================================================================
void vMIDI::File::open()
{
	file.open(filepath, std::ios::binary);

	if (!file || filepath.extension() != ".mid")
		throw std::runtime_error("Error: File could not be loaded!");

	if (!isValid())
		throw std::runtime_error("Error: Not a valid MIDI file!");
}

void vMIDI::File::open(std::string path)
{
	filepath = path;
	file.open(filepath, std::ios::binary);

	if (!file || filepath.extension() != ".mid")
		throw std::runtime_error("Error: File could not be loaded!");

	if (!isValid())
		throw std::runtime_error("Error: Not a valid MIDI file!");
}

//=============================================================================
bool vMIDI::File::isValid()
{
	/**********************************************************************************************
	| The first 14 bytes in a midi file is the header chunk                                       |
	| and the header chunk must begin with "MThd"                                                 |
	|                                                                                             |
	| After the header chunk there must be at least one track chunk                               |
	| and track chunks begin with "MTrk"                                                          |
	|                                                                                             |
	| Also if the file is shorter than 18 characters (or bytes)                                   |
	| then it's impossible for it to be a valid midi file (header(14) + MTrk(4) = 18)             |
	| It's added first so this doesn't cause an out of range error                                |
	|                                                                                             |
	| Finally we check if the file ends with an "End of Track" midi meta event                    |
	| Three bytes with the the first two having the hex values "FF", "2F", the last byte is 0     |
	| string.size() - 2 is actually the last value, I believe an extra byte gets added at the end |
	|                                                                                             |
	| M = 77, T = 84, h = 104, d = 100                                                            |
	| M = 77, T = 84, r = 114, k = 107                                                            |
	**********************************************************************************************/

	// This stream is only used to check if the file is a valid midi file
	std::ifstream temporaryStream;
	temporaryStream.open(filepath, std::ios::binary);

	std::vector<char> tempChar;
	std::vector<uint8_t> tempUint;

	for (int i {0}; temporaryStream; ++i)
	{
		temporaryStream.seekg(i);

		tempChar.push_back('0');
		temporaryStream.get(tempChar[i]);

		tempUint.push_back(static_cast<uint8_t>(tempChar[i]));
	}

	if (tempUint.size() < 18 ||
		tempUint[0]  != 77	|| tempUint[1]  != 84  ||
		tempUint[2]  != 104 || tempUint[3]  != 100 ||
		tempUint[14] != 77	|| tempUint[15] != 84  ||
		tempUint[16] != 114 || tempUint[17] != 107 ||
		tempUint[tempUint.size() - 4] != 0xFF ||
		tempUint[tempUint.size() - 3] != 0x2F ||
		tempUint[tempUint.size() - 2] != 0
		)
	{
		return false;
	}

	else
		return true;
}