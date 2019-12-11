#include "workshop_pch.h"
#include "gl_window.h"

Workshop::GL_Window::~GL_Window()
{
	SDL_DestroyWindow(window);
}

void Workshop::GL_Window::CreateWindow(const WindowInfo & window_info_)
{
	window = SDL_CreateWindow
	(
		window_info_.title.c_str(),
		window_info_.x,
		window_info_.y,
		window_info_.width,
		window_info_.height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
	);
}

void Workshop::GL_Window::SetWindowAsContext()
{
	SDL_GLContext context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, context);
}

void Workshop::GL_Window::HandleEvent()
{
	SDL_Event sdl_event;
	SDL_PollEvent(&sdl_event);
}

void Workshop::GL_Window::SwapWindow()
{
	SDL_GL_SwapWindow(window);
}
