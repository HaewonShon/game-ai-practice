#pragma once

#include "../GraphicsEngine/IScene.h"
#include "../GraphicsEngine/Mesh.h"

class BasicScene : public IScene
{
public:
	void Init() override;
	void Update(double dt) override;
	void DrawObjects() override;
	void DrawGUI() override;

private:
	Mesh triangle;
};