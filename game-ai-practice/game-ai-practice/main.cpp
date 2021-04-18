#include "../GraphicsEngine/Engine.h"
#include "BasicScene.h"

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
	Engine engine;

	engine.Init();

	engine.RegisterScene<BasicScene>(ConvertSceneEnum(Scenes::BASIC_SCENE));
	engine.SetNextScene(ConvertSceneEnum(Scenes::BASIC_SCENE));

	while (!engine.IsDone())
	{
		engine.Update();
	}
}