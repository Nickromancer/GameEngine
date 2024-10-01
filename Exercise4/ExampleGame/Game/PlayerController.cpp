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

		if (Left)
			parent->rotation += RotSpeed * deltaTime;

		if (Right)
			parent->rotation -= RotSpeed * deltaTime;

		if (Forward)
			parent->position += direction * MovAmount * deltaTime;

		if (Fired) 
		{
			auto laserObject = engine->GetInstance()->CreateGameObject("laserObject");
            GetGameObject()->AddChild(std::make_shared<MyEngine::GameObject>(*laserObject));
			auto laserController = std::shared_ptr<ExampleGame::LaserController>(new ExampleGame::LaserController());
			auto laserComponentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
			laserObject->AddComponent(laserController);
			laserObject->AddComponent(laserComponentRenderer);
			laserComponentRenderer->sprite = sprite_atlas->get("laserGreen12.png");

			laserObject->position = parent->position;
			laserObject->rotation = parent->rotation;
			laserObject->Init();

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
		case SDLK_SPACE:
			Fired = event.type == SDL_KEYDOWN;
			break;
		default:
			break;
		}
	}
}
