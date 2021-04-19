#include "BasicScene.h"
#include <array>

void BasicScene::Init()
{
	GLfloat VERTICES[9] = { 
		-0.5F, -0.5F, 0.0F,
		0.5F, -0.5F, 0.0F,
		0.0F, 0.5F, 0.0F
	};

	glGenVertexArrays(1, &tempVAO);
	glGenBuffers(1, &tempVBO);

	glBindVertexArray(tempVAO);
	glBindBuffer(GL_ARRAY_BUFFER, tempVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VERTICES), &VERTICES[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void BasicScene::Update([[maybe_unused]]double dt)
{}

void BasicScene::DrawObjects()
{
	glBindVertexArray(tempVAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void BasicScene::DrawGUI()
{}