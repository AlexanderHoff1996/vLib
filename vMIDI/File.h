#pragma once

#include <filesystem>
#include <fstream>
#include <string>

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class File
{
public:
	std::ifstream& getStream();
	
	std::filesystem::path& getPath();
	void setPath(std::string path);

	void open();
	void open(std::string path);

	bool isValid();

private:
	std::filesystem::path filepath;
	std::ifstream file {filepath, std::ios::binary};
};

//  _______________
// | NAMESPACE END |
//  ***************
}