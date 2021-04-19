#pragma once

#include "../GraphicsEngine/IScene.h"

// temp
#include <gl/glew.h>

class BasicScene : public IScene
{
public:
	void Init() override;
	void Update(double dt) override;
	void DrawObjects() override;
	void DrawGUI() override;

private:
	GLuint tempVAO, tempVBO;
};