#ifndef SCENE0_H
#define SCENE0_H

#include "core/scene/scene.h"

namespace Workshop
{
	class Scene0 : public Scene
	{
	public:
		Scene0(SceneSystem* system_);

		virtual void Begin() override;

		virtual void Render() override;
	};
}

#endif // !SCENE0_H
