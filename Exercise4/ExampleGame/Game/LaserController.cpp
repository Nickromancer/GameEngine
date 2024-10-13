#include "LaserController.h"

#include "Engine/MyEngine.h"
#include "ComponentRendererSprite.h"
#include "LaserObjectController.h"

namespace ExampleGame 
{
	LaserController::LaserController(std::shared_ptr<sre::SpriteAtlas> atlas) 
	{
		sprite_atlas = atlas;
	}

	void LaserController::Init() {

		time_start = 0;
	}

	void LaserController::Update(float deltaTime) 
	{
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		direction.x = glm::sin(glm::radians(-parent->rotation));
		direction.y = glm::cos(glm::radians(-parent->rotation));
		glm::normalize(direction);

		time_elapsed = MyEngine::Engine::GetInstance()->GetTime() - time_start;
	}

	void LaserController::KeyEvent(SDL_Event& event) 
	{
		if ((event.key.keysym.sym == SDLK_SPACE && event.type == SDL_KEYDOWN) && time_elapsed > COOLDOWN)
		{				
			ShootLaser();
			time_start = MyEngine::Engine::GetInstance()->GetTime();
		}
	}

	void LaserController::ShootLaser() 
	{
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();
		
		auto laserObject = engine->GetInstance()->CreateGameObject("laserObject");
		GetGameObject()->AddChild(std::make_shared<MyEngine::GameObject>(*laserObject));

		laserObject->rotation = parent->rotation;
		laserObject->position = parent->position;

		auto laserComponentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
		auto laserObjectController = std::make_shared<ExampleGame::LaserObjectController>(position, direction);

		laserObject->AddComponent(laserComponentRenderer);
		laserObject->AddComponent(laserObjectController);

		laserComponentRenderer->sprite = sprite_atlas->get("laserGreen12.png");
		
	}
}