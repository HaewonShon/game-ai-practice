#include "BasicScene.h"

void BasicScene::Init()
{
	triangle = mesh::CreateTriangle({0.5, 0.5, 1.0});
	triangle.Init();

	triangle.SetScale({2., 2.});
	triangle.SetColor({1., 1., 0.});
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