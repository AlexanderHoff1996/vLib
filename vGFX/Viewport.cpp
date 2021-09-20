#include "Viewport.h"

//=============================================================================
void vGFX::Viewport::set(GLfloat xPos, GLfloat yPos, GLfloat w, GLfloat h)
{
	x = xPos;
	y = yPos;
	width = w;
	height = h;

	glViewport(static_cast<GLint>(x), static_cast<GLint>(y),
		static_cast<GLsizei>(width), static_cast<GLsizei>(height));
}

//=============================================================================
void vGFX::Viewport::setX(GLfloat xPos)
{
	x = xPos;

	glViewport(static_cast<GLint>(x), static_cast<GLint>(y),
		static_cast<GLsizei>(width), static_cast<GLsizei>(height));
}

void vGFX::Viewport::setY(GLfloat yPos)
{
	y = yPos;

	glViewport(static_cast<GLint>(x), static_cast<GLint>(y),
		static_cast<GLsizei>(width), static_cast<GLsizei>(height));
}

void vGFX::Viewport::setWidth(GLfloat w)
{
	width = w;

	glViewport(static_cast<GLint>(x), static_cast<GLint>(y),
		static_cast<GLsizei>(width), static_cast<GLsizei>(height));
}

void vGFX::Viewport::setHeight(GLfloat h)
{
	height = h;

	glViewport(static_cast<GLint>(x), static_cast<GLint>(y),
		static_cast<GLsizei>(width), static_cast<GLsizei>(height));
}

//=============================================================================
GLfloat vGFX::Viewport::getX()		{return x;}
GLfloat vGFX::Viewport::getY()		{return y;}
GLfloat vGFX::Viewport::getWidth()	{return width;}
GLfloat vGFX::Viewport::getHeight()	{return height;}