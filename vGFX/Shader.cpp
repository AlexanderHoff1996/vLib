#include "Shader.h"

//=============================================================================
// The constructor reads and builds the shader
vGFX::Shader::Shader(const char* vertexPath, const char* fragmentPath, bool isFile)
	: shaderProgramID {0}
{
	// If vertexPath and fragmentPath are paths to files (and not just strings)
	if (isFile)
	{
		// Retrieve the vertex/fragment source code from filePath

		std::ifstream vertexShaderFile;
		std::ifstream fragmentShaderFile;

		// Ensure ifstream objects can throw exceptions:
		vertexShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
		fragmentShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

		try 
		{
			// Open files
			vertexShaderFile.open(vertexPath);
			fragmentShaderFile.open(fragmentPath);
			std::stringstream vertexShaderStream, fragmentShaderStream;

			// Read file's buffer contents into streams
			vertexShaderStream << vertexShaderFile.rdbuf();
			fragmentShaderStream << fragmentShaderFile.rdbuf();		

			// Close file handlers
			vertexShaderFile.close();
			fragmentShaderFile.close();

			// Convert stream into string
			vertexCode   = vertexShaderStream.str();
			fragmentCode = fragmentShaderStream.str();		
		}

		catch(std::ifstream::failure e)
		{
			std::cout << "ERROR: Could not read shader file!\n" << std::endl;
		}
	}

	// If vertexPath and fragmentPath are just strings
	else
	{
		vertexCode = vertexPath;
		fragmentCode = fragmentPath;
	}

	vertexShaderCode = vertexCode.c_str();
	fragmentShaderCode = fragmentCode.c_str();


	// Compile shaders

	GLuint vertexShader;
	GLuint fragmentShader;
	GLint  success;
	GLchar infoLog[512];

	// Vertex Shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
	glCompileShader(vertexShader);
	
	// Check for vertex shader compilation errors
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cout << "ERROR: Could not compile vertex shader!\n" << infoLog << std::endl;
	};

	// Fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
	glCompileShader(fragmentShader);

	// Check for fragment shader compilation errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cout << "ERROR: Could not compile fragment shader!\n" << infoLog << std::endl;
	};

	// Link the shaders using a shader program
	shaderProgramID = glCreateProgram();
	glAttachShader(shaderProgramID, vertexShader);
	glAttachShader(shaderProgramID, fragmentShader);
	glLinkProgram(shaderProgramID);
	
	// Check for linking errors
	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(shaderProgramID, 512, nullptr, infoLog);
		std::cout << "ERROR: Could not link shaders!\n" << infoLog << std::endl;
	}

	// After linking, the shader objects are no longer needed
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

vGFX::Shader::~Shader()
{
	glDeleteProgram(shaderProgramID);
}

//=============================================================================
// Use/activate the shader
void vGFX::Shader::use()
{
	glUseProgram(shaderProgramID);
}

//=============================================================================
// Utility uniform functions
void vGFX::Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), (int)value);
}

void vGFX::Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), value);
}

void vGFX::Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(shaderProgramID, name.c_str()), value);
}

void vGFX::Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{ 
	glUniform2fv(glGetUniformLocation(shaderProgramID, name.c_str()), 1, &value[0]); 
}
void vGFX::Shader::setVec2(const std::string &name, float x, float y) const
{ 
	glUniform2f(glGetUniformLocation(shaderProgramID, name.c_str()), x, y); 
}

void vGFX::Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{ 
	glUniform3fv(glGetUniformLocation(shaderProgramID, name.c_str()), 1, &value[0]); 
}
void vGFX::Shader::setVec3(const std::string &name, float x, float y, float z) const
{ 
	glUniform3f(glGetUniformLocation(shaderProgramID, name.c_str()), x, y, z); 
}

void vGFX::Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{ 
	glUniform4fv(glGetUniformLocation(shaderProgramID, name.c_str()), 1, &value[0]); 
}
void vGFX::Shader::setVec4(const std::string &name, float x, float y, float z, float w) const
{ 
	glUniform4f(glGetUniformLocation(shaderProgramID, name.c_str()), x, y, z, w); 
}

void vGFX::Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(shaderProgramID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void vGFX::Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(shaderProgramID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void vGFX::Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}