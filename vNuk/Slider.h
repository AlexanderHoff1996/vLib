#pragma once

#include "nuklear/NuklearSDL.h"

#include <iostream>
#include <string>
#include <functional>

//=============================================================================
namespace vNuk {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class Slider
{
public:
	Slider(float minValue, float maxValue, float stepValue, float* value,
		std::function<void()> callback);
	
	Slider(int minValue, int maxValue, int stepValue, int* value,
		std::function<void()> callback);

	~Slider();

	void draw();

private:
	float minValueF		{0.f};
	float maxValueF		{0.f};
	float stepValueF	{0.f};
	
	int minValueI		{0};
	int maxValueI		{0};
	int stepValueI		{0};

	float* valueF		{nullptr};
	int* valueI			{nullptr};

	std::function<void()> callback;

	bool isFloat {false};
};

//  _______________
// | NAMESPACE END |
//  ***************
}