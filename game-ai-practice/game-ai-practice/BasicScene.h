#pragma once

#include "../GraphicsEngine/IScene.h"
//#include "../GraphicsEngine/GameObject.h"

class GameObject;

class BasicScene : public IScene
{
public:
	~BasicScene();
	void Init() override;
	void Update(double dt) override;
	void DrawObjects() override;
	void DrawGUI() override;
private:
	GameObject* triangle;
};