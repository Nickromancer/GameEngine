#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class PlayerController : public MyEngine::Component {
		const float RotSpeed = 100;
		const float MovAmount = 100;
		bool Left = false;
		bool Right = false;
		bool Forward = false;
		bool Fired = false;
		std::shared_ptr<sre::SpriteAtlas> sprite_atlas;

	public:
		PlayerController(std::shared_ptr<sre::SpriteAtlas> atlas);
		glm::vec2 position;
		float rotation;
		glm::vec2 direction = glm::vec2(1, 0);


		void Init() override;
		void Update(float) override;
		void KeyEvent(SDL_Event&) override;
	};
}