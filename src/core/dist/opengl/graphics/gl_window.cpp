#include "workshop_pch.h"
#include "gl_window.h"

#include "core/dist/opengl/event/sdl_key_map.h"

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

void Workshop::GL_Window::HandleEvent(EventHandler* handler_)
{
	SDL_Event sdl_event;
	SDL_PollEvent(&sdl_event);

	/*if (sdl_event.type == SDL_KEYDOWN)
	{
		printf("key input\n");
	}*/

	SDL_KeyMap* translator = SDL_KeyMap::GetInstance();
	
	switch (sdl_event.type)
	{
	case SDL_KEYDOWN:
		handler_->current_keyboard_key_down = translator->GetKeyboardTranslator().at(sdl_event.key.keysym.sym);
		break;
	case SDL_KEYUP:
		handler_->current_keyboard_key_up = translator->GetKeyboardTranslator().at(sdl_event.key.keysym.sym);
		break;
	}
}

void Workshop::GL_Window::SwapWindow()
{
	SDL_GL_SwapWindow(window);
}
