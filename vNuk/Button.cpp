#include "Button.h"

//=============================================================================
vNuk::ImageButton::ImageButton(struct nk_image image,
	float x, float y, float width, float height)
{
	this->normal	= image;
	this->hover		= image;
	this->clicked	= image;
}

vNuk::ImageButton::ImageButton(struct nk_image normal, struct nk_image hover,
	float x, float y, float width, float height)
{
	this->normal	= normal;
	this->hover		= hover;
	this->clicked	= normal;
}

vNuk::ImageButton::ImageButton(struct nk_image normal, struct nk_image hover,
	struct nk_image clicked, float x, float y, float width, float height)
{
	this->normal	= normal;
	this->hover		= hover;
	this->clicked	= clicked;
}

//=============================================================================
vNuk::ImageButton::ImageButton::~ImageButton()
{

}