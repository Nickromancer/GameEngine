#pragma once

#include "MyEngine.h"

namespace MyEngine {
	class Component {
	public:
		sre::Sprite gameSprite;
		virtual void Init() {};
		virtual void Update() {};
	};
}