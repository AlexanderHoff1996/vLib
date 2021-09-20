#pragma once

// This file should store some shared resources, like shaders
// All triangles should use the same shaders
// Same with rectangles and textures

#include "Shader.h"
#include "Viewport.h"

#include <glad/glad.h>
#include <SDL.h>

#include <iostream>
#include <string>

//=============================================================================
namespace vGFX {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

namespace shared {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
// Triangle
extern std::string triangleVertexShader;
extern std::string triangleFragmentShader;

// Rectangle
extern std::string rectangleVertexShader;
extern std::string rectangleFragmentShader;

// Texture
extern std::string textureVertexShader;
extern std::string textureFragmentShader;

//  _______________
// | NAMESPACE END |	// shared
//  ***************
}

//  _______________
// | NAMESPACE END |	// vGFX
//  ***************
}