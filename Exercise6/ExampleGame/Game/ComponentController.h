#pragma once

#include "Component.h"

class ComponentController : public MyEngine::Component {
	void Init(rapidjson::Value&) override;
	void Update(float deltaTime) override;
	void KeyEvent(SDL_Event&) override;
	void Render(sre::RenderPass&) override;

	void Rotate(float deltaTime);
	void Move(float deltaTime);
	void MovePointIn3DSpace(float pitch, float yaw);
private:
	float mov_speed;
	float rot_speed;


	float deltaMousePostion;
	float mouseRotationX;

	float rotateX;
	float rotateY;

	glm::vec3 move_direction = glm::vec3(1, 0, 1);

	bool bLeft;
	bool bRight;
	bool bForward;
	bool bBackward;
	bool bMouseMotion;
};