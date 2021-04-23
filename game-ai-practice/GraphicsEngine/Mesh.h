#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include <vector>

#include <gl/glew.h>

class Mesh
{
public:
	~Mesh() noexcept;

	void Init() noexcept;
	void Draw() noexcept;
	void Clear() noexcept;

	void AddVertex(const vec2& v) noexcept;
	void SetColor(const vec3& c) noexcept;
	
	void SetTranslation(const vec2& v) noexcept;
	void SetScale(const vec2& v) noexcept;
	void SetRotation(double radian) noexcept;
	
	void AddTranslation(const vec2& v) noexcept;
	void AddRotation(double radian) noexcept;

private:
	std::vector<vec2> vertices;
	vec3 color{};

	vec2 translation{};
	vec2 scale{};
	double rotation{};

	GLuint vao{};
	GLuint vbo{};
};