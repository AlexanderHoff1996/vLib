#pragma once

#include "nuklear/NuklearSDL.h"

#include <string>
#include <iostream>

//=============================================================================
namespace vNuk {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
class Button
{
public:
private:
};

//=============================================================================
class ImageButton
{
public:
	ImageButton(struct nk_image image,
		float x, float y, float width, float height);
	
	ImageButton(struct nk_image normal, struct nk_image hover,
		float x, float y, float width, float height);
	
	ImageButton(struct nk_image normal, struct nk_image hover,
		struct nk_image clicked, float x, float y, float width, float height);
	
	~ImageButton();

private:
	float x			{0.0f};
	float y			{0.0f};
	float width		{0.0f};
	float height	{0.0f};

	struct nk_image normal;
	struct nk_image hover;
	struct nk_image clicked;
};

//  _______________
// | NAMESPACE END |
//  ***************
}