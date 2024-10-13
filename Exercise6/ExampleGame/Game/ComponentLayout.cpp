#include "ComponentLayout.h"
#include "ComponentRendererMesh.h"
#include "MyEngine.h"


void ComponentLayout::Init(rapidjson::Value& serializedData) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();


		auto& layout = serializedData["layout"].GetArray();
		std::cout << layout[0][0].GetFloat() << "\n";

		//Create a new gameObject with a `ComponentRenderMesh` for each entry in `layout`
		for (int i = 0; i < layout[0].Size(); i++)
		{
			for (int j = 0; j < layout.Size(); j++)
			{
				std::shared_ptr<MyEngine::GameObject> game_object = std::make_shared<MyEngine::GameObject>();
				game_object = std::shared_ptr<MyEngine::GameObject>(engine->CreateGameObject("Block"));

				auto render = std::make_shared<ComponentRendererMesh>();
				game_object->AddComponent(render);
				//game_object->SetPosition(glm::vec3())
				std::cout << "Position: " << i << " : " << j << "\n";
			}
		}
		//Assign different UV coordinates to the cube, so that each face shows the appropriate tile in the texture
		//Set the position of the child gameObjects to replicate the structure in 3D space
}

