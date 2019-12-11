#ifndef GL_WINDOW_H
#define GL_WINDOW_H

#include "core/graphics/i_window.h"

#include <SDL.h>

namespace Workshop
{
	class GL_Window : public IWindow
	{
	private:
		SDL_Window* window;

	public:
		~GL_Window();

		// Inherited via IWindow
		virtual void CreateWindow(const WindowInfo & window_info_) override;
		virtual void SetWindowAsContext() override;
		virtual void HandleEvent() override;

		// Inherited via IWindow
		virtual void SwapWindow() override;
	};
}

#endif // !GL_WINDOW_H
