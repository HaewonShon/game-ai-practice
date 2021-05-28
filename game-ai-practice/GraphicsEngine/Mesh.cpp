#include "Mesh.h"
#include "constants.h" // PI
#include "Engine.h" // GetShader

Mesh::~Mesh() noexcept
{
	Clear();
}

void Mesh::Init() noexcept
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo); // TODO : Change number of buffer to generate

	glBindVertexArray(vao);

	// vertex
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vec2), vertices.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindVertexArray(0);
}

void Mesh::Draw() noexcept
{
	Shader& shader = Engine::GetShader();

	glBindVertexArray(vao);

	//shader.SetUniformMat3("TRS", TRS);
	shader.SetUniformVec3("color", color);
	shader.SetUniformMat3("TRS", TRS);
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertices.size()));

	glBindVertexArray(0);
}

void Mesh::Clear() noexcept
{
	vertices.clear();

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

void Mesh::AddVertex(const vec2& v) noexcept
{
	vertices.push_back(v);
}

void Mesh::SetColor(float r, float g, float b) noexcept
{
	color.x = r;
	color.y = g;
	color.z = b;
}

void Mesh::SetColor(const vec3& c) noexcept
{
	color = c;
}

void Mesh::SetMode(Mesh::Mode m) noexcept
{
	switch (m)
	{
	case Mode::TRIANGLES:
		mode = GL_TRIANGLES;
		break;
	case Mode::TRIANGLE_FAN:
		mode = GL_TRIANGLE_FAN;
		break;
	case Mode::TRIANGLE_STRIP:
		mode = GL_TRIANGLE_STRIP;
		break;
	}
}
	 
void Mesh::SetTranslation(const vec2& v) noexcept
{
	translation = v;
	UpdateMatrix();
}

void Mesh::SetScale(const vec2& v) noexcept
{
	scale = v;
	UpdateMatrix();
}

void Mesh::SetRotation(double radian) noexcept
{
	rotation = radian;
	UpdateMatrix();
}

void Mesh::AddTranslation(const vec2& v) noexcept
{
	translation += v;
	UpdateMatrix();
}

void Mesh::AddRotation(double radian) noexcept
{
	rotation += radian;
	UpdateMatrix();
}

mat3& Mesh::GetTRS() noexcept
{
	return TRS;
}

void Mesh::UpdateMatrix() noexcept
{
	TRS = matrix3::Scale(scale)
		* matrix3::Rotate(rotation)
		* matrix3::Translate(translation);
}

namespace mesh
{
	Mesh CreateTriangle(const vec3& color) noexcept
	{
		Mesh triangle;
		triangle.AddVertex({ 0.f, 0.5f });
		triangle.AddVertex({ -0.5f, -0.5f });
		triangle.AddVertex({ 0.5f, -0.5f });
		triangle.SetColor(color);
		triangle.SetMode(Mesh::Mode::TRIANGLES);
		return triangle;
	}

	Mesh CreateCircle(const vec3& color) noexcept
	{
		Mesh circle;
		circle.AddVertex({ 0.0f, 0.0f });
		double angle_gap = 2.0 * PI / 32.0;
		for (int i = 0; i <= 32; ++i)
		{
			circle.AddVertex(
				vec2{static_cast<float>(std::cos(angle_gap * i)), 
				static_cast<float>(std::sin(angle_gap * i))} * 0.5f);
		}
		circle.SetColor(color);
		circle.SetMode(Mesh::Mode::TRIANGLE_STRIP);
		return circle;
	}
	Mesh CreateSquare(const vec3& color) noexcept
	{
		Mesh square;
		square.AddVertex({-0.5f, 0.5f});
		square.AddVertex({ 0.5f, 0.5f });
		square.AddVertex({ -0.5f, -0.5f });
		square.AddVertex({ 0.5f, 0.5f });
		square.AddVertex({ -0.5f, -0.5f });
		square.AddVertex({ 0.5f, -0.5f });
		square.SetColor(color);
		square.SetMode(Mesh::Mode::TRIANGLE_STRIP);
		return square;
	}
}