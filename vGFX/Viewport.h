#pragma once

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
class Viewport
{
public:
	static void set(GLfloat xPos, GLfloat yPos, GLfloat w, GLfloat h);
	
	static void setX(GLfloat xPos);
	static void setY(GLfloat yPos);
	static void setWidth(GLfloat w);
	static void setHeight(GLfloat h);

	static GLfloat getX();
	static GLfloat getY();
	static GLfloat getWidth();
	static GLfloat getHeight();

private:
	inline static GLfloat x {0};
	inline static GLfloat y {0};
	inline static GLfloat width {0};
	inline static GLfloat height {0};
};

//  _______________
// | NAMESPACE END |
//  ***************
}