#include "BasicScene.h"

void BasicScene::Init()
{
	triangle.AddVertex({ 0.0, 0.5 });
	triangle.AddVertex({ -0.5, -0.5 });
	triangle.AddVertex({ 0.5, -0.5 });

	triangle.SetColor({ 0.5, 0.5, 1.0 });

	triangle.Init();
}

void BasicScene::Update([[maybe_unused]] double dt)
{

}

void BasicScene::DrawObjects()
{
	triangle.Draw();
}

void BasicScene::DrawGUI()
{
}