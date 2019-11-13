#include "workshop_pch.h"
#include "engine.h"

void Workshop::Engine::Init(Dist dist_, const WindowInfo& window_info_)
{
	graphics_system->InitGraphicsSystem();

	graphics_system->SetupWindow(window_info_);

	graphics_system->PostInit();
}

void Workshop::Engine::Update()
{
	while (true)
	{
		graphics_system->HandleEvent();
		graphics_system->BeginRender();

		graphics_system->EndRender();
	}
}

void Workshop::Engine::End()
{
	graphics_system->EndGraphicsSystem();
}
