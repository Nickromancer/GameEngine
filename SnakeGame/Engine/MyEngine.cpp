#include "MyEngine.h"

#include <random>

#include "GameObject.h"

namespace MyEngine {
	int Engine::GetScreenWidth() {
		return width;
	}

	int Engine::GetScreenHeight() {
		return height;
	}

	void Engine::Init() {
		// initializes random generator
		std::srand(std::time(nullptr)); 

		renderer.setWindowSize(window_size);
		renderer.init();
		camera.setWindowCoordinates();

		atlas = sre::SpriteAtlas::create("data/snake.json", "data/snake.png");
	}

	void Engine::ProcessEvents(SDL_Event& event) {
		switch (event.key.keysym.sym) {
			case SDLK_w:
				input = SDLK_w;
				std::cout << "UP" << "\n";
				break;
			case SDLK_s:
				input = SDLK_s;
				std::cout << "DOWN" << "\n";
				break;
			case SDLK_a:
				input = SDLK_a;
				std::cout << "LEFT" << "\n";
				break;
			case SDLK_d:
				input = SDLK_d;
				std::cout << "RIGHT" << "\n";
				break;
			case SDLK_2:
				input = SDLK_2;
				break;
			case SDLK_1:
				input = SDLK_1;
				break;
			default:
				break;

		}
	}

	void Engine::Update() {
		++frame;
		if (input == SDLK_1)
		{
			b_show_debug_window = !b_show_debug_window;

			if (!b_show_debug_window)
				// do a full clear to hide the panel
				std::cout << "DEBUG_CLEAR" << "\n";
		}
	}

	void Engine::Render() {
		if (b_show_debug_window)
		{
			std::cout << " Computation(ms) : " << GetTimeComputationMs()	<< "\t+" << std::endl;
			std::cout << " Elapsed(ms)     : " << GetTimeElapsedMs()		<< "\t+" << std::endl;
			std::cout << " FPS             : " << GetFPS()					<< "\t+" << std::endl;
			std::cout << "+++++++++++++++++++++++++++++++++";
		}
	}
}
