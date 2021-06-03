#include "GameObject.h"
#include "Shader.h"
#include "Engine.h"

GameObject::GameObject(std::string name)
	: name(name)
{
	mesh = mesh::CreateSquare();
}

GameObject::GameObject(std::string name, vec2 position)
	: name(name), translation(position)
{
	mesh = mesh::CreateSquare();
}

void GameObject::Update(float dt)
{
	translation += velocity * dt;
}

void GameObject::Draw()
{
	if (mesh.GetID() == 0)
	{
		std::string errorMsg = name + "'s mesh drawn without initialize";
		throw std::runtime_error(errorMsg);
	}
	Shader& shader = Engine::GetShader();
	shader.SetUniformVec3("color", color);
	shader.SetUniformMat3("TRS", TRS);
	mesh.Draw();
}

const std::string& GameObject::GetName() const noexcept
{
	return name;
}

bool GameObject::IsDead() const noexcept
{
	return isDead;
}

void GameObject::SetColor(float r, float g, float b) noexcept
{
	color.x = r;
	color.y = g;
	color.z = b;
}

void GameObject::SetColor(const vec3& c) noexcept
{
	color = c;
}

void GameObject::SetTranslation(const vec2& v) noexcept
{
	translation = v;
	UpdateMatrix();
}

void GameObject::SetScale(const vec2& v) noexcept
{
	scale = v;
	UpdateMatrix();
}

void GameObject::SetRotation(double radian) noexcept
{
	rotation = radian;
	UpdateMatrix();
}

void GameObject::SetVelocity(const vec2& v) noexcept
{
	velocity = v;
}

void GameObject::AddTranslation(const vec2& v) noexcept
{
	translation += v;
	UpdateMatrix();
}

void GameObject::AddRotation(double radian) noexcept
{
	rotation += radian;
	UpdateMatrix();
}

void GameObject::AddVelocity(const vec2& v) noexcept
{
	velocity += v;
}

vec2 GameObject::GetTranslation() const noexcept
{
	return translation;
}

vec2 GameObject::GetScale() const noexcept
{
	return scale;
}

double GameObject::GetRotation() const noexcept
{
	return rotation;
}

vec2 GameObject::GetVelocity() const noexcept
{
	return velocity;
}

mat3& GameObject::GetTRS() noexcept
{
	return TRS;
}

void GameObject::UpdateMatrix() noexcept
{
	TRS = matrix3::Scale(scale)
		* matrix3::Rotate(rotation)
		* matrix3::Translate(translation);
}
