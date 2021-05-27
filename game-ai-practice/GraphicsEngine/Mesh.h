#pragma once

#include "Matrix3.h"
#include <vector>

#include <gl/glew.h>

struct Color
{
	Color(float c) : r(c), g(c), b(c) {}
	float r, g, b;
};

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
	void SetColor(const Color& c) noexcept;
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
	Color color{0.f};
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
	Mesh CreateTriangle(const Color& color) noexcept;
	Mesh CreateCircle(const Color& color) noexcept;
	Mesh CreateSquare(const Color& color) noexcept;
}