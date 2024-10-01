#include "AstroidController.h"

#include "Engine/MyEngine.h"
#include <random>

namespace ExampleGame {
	void AstroidController::Init() {
		MyEngine::GameObject* parent = GetGameObject();
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();

		parent->rotation = std::rand() % 360;
		MovAmount = (std::rand() % static_cast<int>(MaxSpeed)) + MinSpeed;

		direction.x = glm::sin(glm::radians(-parent->rotation));
		direction.y = glm::cos(glm::radians(-parent->rotation));
		glm::normalize(direction);

        parent->position = glm::vec2(
			std::rand() % static_cast<int>(engine->GetScreenSize().x), 
			std::rand() % static_cast<int>(engine->GetScreenSize().y));
				
	}

	void AstroidController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		glm::vec2 screen_size = MyEngine::Engine::GetInstance()->GetScreenSize();

		parent->rotation += RotSpeed * deltaTime;
		parent->position += direction * MovAmount * deltaTime;

		if (parent->position.x < 0)
			parent->position.x = screen_size.x;
		if (parent->position.x > screen_size.x)
			parent->position.x = 0;

		if (parent->position.y < 0)
			parent->position.y = screen_size.y;
		if (parent->position.y > screen_size.y)
			parent->position.y = 0;

	}
}