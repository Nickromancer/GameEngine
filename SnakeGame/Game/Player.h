#pragma once

#include <list>

#include "../Engine/Component.h"

namespace Snake {
	class Player : public MyEngine::Component {
		//sre::Sprite snake_sprite;
		const int PLAYER_START_X = 25;
		const int PLAYER_START_Y = 25;
		const int PLAYER_SPEED = 20;

	public:
		std::list<sre::Sprite> sprites;
		inline int GetPosX() { return pos_x.front(); }
		inline int GetPosY() { return pos_y.front(); }
		void Grow();
		bool IsOverlapping();

		void Init();
		void ProcessEvents(char input);
		void Update(int frame);
		void Render();

	private:
		std::list<int> pos_x;
		std::list<int> pos_y;

		int animation_frame;

		int dir_x, dir_y;
		int erase_x, erase_y;

	
	};
}