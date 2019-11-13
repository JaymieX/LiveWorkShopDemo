#include "workshop_pch.h"
#include "gl_graphics_system.h"

#include <SDL.h>
#include <glad/glad.h>

void Workshop::GL_GraphicsSystem::InitGraphicsSystem()
{
	// OpenGL 4.5
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);

	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

	// Use core profile
	SDL_GL_SetAttribute(
		SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_CORE
	);

	// Misc
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Enable double buffer
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);  // Enable 24bit z buffer
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Some thing went wrong");
		return;
	}

	if (SDL_GL_LoadLibrary(nullptr) == -1)
	{
		printf("SDL OpenGL init error\n");
		return;
	}
}

void Workshop::GL_GraphicsSystem::PostInit()
{
	// Load GLAD ver 1
	if (!gladLoadGLLoader((GLADloadproc)(SDL_GL_GetProcAddress)))
	{
		printf("%s \n", "Failed to initialize GLAD");
		return;
	}
}

void Workshop::GL_GraphicsSystem::BeginRender()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Workshop::GL_GraphicsSystem::EndRender()
{
	// SDL_GL_SwapWindow(window);
}

void Workshop::GL_GraphicsSystem::EndGraphicsSystem()
{
}
