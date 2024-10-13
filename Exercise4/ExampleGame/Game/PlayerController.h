#pragma once

#include "Engine/Component.h"

constexpr float DELTA_DEGREE = 200;
constexpr float DELTA_SPEED = 150;

namespace ExampleGame {
	class PlayerController : public MyEngine::Component {
		float speed = 0;
		bool Left = false;
		bool Right = false;
		bool Forward = false;
		std::shared_ptr<sre::SpriteAtlas> sprite_atlas;

	public:
		PlayerController(std::shared_ptr<sre::SpriteAtlas> atlas);
		glm::vec2 position;
		float rotation;
		glm::vec2 direction = glm::vec2(1, 0);

		glm::vec2 velocity = glm::vec2(1, 1);
		float drag = 50.f;


		void Init() override;
		void Update(float) override;
		void KeyEvent(SDL_Event&) override;
	};
}