#include "Clear.h"

//=============================================================================
void vGFX::clear(color::ColorFA col)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(col.r, col.g, col.b, col.a);
}

void vGFX::clear(color::ColorRGBA col)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(col.r / 255.f, col.g / 255.f, col.b / 255.f, col.a / 255.f);
}

void vGFX::clear(color::ColorRGB col)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(col.r / 255.f, col.g / 255.f, col.b / 255.f, 1.0f);
}