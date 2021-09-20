#pragma once

#include "Color.h"

#include <glad/glad.h>

//=============================================================================
namespace vGFX {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
void clear(color::ColorFA col);
void clear(color::ColorRGBA col);
void clear(color::ColorRGB col);

//  _______________
// | NAMESPACE END |
//  ***************
}