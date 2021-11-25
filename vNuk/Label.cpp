#include "Label.h"

//=============================================================================
void vNuk::label(std::string text, nk_flags alignment)
{
	nk_label(NuklearContext::context, text.c_str(), alignment);
}