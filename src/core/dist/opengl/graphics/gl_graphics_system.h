#ifndef GL_GRAPHICS_SYSTEM_H
#define GL_GRAPHICS_SYSTEM_H

#include "core/graphics/i_graphics_system.h"

namespace Workshop
{
	class GL_GraphicsSystem : public IGraphicsSystem
	{
	public:
		// Inherited via IGraphicsSystem
		virtual void InitGraphicsSystem() override;
		virtual void PostInit() override;
		virtual void BeginRender() override;
		virtual void EndRender() override;
		virtual void EndGraphicsSystem() override;
	};
}

#endif