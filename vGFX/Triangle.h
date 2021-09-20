#pragma once

#include "Shader.h"
#include "Viewport.h"
#include "Point.h"
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
class Triangle
{
public:
	Triangle();
	Triangle(Point2D p1, Point2D p2, Point2D p3, color::ColorFA col);

	~Triangle();

	void render();

	int getX()		{return x;}
	int getY()		{return y;}
	int getWidth()	{return width;}
	int getHeight()	{return height;}

private:
	int x		{0};
	int y		{0};
	int width	{0};
	int height	{0};

	GLfloat vertexData[18];

	GLuint VBO;
	GLuint VAO;

	// Shader object (with vertex and fragment shader paths)
	Shader shader {shared::triangleVertexShader.c_str(),
		shared::triangleFragmentShader.c_str()};
};

//  _______________
// | NAMESPACE END |
//  ***************
}