#pragma once

#include "Engine/Component.h"

float constexpr LIFE_TIME = 1.f;
float constexpr SPEED = 500.f;

namespace ExampleGame {

	class LaserObjectController : public MyEngine::Component {
		MyEngine::GameObject* parent;

	public:
		LaserObjectController(glm::vec2 position, glm::vec2 direction);
		glm::vec2 position;
		float rotation;
		glm::vec2 direction = glm::vec2(1, 0);

		float time_start;
		float time_elapsed;


		void Init() override;
		void Update(float) override;
	};
}