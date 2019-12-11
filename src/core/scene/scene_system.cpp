#include "workshop_pch.h"
#include "scene_system.h"

void Workshop::SceneSystem::SwitchScene(const std::string & name_)
{
	// End the last scene
	if (current_scene != nullptr)
	{
		current_scene->End();
	}

	// If scene_map contains name_
	// return
	if (scene_map.find(name_) == scene_map.end())
		return;

	current_scene = scene_map.at(name_).get();
	current_scene->Begin();
}

void Workshop::SceneSystem::PreEventHandling()
{
	handel.Reset();
}

void Workshop::SceneSystem::Update()
{
	if (current_scene != nullptr)
	{
		current_scene->Update();
	}
}

void Workshop::SceneSystem::Render()
{
	if (current_scene != nullptr)
	{
		current_scene->Render();
	}
}
