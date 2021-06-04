#pragma once

#include <string>
#include "Matrix3.h"
#include "Mesh.h"

class GameObject
{
public:
	GameObject(std::string name);
	GameObject(std::string name, vec2 position);

	virtual void Update(float dt);
	virtual void Draw();

	const std::string& GetName() const noexcept;
	bool IsDead() const noexcept;

	void SetColor(float r, float g, float b) noexcept;
	void SetColor(const vec3& c) noexcept;

	void SetTranslation(const vec2& v) noexcept;
	void SetScale(const vec2& v) noexcept;
	void SetRotation(double radian) noexcept;
	void SetVelocity(const vec2& v) noexcept;

	void AddTranslation(const vec2& v) noexcept;
	void AddRotation(double radian) noexcept;
	void AddVelocity(const vec2& v) noexcept;

	vec2 GetTranslation() const noexcept;
	vec2 GetScale() const noexcept;
	double GetRotation() const noexcept;
	vec2 GetVelocity() const noexcept;

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

	bool isDead{ false };

private:
	GameObject(const GameObject&) = delete;
	GameObject(GameObject&&) = delete;
	GameObject& operator=(const GameObject&) = delete;
	GameObject& operator=(GameObject&&) = delete;
};