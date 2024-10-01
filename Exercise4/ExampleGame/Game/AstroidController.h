#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class AstroidController : public MyEngine::Component {
		const float RotSpeed = 50;
		const float MinSpeed = 10;
		const float MaxSpeed = 100;
		const glm::vec2 MovDirection = glm::vec2(1, 0);

	public:
		float MovAmount;
		glm::vec2 position;
		float rotation;
		glm::vec2 direction;

		void Init() override;
		void Update(float) override;
	};
}