#pragma once

#include "Component.h"

class ComponentLayout : public MyEngine::Component {
public:
	void Init(rapidjson::Value& serializedData) override;
};