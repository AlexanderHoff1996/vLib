#include "Window.h"

//=============================================================================
vNuk::Window::Window(std::string title,
	float x, float y, float width, float height,
	std::function<void()> callback, nk_flags flags)
{
	this->title		= title;
	this->x			= x;
	this->y			= y;
	this->width		= width;
	this->height	= height;
	this->callback	= callback;
	this->flags		= flags;
}

//=============================================================================
vNuk::Window::~Window()
{

}

//=============================================================================
void vNuk::Window::draw()
{
	if (nk_begin(NuklearContext::context, title.c_str(),
		nk_rect(x, y, width, height), flags))
	{
		callback();
	}

	nk_end(NuklearContext::context);
}