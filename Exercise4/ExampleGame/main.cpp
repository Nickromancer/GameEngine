#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

#include "Engine/MyEngine.h"

#include "Game/PlayerController.h"
#include "Game/AstroidController.h"
#include "Game/ComponentRendererSprite.h"

void InitGame();
void ProcessEvents(SDL_Event& event);
void Update(float deltaTime);
void Render();

MyEngine::Engine engine;

constexpr int AMOUNT_OF_ASTROIDS = 5;

glm::vec2 window_size = glm::vec2(800, 600);
sre::SDLRenderer renderer;
sre::Camera camera;
std::shared_ptr<sre::SpriteAtlas> atlas;

int main() {
	renderer.frameRender = Render;
	renderer.frameUpdate = Update;
	renderer.keyEvent = ProcessEvents;

	renderer.setWindowSize(window_size);
	renderer.init();
	camera.setWindowCoordinates();

	atlas = sre::SpriteAtlas::create("data/Asteroid.json", "data/Asteroid.png");

	//Create the player
	auto playerObject = engine.CreateGameObject("PlayerObject");
	auto playerController = std::shared_ptr<ExampleGame::PlayerController>(new ExampleGame::PlayerController(atlas));
	auto playerComponentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	playerObject->AddComponent(playerController);
	playerObject->AddComponent(playerComponentRenderer);
	playerComponentRenderer->sprite = atlas->get("playerShip1_green.png");



	//Create the asteroids
	for (int i = 0; i < AMOUNT_OF_ASTROIDS; i++) {
		auto astroidObject = engine.CreateGameObject("AstroidObject");
		auto astroidController = std::shared_ptr<ExampleGame::AstroidController>(new ExampleGame::AstroidController());
		auto astroidComponentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
		astroidObject->AddComponent(astroidController);
		astroidObject->AddComponent(astroidComponentRenderer);
		astroidComponentRenderer->sprite = atlas->get("meteorGrey_big1.png");
	}

	engine.Init();

	renderer.startEventLoop();
}

void ProcessEvents(SDL_Event& event) {
	engine.ProcessEvents(event);
}

void Update(float deltaTime) {
	engine.Update(deltaTime);
}

void Render() {
	engine.Render();
}