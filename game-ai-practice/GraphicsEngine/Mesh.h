#pragma once

#include "Matrix3.h"
#include <vector>

#include <gl/glew.h>

class Mesh
{
public:
	enum class Mode
	{
		TRIANGLES, TRIANGLE_STRIP, TRIANGLE_FAN,
	};

	~Mesh() noexcept;

	void Init() noexcept;
	void Draw() noexcept;
	void Clear() noexcept;

	void AddVertex(const vec2& v) noexcept;
	void SetColor(float r, float g, float b) noexcept;
	void SetColor(const vec3& c) noexcept;
	void SetMode(Mesh::Mode m) noexcept;
	
	void SetTranslation(const vec2& v) noexcept;
	void SetScale(const vec2& v) noexcept;
	void SetRotation(double radian) noexcept;
	
	void AddTranslation(const vec2& v) noexcept;
	void AddRotation(double radian) noexcept;

	mat3& GetTRS() noexcept;
private:
	void UpdateMatrix() noexcept;

	std::vector<vec2> vertices;
	vec3 color{0.f};
	GLuint mode;

	vec2 translation{0.0};
	vec2 scale{1.0};
	double rotation{0.0};

	mat3 TRS{1.0};

	GLuint vao{};
	GLuint vbo{};
};

namespace mesh
{
	Mesh CreateTriangle(const vec3& color) noexcept;
	Mesh CreateCircle(const vec3& color) noexcept;
	Mesh CreateSquare(const vec3& color) noexcept;
}