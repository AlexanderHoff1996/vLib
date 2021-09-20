#include "LoadShader.h"

//=============================================================================
std::string vGFX::loadVertexShader(const char* vertexPath)
{
	// Retrieve the vertex source code from filePath

	std::string vertexCode;
	std::ifstream vertexShaderFile;

	// Ensure ifstream objects can throw exceptions:
	vertexShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

	try 
	{
		// Open file
		vertexShaderFile.open(vertexPath);
		std::stringstream vertexShaderStream;

		// Read file's buffer contents into streams
		vertexShaderStream << vertexShaderFile.rdbuf();

		// Close file handlers
		vertexShaderFile.close();

		// Convert stream into string
		vertexCode = vertexShaderStream.str();

		return vertexCode;
	}

	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR: Could not read vertex shader file!\n" << std::endl;

		return "";
	}
}

//=============================================================================
std::string vGFX::loadFragmentShader(const char* fragmentPath)
{
	// Retrieve the fragment source code from filePath

	std::string fragmentCode;
	std::ifstream fragmentShaderFile;

	// Ensure ifstream objects can throw exceptions:
	fragmentShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

	try 
	{
		// Open file
		fragmentShaderFile.open(fragmentPath);
		std::stringstream fragmentShaderStream;

		// Read file's buffer contents into streams
		fragmentShaderStream << fragmentShaderFile.rdbuf();		

		// Close file handlers
		fragmentShaderFile.close();

		// Convert stream into string
		fragmentCode = fragmentShaderStream.str();

		return fragmentCode;
	}

	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR: Could not read fragment shader file!\n" << std::endl;

		return "";
	}
}