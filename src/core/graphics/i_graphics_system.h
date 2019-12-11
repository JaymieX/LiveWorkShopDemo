#ifndef I_GRAPHICS_SYSTEM_H
#define I_GRAPHICS_SYSTEM_H

#include "i_window.h"
#include "core/event/event_handler.h"

namespace Workshop
{
	class IGraphicsSystem
	{
	protected:
		std::unique_ptr<IWindow> window;

	public:
		virtual void InitGraphicsSystem() = 0;

		virtual void PostInit() = 0;

		virtual void BeginRender() = 0;

		virtual void EndRender() = 0;

		virtual void EndGraphicsSystem() = 0;

		inline void HandleEvent(EventHandler* handler_)
		{
			window->HandleEvent(handler_);
		}

		inline void SetupWindow(const WindowInfo& window_info_)
		{
			window->CreateWindow(window_info_);
			window->SetWindowAsContext();
		}
	};
}

#endif