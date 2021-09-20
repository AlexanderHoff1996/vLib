#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

//=============================================================================
namespace vGFX {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
std::string loadVertexShader(const char* vertexPath);
std::string loadFragmentShader(const char* fragmentPath);

//  _______________
// | NAMESPACE END |
//  ***************
}