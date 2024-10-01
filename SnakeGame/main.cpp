#include <chrono>

#include "sre/SDLRenderer.hpp"  
#include "sre/SpriteAtlas.hpp"

#include "Engine/MyEngine.h"
#include "Game/Score.h"
#include "Game/Player.h"
#include "Game/Collectible.h"

MyEngine::Engine engine;

Snake::Score		score;
Snake::Player		player;
Snake::Collectible	collectible;

glm::vec2 position = glm::vec2(400, 400);

bool bQuit;

void InitGame();
void ProcessEvents(SDL_Event& event);
void Update(float deltaTime);
void Render();

int main() 
{
	InitGame();
}

void InitGame() {
	engine.Init();
	score.Init();

	player.gameSprite = engine.atlas->get("snake-body.png");
	player.gameSprite.setPosition(engine.window_size / 3.0f);
	player.Init();
	collectible.Init(engine);

	engine.renderer.frameRender = Render;
	engine.renderer.frameUpdate = Update;
	engine.renderer.keyEvent = ProcessEvents;

	collectible.gameSprite = engine.atlas->get("berry.png");
	collectible.gameSprite.setPosition(engine.window_size / 2.0f);

	engine.renderer.startEventLoop();
}

void ProcessEvents(SDL_Event &event) 
{ 
	engine.ProcessEvents(event);
	player.ProcessEvents(engine.input);

}

void Update(float deltaTime) {

	engine.Update();
	player.Update(engine.frame);

	// check death
	if (player.IsOverlapping())
	{
		++score.deaths;
		score.score = 0;
		player.Init();
		collectible.Init(engine);
	}

	// check collection
	if (
		player.GetPosX() == collectible.GetPosX() &&
		player.GetPosY() == collectible.GetPosY()
		)
	{
		++score.score;
		player.Grow();
		collectible.Init(engine);
	}
}

void Render() {
	engine.Render();
	player.Render();
	collectible.Render();

	if (!engine.b_show_debug_window)
		score.Render();

	sre::RenderPass renderPass = sre::RenderPass::create()
		.withCamera(engine.camera)
		.withClearColor(true, { .3f, .3f, 1, 1 })
		.build();

	sre::SpriteBatch::SpriteBatchBuilder spriteBatchBuilder
		= sre::SpriteBatch::create();

	for (sre::Sprite& sprite : player.sprites)
	{
		spriteBatchBuilder.addSprite(sprite);
	}
	
	spriteBatchBuilder.addSprite(collectible.gameSprite);

	auto spriteBatch = spriteBatchBuilder.build();
	renderPass.draw(spriteBatch);
}
