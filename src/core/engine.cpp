#include "workshop_pch.h"
#include "engine.h"

#include "core/dist/opengl/graphics/gl_graphics_system.h"

// static std::unique_ptr<IGraphicsSystem> graphics_system;
std::unique_ptr<Workshop::IGraphicsSystem> Workshop::Engine::graphics_system(nullptr);

// static SceneSystem scene_system;
Workshop::SceneSystem Workshop::Engine::scene_system;

void Workshop::Engine::Init(Dist dist_, const WindowInfo& window_info_)
{
	switch (dist_)
	{
	case Workshop::OPENGL_CORE:
		graphics_system = std::make_unique<GL_GraphicsSystem>();
		break;
	case Workshop::DIRECTX_11:
		break;
	}

	graphics_system->InitGraphicsSystem();

	graphics_system->SetupWindow(window_info_);

	graphics_system->PostInit();
}

void Workshop::Engine::Update()
{
	while (true)
	{
		scene_system.PreEventHandling();
		
		graphics_system->HandleEvent(scene_system.GetEventHandler());

		scene_system.Update();

		graphics_system->BeginRender();

		scene_system.Render();

		graphics_system->EndRender();
	}
}

void Workshop::Engine::End()
{
	graphics_system->EndGraphicsSystem();
}
