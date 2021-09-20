#pragma once

#include "Viewport.h"
#include "Shared.h"
#include "LoadShader.h"

#include <glad/glad.h>
#include <SDL.h>

#include <iostream>

//=============================================================================
namespace vGFX {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
void init(int major, int minor, int profile,
	SDL_Window* window, SDL_GLContext& context);

void init(int major, int minor, SDL_Window* window, SDL_GLContext& context);

void setOpenGLVersion(int major, int minor, int profile);
void createOpenGLContext(SDL_Window* window, SDL_GLContext& context);
void initGLAD();
void setViewport(int x, int y, int w, int h);
void useVsync();
void loadShaders();

//  _______________
// | NAMESPACE END |
//  ***************
}