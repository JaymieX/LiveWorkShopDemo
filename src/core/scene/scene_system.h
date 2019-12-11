#ifndef SCENE_SYSTEM_H
#define SCENE_SYSTEM_H

#include "scene.h"
#include "core/event/event_handler.h"

namespace Workshop
{
	class SceneSystem final
	{
	private:
		std::unordered_map<std::string, std::unique_ptr<Scene>> scene_map;

		Scene* current_scene;
		
	protected:
		EventHandler handel;
		
	public:
		inline EventHandler* GetEventHandler()
		{
			return &handel;
		}
		
		template <typename SceneType, typename ...Args>
		void AddScene(const std::string& name_, Args&&... args_)
		{
			static_assert(
				std::is_convertible<SceneType, Scene>::value,
				"SceneType must publicly inherit from Scene"
			);

			// If scene_map contains name_
			// return
			if (scene_map.find(name_) != scene_map.end())
				return;

			scene_map.emplace(
				name_,
				std::make_unique<SceneType>(this, std::forward<Args>(args_)...)
			);
		}

		void SwitchScene(const std::string& name_);

		void PreEventHandling();

		void Update();

		void Render();
	};
}

#endif // !SCENE_SYSTEM_H
