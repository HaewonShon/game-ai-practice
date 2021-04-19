#include "../GraphicsEngine/Engine.h"
#include "BasicScene.h"

#include <iostream>

enum class Scenes
{
	BASIC_SCENE,
	COUNT
};

[[nodiscard]] int ConvertSceneEnum(Scenes scene)
{
	return static_cast<int>(scene);
}

int main()
{
	try {
		Engine engine;

		engine.Init();

		engine.RegisterScene<BasicScene>(ConvertSceneEnum(Scenes::BASIC_SCENE));
		engine.SetNextScene(ConvertSceneEnum(Scenes::BASIC_SCENE));

		while (!engine.IsDone())
		{
			engine.Update();
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}
	return 0;
}