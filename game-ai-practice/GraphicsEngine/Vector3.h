#pragma once
#include "Vector2.h"

struct [[nodiscard]] vec3
{
	float x{ .0 };
	float y{ .0 };
	float z{ .0 };

	inline vec3() = default;
	inline vec3(float val) : vec3(val, val, val) {}
	inline vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	inline vec3(const vec2& v, float _z = 0.f) : vec3(v.x, v.y, _z) {}
	 
	inline constexpr vec3& operator+=(const vec3& rhs) noexcept;
	inline constexpr vec3& operator-=(const vec3& rhs) noexcept;
	inline constexpr vec3& operator*=(float val) noexcept;
	inline constexpr vec3& operator/=(float val) noexcept;
	 
	inline constexpr vec3 operator+(const vec3& rhs) noexcept;
	inline constexpr vec3 operator-(const vec3& rhs) noexcept;
	inline constexpr vec3 operator*(float val) noexcept;
	inline constexpr vec3 operator/(float val) noexcept;
	 
	inline [[nodiscard]] constexpr bool operator==(const vec3& rhs) const noexcept;
	inline [[nodiscard]] constexpr bool operator!=(const vec3& rhs) const noexcept;
	 
	inline [[nodiscard]] constexpr float GetLengthSquared() const noexcept;
	inline vec3 GetNormalized() const noexcept;
};

float DotProduct(const vec3& v1, const vec3& v2);
float GetAngle(const vec3& v1, const vec3& v2);
vec3 CrossProduct(const vec3& v1, const vec3& v2);

#include "Vector3.inl"