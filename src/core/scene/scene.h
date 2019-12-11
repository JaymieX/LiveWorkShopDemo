#ifndef SCENE_H
#define SCENE_H

namespace Workshop
{
	class Scene
	{
	protected:
		class SceneSystem* system;

	public:
		Scene(class SceneSystem* system_);

		virtual void Begin() {};

		virtual void End() {};

		virtual void Update() {};

		virtual void Render() {};
	};
}

#endif // !SCENE_H
