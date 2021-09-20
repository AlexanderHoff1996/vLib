#include "Init.h"
#include "Viewport.h"
#include "Point.h"
#include "Color.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Texture.h"

#include <glad/glad.h>
#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

const int x {SDL_WINDOWPOS_UNDEFINED};
const int y {SDL_WINDOWPOS_UNDEFINED};

const int width {1280};
const int height {720};

const float widthF {1280.0f};
const float heightF {720.0f};

// SDL window
SDL_Window* window {nullptr};

// OpenGL context
SDL_GLContext context;

void initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		std::cout << "SDL could not initialize!\nSDL_ERROR: " <<
		SDL_GetError() << std::endl;

		throw std::runtime_error("Error: SDL could not initialize!");
	}
}

void createWindow(std::string title, int x, int y, int w, int h)
{
	window = SDL_CreateWindow(title.c_str(), x, y, w, h,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	
	if (window == nullptr)
	{
		std::cout << "Window could not be created!\nSDL_ERROR: " <<
			SDL_GetError() << std::endl;
	}
}

void render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void mainLoop()
{
	bool quit {false};
	SDL_Event e;

	// Triangle
	vGFX::Point2D p1 {200.0f, heightF - 200.0f};
	vGFX::Point2D p2 {widthF / 2, 200.0f};
	vGFX::Point2D p3 {widthF - 200.0f, heightF - 200.0f};
	vGFX::color::ColorFA triangleColor {vGFX::color::colorFA::gold};
	vGFX::Triangle triangle {p1, p2, p3, triangleColor};

	// Rectangle
	vGFX::Rectangle rectangle; 
	rectangle.setX(100.0f);
	rectangle.setY(100.0f);
	rectangle.setWidth(widthF - 200.0f);
	rectangle.setHeight(heightF - 200.0f);
	vGFX::color::ColorRGB rectangleColor {vGFX::color::colorRGB::seaGreen};
	rectangle.setColor(rectangleColor);

	int i {0};

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		render();
		rectangle.render();
		triangle.render();

		// Update the window (for windows using OpenGL rendering)
		SDL_GL_SwapWindow(window);
	}
}

void quit()
{
	// Destroy the window    
	SDL_DestroyWindow(window);
	window = nullptr;

	// Quit SDL
	SDL_Quit();
}

int main(int argc, char* args[])
{
	// Initialize SDL
	initSDL();

	// Create the window
	createWindow("vGFX", x, y, width, height);

	// Initialize vGFX
	// Set OpenGL version to 3.3 (core)
	// Create the OpenGL context
	// Initialize GLAD
	// Set the viewport to the window size
	// And load the shaders for Triangle, Rectangle, and Texture
	vGFX::init(3, 3, window, context);

	// The viewport is used to convert between normalized device coordinates (-0.0 to 1.0)
	// and window coordinates (w = window coordinates, n = normalized device coordinates):
	// Xw = (Xnd + 1) * (width / 2) + X
	// Yw = (Ynd + 1) * (height / 2) + Y
	// This is set to the window size by default so it's not actually needed
	// unless you want to specify a different size or the window size changes
	// Don't set x or y to SDL_WINDOWPOS_UNDEFINED, or it won't work!

	// Use Vsync
	vGFX::useVsync();

	// Run the main loop
	mainLoop();

	// Quit SDL and free resources
	quit();
	
	return 0;
}