#include "LaserObjectController.h"
#include "Engine/MyEngine.h"


namespace ExampleGame {
	LaserObjectController::LaserObjectController(glm::vec2 position, glm::vec2 direction)
	{
		this->position = position;
		this->direction = direction;
		time_start = MyEngine::Engine::GetInstance()->GetTime();

	}
	void LaserObjectController::Init()
	{
		this->parent = GetGameObject();
		parent->position = position;
	}
	void LaserObjectController::Update(float deltaTime)
	{
		time_elapsed = MyEngine::Engine::GetInstance()->GetTime() - time_start;
		this->parent = GetGameObject();
		parent->position += direction * deltaTime * SPEED;

		if (time_elapsed > LIFE_TIME)
			parent->Delete();

	}
}
