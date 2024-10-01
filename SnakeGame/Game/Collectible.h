#pragma once

#include "../Engine/Component.h"

namespace Snake {
	class Collectible : public MyEngine::Component {
		const int PLAY_AREA_MARGINS = 4;

		int pos_x;
		int pos_y;


	public:
		inline int GetPosX() { return pos_x; }
		inline int GetPosY() { return pos_y; }

		void Init(MyEngine::Engine& engine);
		void Update();
		void Render();
	};
}
