#include "Slider.h"

//=============================================================================
vNuk::Slider::Slider(float minValue, float maxValue, float stepValue,
	float* value, std::function<void()> callback)
{
	this->minValueF		= minValue;
	this->maxValueF		= maxValue;
	this->stepValueF	= stepValue;
	this->valueF		= value;
	this->callback		= callback;

	isFloat = true;
}

vNuk::Slider::Slider(int minValue, int maxValue, int stepValue,
	int* value, std::function<void()> callback)
{
	this->minValueI		= minValue;
	this->maxValueI		= maxValue;
	this->stepValueI	= stepValue;
	this->valueI		= value;
	this->callback		= callback;

	isFloat = false;
}

//=============================================================================
vNuk::Slider::~Slider()
{

}

//=============================================================================
void vNuk::Slider::draw()
{
	if (isFloat)
	{
		if (nk_slider_float(NuklearContext::context,
			minValueF, valueF, maxValueF, stepValueF))
		{
			callback();
		}
	}

	else
	{
		if (nk_slider_int(NuklearContext::context,
			minValueI, valueI, maxValueI, stepValueI))
		{
			callback();
		}
	}
}