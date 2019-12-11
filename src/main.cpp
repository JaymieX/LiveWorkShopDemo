#include "workshop_pch.h"
#include "core/engine.h"
#include "core/custom/scene0.h"

int main(int argc_, char* argv_[])
{
	printf("CPP main");

	Workshop::WindowInfo info;
	info.x = 50;
	info.y = 50;
	info.width = 800;
	info.height = 600;
	info.title = "Workshop";

	Workshop::Engine::Init(Workshop::OPENGL_CORE, info);

	Workshop::Engine::scene_system.AddScene<Workshop::Scene0>("scene0");
	Workshop::Engine::scene_system.SwitchScene("scene0");

	Workshop::Engine::Update();
	Workshop::Engine::End();

	system("pause");

	return 0;
}