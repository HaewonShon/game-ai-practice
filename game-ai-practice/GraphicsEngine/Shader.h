#pragma once

#include <gl/glew.h>

class Shader
{
public:
	void Init();
	void Bind();
	void Unbind();

	// uniforms
	void SetUniformFloat(const GLchar* variableName, float value);
	void SetUniformInt(const GLchar* variableName, int value);
	//void SetUniformVec3(const GLchar* variableName, Vector3 value);
	//void SetUniformMat3(const GLchar* variableName, Matrix3 value);
private:
	GLint GetUniformLocation(const GLchar* variableName);

	GLuint shaderID{};
};