#pragma once

#include <string>
#include "Matrix3.h"
#include "Mesh.h"

class GameObject
{
public:
	GameObject(std::string name);
	GameObject(std::string name, vec2 position);

	void Update(float dt);
	void Draw();

	void SetColor(float r, float g, float b) noexcept;
	void SetColor(const vec3& c) noexcept;

	void SetTranslation(const vec2& v) noexcept;
	void SetScale(const vec2& v) noexcept;
	void SetRotation(double radian) noexcept;

	void AddTranslation(const vec2& v) noexcept;
	void AddRotation(double radian) noexcept;

	vec2 GetTranslation() const noexcept;
	vec2 GetScale() const noexcept;
	double GetRotation() const noexcept;

	mat3& GetTRS() noexcept;

protected:
	void UpdateMatrix() noexcept;

	std::string name;

	Mesh mesh;

	// color to draw
	vec3 color{ 0.f };

	// TRS information
	vec2 translation{ 0.f };
	vec2 velocity{ 0.f };
	vec2 scale{ 100.f };
	double rotation{ 0.f };

	mat3 TRS{ 1.0 };

private:
	GameObject(const GameObject&) = delete;
	GameObject(GameObject&&) = delete;
	GameObject& operator=(const GameObject&) = delete;
	GameObject& operator=(GameObject&&) = delete;
};