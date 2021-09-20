#pragma once

#include "Shader.h"
#include "Viewport.h"
#include "Color.h"

#include "Shared.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

//=============================================================================
namespace vGFX {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class Texture
{
public:
	Texture();
	~Texture();

	void createTexture(GLfloat x, GLfloat y, GLfloat w, GLfloat h,
		int imageWidth, int imageHeight, const void* data, int format,
		int textureFilterMin = GL_LINEAR, int textureFilterMag = GL_LINEAR,
		int textureWrapX = GL_REPEAT, int textureWrapY = GL_REPEAT);

	void render();

	int get()		{return static_cast<int>(texture);}

	float getWidth()  {return static_cast<float>(width);}
	float getHeight() {return static_cast<float>(height);}

	void set(float xPos, float yPos, float w, float h);

	void setX(float xPos);
	void setY(float yPos);
	void setWidth(float w);
	void setHeight(float h);

	void setColor(color::ColorFA col);
	void setColor(color::ColorRGBA col);
	void setColor(color::ColorRGB col);

private:
	GLuint texture;

	GLfloat x		{0.0f};
	GLfloat y		{0.0f};
	GLfloat width	{0.0f};
	GLfloat height	{0.0f};

	color::ColorFA color {0.0f};

	GLfloat vertexData[16];
	GLuint indices[6];

	GLuint VBO;
	GLuint VAO;
	GLuint EBO;

	// Shader object (with vertex and fragment shader paths)
	Shader shader {shared::textureVertexShader.c_str(),
		shared::textureFragmentShader.c_str()};

	void free();

	void setVertexData();
	void setupMatrices();
	void setBuffers();
	void setAttributes();

	void updateData();
};

//  _______________
// | NAMESPACE END |
//  ***************
}