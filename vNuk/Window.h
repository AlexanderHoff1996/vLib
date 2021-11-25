#pragma once

#include "nuklear/NuklearSDL.h"

#include <string>
#include <functional>

//=============================================================================
namespace vNuk {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class Window
{
public:
	Window(std::string title, float x, float y, float width, float height,
		std::function<void()> callback, nk_flags flags = 0);

	~Window();

	void draw();

private:
	std::string title;

	float x			{0.f};
	float y			{0.f};
	float width		{0.f};
	float height	{0.f};

	nk_flags flags {0};

	std::function<void()> callback;
};

//  _______________
// | NAMESPACE END |
//  ***************
}