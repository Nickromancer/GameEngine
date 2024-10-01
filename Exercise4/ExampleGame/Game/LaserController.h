#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class LaserController : public MyEngine::Component {
		const float MovAmount = 100;
		const float LifeTime = 1;
	public:
		glm::vec2 position;
		float rotation;
		float time_start;
		glm::vec2 direction = glm::vec2(1, 0);


		void Init() override;
		void Update(float) override;

		//void KeyEvent(SDL_Event&) override;
	};
}