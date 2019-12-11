#ifndef I_WINDOW_H
#define I_WINDOW_H

#include "core/event/event_handler.h"

namespace Workshop
{
	struct WindowInfo
	{
		int x, y;
		int width, height;

		std::string title;
	};

	class IWindow
	{
	public:
		virtual void CreateWindow(const WindowInfo& window_info_) = 0;

		virtual void SetWindowAsContext() = 0;

		virtual void HandleEvent(EventHandler* handler_) = 0;

		virtual void SwapWindow() = 0;
	};
}

#endif