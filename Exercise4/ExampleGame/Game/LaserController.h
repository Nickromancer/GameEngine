#pragma once

#include "Engine/Component.h"

float constexpr COOLDOWN = .1f;

namespace ExampleGame {
	class LaserController : public MyEngine::Component {
		bool bFired = false;
		bool bIsFired = false;
		std::shared_ptr<sre::SpriteAtlas> sprite_atlas;

	public:
		LaserController(std::shared_ptr<sre::SpriteAtlas> atlas);
		glm::vec2 position;
		float rotation;
		glm::vec2 direction = glm::vec2(1, 0);
		
		float time_start;
		float time_elapsed;


		void Init() override;
		void Update(float) override;
		void ShootLaser();

		void KeyEvent(SDL_Event&) override;
	};
}