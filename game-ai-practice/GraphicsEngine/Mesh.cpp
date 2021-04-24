#include "Mesh.h"

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
	glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 0, nullptr);

	glBindVertexArray(0);
}

void Mesh::Draw() noexcept
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glBindVertexArray(0);
}

void Mesh::Clear() noexcept
{
	vertices.clear();
	color = vec3{ 0.0 };

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

void Mesh::AddVertex(const vec2& v) noexcept
{
	vertices.push_back(v);
}

void Mesh::SetColor(const vec3& c) noexcept
{
	color = c;
}
	 
void Mesh::SetTranslation(const vec2& v) noexcept
{
	translation = v;
}

void Mesh::SetScale(const vec2& v) noexcept
{
	scale = v;
}

void Mesh::SetRotation(double radian) noexcept
{
	rotation = radian;
}

void Mesh::AddTranslation(const vec2& v) noexcept
{
	translation += v;
}

void Mesh::AddRotation(double radian) noexcept
{
	rotation += radian;
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