#ifndef ENGINE_H
#define ENGINE_H

#include "graphics/i_window.h"
#include "graphics/i_graphics_system.h"

namespace Workshop
{
	enum Dist
	{
		OPENGL_CORE,
		DIRECTX_11
	};

	class Engine final
	{
	private:
		static std::unique_ptr<IGraphicsSystem> graphics_system;

	public:
		static void Init(Dist dist_, const WindowInfo& window_info_);

		static void Update();

		static void End();
	};
}

#endif