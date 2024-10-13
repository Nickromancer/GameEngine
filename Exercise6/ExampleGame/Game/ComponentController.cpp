#include "ComponentController.h"

#include "MyEngine.h"
#include "glm/glm.hpp"
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include "SDL.h"


void ComponentController::Init(rapidjson::Value& serializedData) {
	mov_speed = serializedData["movSpeed"].GetFloat();
	rot_speed = serializedData["rotSpeed"].GetFloat();
	std::cout << mov_speed << "\n";
	mov_speed *= 5;
	rot_speed *= 100;
}

void ComponentController::Update(float deltaTime) {
	auto gameObject = GetGameObject();

	//std::cout << gameObject->GetEulerAngles().y << " : " << gameObject->GetEulerAngles().p << " : " << gameObject->GetEulerAngles().r << "\n";

	Rotate(deltaTime);
	Move(deltaTime);

}

void ComponentController::KeyEvent(SDL_Event& event)
{
	auto gameObject = GetGameObject();

	if (event.type == SDL_MOUSEMOTION)
	{
		bMouseMotion = event.type == SDL_MOUSEMOTION;
		mouseRotationX = static_cast<float>(event.motion.x);
	}

	switch (event.key.keysym.sym)
	{
	case SDLK_a:
		bLeft = event.type == SDL_KEYDOWN;
		break;
	case SDLK_d:
		bRight = event.type == SDL_KEYDOWN;
		break;
	case SDLK_w:
		bForward = event.type == SDL_KEYDOWN;
		break;
	case SDLK_s:
		bBackward = event.type == SDL_KEYDOWN;
		break;
	default:
		break;
	}
}

void ComponentController::Render(sre::RenderPass&) {
	auto gameObject = GetGameObject();
	glm::vec3 position = gameObject->GetPosition();
	glm::vec3 _rotation = gameObject->GetEulerAngles();
	glm::vec3 scale = gameObject->GetScale();

	ImGui::SetNextWindowPos(ImVec2(.0f, .0f), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(300, 85), ImGuiCond_Always);
	ImGui::Begin("ComponentController::Render", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
	if (ImGui::DragFloat3("Position", &(position.x)))
		gameObject->SetPosition(position);
	if (ImGui::DragFloat3("Rotation", &(_rotation.x)))
		gameObject->SetEulerAngles(_rotation);
	if (ImGui::DragFloat3("Scale", &(scale.x)))
		gameObject->SetScale(scale);
	ImGui::End();
}

void ComponentController::Rotate(float deltaTime)
{
	auto gameObject = GetGameObject();

	if (bLeft)
	{
		gameObject->SetEulerAngles(gameObject->GetEulerAngles() - glm::vec3(0, -rot_speed * deltaTime, 0));
	}
	if (bRight)
	{
		gameObject->SetEulerAngles(gameObject->GetEulerAngles() - glm::vec3(0, rot_speed * deltaTime, 0));
	}

	if (bMouseMotion)
	{
		rotateX = (mouseRotationX / (float)(MyEngine::Engine::GetInstance()->GetScreenSize().x) * 3.14f - 3.14f / 2);
		gameObject->SetEulerAngles(gameObject->GetEulerAngles() - glm::vec3(0, (rotateX - deltaMousePostion) * rot_speed * deltaTime * 10, 0));
		deltaMousePostion = rotateX;
	}
}

void ComponentController::Move(float deltaTime)
{
	auto gameObject = GetGameObject();

	move_direction.x = glm::sin(glm::radians(gameObject->GetEulerAngles().y));
	move_direction.z = glm::cos(glm::radians(gameObject->GetEulerAngles().y));
	glm::normalize(move_direction);

	if (bForward)
	{
		gameObject->SetPosition(gameObject->GetPosition() - move_direction * mov_speed * deltaTime);
	}

	if (bBackward)
	{
		gameObject->SetPosition(gameObject->GetPosition() + move_direction * mov_speed * deltaTime);
	}
}
