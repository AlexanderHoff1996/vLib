#include "Init.h"

//=============================================================================
void vGFX::init(int major, int minor, int profile,
	SDL_Window* window, SDL_GLContext& context)
{
	setOpenGLVersion(major, minor, profile);
	createOpenGLContext(window, context);
	initGLAD();

	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	setViewport(0, 0, w, h);
	
	loadShaders();
}

void vGFX::init(int major, int minor, SDL_Window* window, SDL_GLContext& context)
{
	setOpenGLVersion(major, minor, SDL_GL_CONTEXT_PROFILE_CORE);
	createOpenGLContext(window, context);
	initGLAD();

	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	setViewport(0, 0, w, h);
	
	loadShaders();
}

//=============================================================================
void vGFX::setOpenGLVersion(int major, int minor, int profile)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, profile);
}

void vGFX::createOpenGLContext(SDL_Window* window, SDL_GLContext& context)
{
	context = SDL_GL_CreateContext(window);

	if (context == nullptr)
	{
		std::cout << "OpenGL context could not be created!\nSDL_ERROR: " <<
			SDL_GetError() << std::endl;
	}
}

void vGFX::initGLAD()
{
	if (!gladLoadGLLoader(static_cast<GLADloadproc>(SDL_GL_GetProcAddress)))
	{
		std::cout << "Could not initialize GLAD!" << std::endl;
	}
}

//=============================================================================
void vGFX::setViewport(int x, int y, int w, int h)
{
	Viewport::set(static_cast<GLfloat>(x), static_cast<GLfloat>(y),
		static_cast<GLfloat>(w), static_cast<GLfloat>(h));
}

void vGFX::useVsync()
{
	if (SDL_GL_SetSwapInterval(1) < 0)
	{
		std::cout << "Unable to set Vsync!\nSDL_ERROR: " <<
			SDL_GetError() << std::endl;
	}
}

//=============================================================================
void vGFX::loadShaders()
{
	// Triangle

	shared::triangleVertexShader = loadVertexShader(
		"D:/_Mappar/Programmering/C++/Bibliotek/Egna Bibliotek/vLib/"
		"vGFX/Resources/Shaders/triangle.vs");

	shared::triangleFragmentShader = loadFragmentShader(
		"D:/_Mappar/Programmering/C++/Bibliotek/Egna Bibliotek/vLib/"
		"vGFX/Resources/Shaders/triangle.fs");


	// Rectangle

	shared::rectangleVertexShader = loadVertexShader(
		"D:/_Mappar/Programmering/C++/Bibliotek/Egna Bibliotek/vLib/"
		"vGFX/Resources/Shaders/rectangle.vs");

	shared::rectangleFragmentShader = loadFragmentShader(
		"D:/_Mappar/Programmering/C++/Bibliotek/Egna Bibliotek/vLib/"
		"vGFX/Resources/Shaders/rectangle.fs");


	// Texture

	shared::textureVertexShader = loadVertexShader(
		"D:/_Mappar/Programmering/C++/Bibliotek/Egna Bibliotek/vLib/"
		"vGFX/Resources/Shaders/texture.vs");

	shared::textureFragmentShader = loadFragmentShader(
		"D:/_Mappar/Programmering/C++/Bibliotek/Egna Bibliotek/vLib/"
		"vGFX/Resources/Shaders/texture.fs");
}