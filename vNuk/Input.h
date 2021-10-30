#pragma once

#include "nuklear/NuklearSDL.h"

//=============================================================================
namespace vNuk {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
void inputBegin();
void inputEnd();

void handleEvent(SDL_Event* event);

//  _______________
// | NAMESPACE END |
//  ***************
}