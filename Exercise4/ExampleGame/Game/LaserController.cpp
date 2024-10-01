#include "LaserController.h"

#include "Engine/MyEngine.h"

namespace ExampleGame {
	void LaserController::Init() {
		MyEngine::GameObject* parent = GetGameObject();
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		time_start = engine->GetTime();

		direction.x = glm::sin(glm::radians(-parent->rotation));
		direction.y = glm::cos(glm::radians(-parent->rotation));
		glm::normalize(direction);



		//std::cout << "Created: " << position.x << " : " << position.y << "Parent: " << parent->GetName() << "\n";
		//std::cout << direction.x << " X : Y " << direction.y << "\n";


	}

	void LaserController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();
		float time_elapsed = engine->GetTime() - time_start;

		std::cout << LifeTime << "\n";

		parent->position += direction * MovAmount * deltaTime;

		if (time_elapsed > LifeTime)
		{
			//delete parent;
		}

	}
}