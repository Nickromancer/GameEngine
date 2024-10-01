#include "Collectible.h"

#include <random>

#include "../Engine/MyEngine.h"

namespace Snake {
	void Collectible::Init(MyEngine::Engine& engine) {
		int min_x = PLAY_AREA_MARGINS * 25;
		int min_y = PLAY_AREA_MARGINS * 25;
		int max_x = engine.GetScreenHeight()  - PLAY_AREA_MARGINS * 25;
		int max_y = engine.GetScreenWidth() - PLAY_AREA_MARGINS * 25;

		pos_x = std::rand() * 25 % (max_x - min_x) + min_x;
		pos_y = std::rand() * 25 % (max_y - min_y) + min_y;
	}

	void Collectible::Update() { }

	void Collectible::Render() {
		gameSprite.setPosition(glm::vec2(pos_x, pos_y));
	}
}