#include "BasicScene.h"

void BasicScene::Init()
{
	triangle = mesh::CreateSquare({1.f});
	triangle.Init();

	triangle.SetScale({200.f, 200.f});
	triangle.SetColor(1.f, 1.f, 0.f);
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