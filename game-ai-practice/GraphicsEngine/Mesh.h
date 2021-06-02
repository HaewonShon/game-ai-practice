#pragma once

#include "Vector2.h"
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
	void SetMode(Mesh::Mode m) noexcept;

	GLuint GetID() const noexcept;
	
private:

	std::vector<vec2> vertices;
	GLuint mode;

	GLuint vao{};
	GLuint vbo{};
};

namespace mesh
{
	Mesh CreateTriangle() noexcept;
	Mesh CreateCircle() noexcept;
	Mesh CreateSquare() noexcept;
}