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
class Rectangle
{
public:
	Rectangle();
	Rectangle(GLfloat xPos, GLfloat yPos, GLfloat w, GLfloat h, color::ColorFA col);
	Rectangle(GLfloat xPos, GLfloat yPos, GLfloat w, GLfloat h, color::ColorRGBA col);
	Rectangle(GLfloat xPos, GLfloat yPos, GLfloat w, GLfloat h, color::ColorRGB col);

	~Rectangle();

	void render();

	float getX();
	float getY();
	float getWidth();
	float getHeight();
	
	color::ColorFA getColorFA();
	color::ColorRGBA getColorRGBA();
	color::ColorRGB getColorRGB();

	void set(float xPos, float yPos, float w, float h, color::ColorFA col);
	void set(float xPos, float yPos, float w, float h, color::ColorRGBA col);
	void set(float xPos, float yPos, float w, float h, color::ColorRGB col);

	void setX(float xPos);
	void setY(float yPos);
	void setWidth(float w);
	void setHeight(float h);
	
	void setColor(color::ColorFA col);
	void setColor(color::ColorRGBA col);
	void setColor(color::ColorRGB col);

private:
	GLfloat x		{0.0f};
	GLfloat y		{0.0f};
	GLfloat width	{0.0f};
	GLfloat height	{0.0f};
	
	color::ColorFA color {0.0f};

	GLfloat vertexData[24];
	GLuint indices[6];

	GLuint VBO;
	GLuint VAO;
	GLuint EBO;

	// Shader object (with vertex and fragment shader paths)
	Shader shader {shared::rectangleVertexShader.c_str(),
		shared::rectangleFragmentShader.c_str()};

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