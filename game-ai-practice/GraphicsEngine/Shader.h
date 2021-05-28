#pragma once

#include <gl/glew.h>
#include "Matrix3.h"
#include "Mesh.h"

class Shader
{
public:
	void Init();
	void Bind() noexcept;
	void Unbind() noexcept;

	// uniforms
	void SetUniformFloat(const GLchar* variableName, float value) noexcept;
	void SetUniformInt(const GLchar* variableName, int value) noexcept;
	void SetUniformVec3(const GLchar* variableName, const vec3& value) noexcept;
	void SetUniformMat3(const GLchar* variableName, const mat3& value) noexcept;
private:
	GLint GetUniformLocation(const GLchar* variableName);

	GLuint shaderID{};
};