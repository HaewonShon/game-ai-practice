#pragma once
#include "Vector2.h"

struct [[nodiscard]] vec3
{
	double x{ .0 };
	double y{ .0 };
	double z{ .0 };

	vec3() = default;
	vec3(double val) : vec3(val, val, val) {}
	vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
	vec3(const vec2& v, double _z) : vec3(v.x, v.y, _z) {}
	vec3(const vec2& v) : vec3(v, 0.0) {}

	constexpr vec3& operator+=(const vec3& rhs) noexcept;
	constexpr vec3& operator-=(const vec3& rhs) noexcept;
	constexpr vec3& operator*=(double val) noexcept;
	constexpr vec3& operator/=(double val) noexcept;

	constexpr vec3 operator+(const vec3& rhs) noexcept;
	constexpr vec3 operator-(const vec3& rhs) noexcept;
	constexpr vec3 operator*(double val) noexcept;
	constexpr vec3 operator/(double val) noexcept;

	[[nodiscard]] constexpr bool operator==(const vec3& rhs) noexcept;
	[[nodiscard]] constexpr bool operator!=(const vec3& rhs) noexcept;

	[[nodiscard]] constexpr double GetLengthSquared() noexcept;
	vec3 GetNormalized() noexcept;
};

#include "Vector3.inl"