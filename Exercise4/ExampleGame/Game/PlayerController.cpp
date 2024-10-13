#include "PlayerController.h"

#include "Engine/MyEngine.h"
#include "LaserController.h"
#include "ComponentRendererSprite.h"


namespace ExampleGame {
	PlayerController::PlayerController(std::shared_ptr<sre::SpriteAtlas> atlas)
	{
		sprite_atlas = atlas;
	}

	void PlayerController::Init() {
		GetGameObject()->position = MyEngine::Engine::GetInstance()->GetScreenSize() / 2.f;
	}

	void PlayerController::Update(float deltaTime) {
		MyEngine::GameObject* parent = GetGameObject();
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();

		glm::vec2 screen_size = MyEngine::Engine::GetInstance()->GetScreenSize();

		direction.x = glm::sin(glm::radians(-parent->rotation));
		direction.y = glm::cos(glm::radians(-parent->rotation));
		glm::normalize(direction);

		speed -= drag * deltaTime;

		if (speed <= .1f)
			speed = 0;

		std::cout << direction.x << " : " << direction.y << "\n";

		//velocity += (direction * (speed * deltaTime)) + 1.f / 2.f * ((drag / 10.f) * glm::pow(deltaTime, 2.f));

		velocity += (direction * speed * deltaTime) - drag;



		parent->position += (velocity * deltaTime);

		if (Left)
			parent->rotation += DELTA_SPEED * deltaTime;

		if (Right)
			parent->rotation -= DELTA_DEGREE * deltaTime;

		if (Forward)
		{
			speed += DELTA_SPEED * deltaTime;
			direction += speed * deltaTime;

		}

		if (parent->position.x < 0)
			parent->position.x = screen_size.x;
		if (parent->position.x > screen_size.x)
			parent->position.x = 0;

		if (parent->position.y < 0)
			parent->position.y = screen_size.y;
		if (parent->position.y > screen_size.y)
			parent->position.y = 0;


	}

	void PlayerController::KeyEvent(SDL_Event& event) {
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			Left = event.type == SDL_KEYDOWN;
			break;
		case SDLK_d:
			Right = event.type == SDL_KEYDOWN;
			break;
		case SDLK_w:
			Forward = event.type == SDL_KEYDOWN;
			break;
		default:
			break;
		}
	}
}
