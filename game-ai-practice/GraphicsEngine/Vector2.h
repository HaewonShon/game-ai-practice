#pragma once

struct [[nodiscard]] vec2
{
	double x{.0};
	double y{.0};

	vec2() = default;
	vec2(double val) : vec2(val, val) {}
	vec2(double _x, double _y) : x(_x), y(_y) {}

	constexpr vec2& operator+=(const vec2& rhs) noexcept;
	constexpr vec2& operator-=(const vec2& rhs) noexcept;
	constexpr vec2& operator*=(double val) noexcept;
	constexpr vec2& operator/=(double val) noexcept;

	constexpr vec2 operator+(const vec2& rhs) noexcept;
	constexpr vec2 operator-(const vec2& rhs) noexcept;
	constexpr vec2 operator*(double val) noexcept;
	constexpr vec2 operator/(double val) noexcept;

	[[nodiscard]] constexpr bool operator==(const vec2& rhs) noexcept;
	[[nodiscard]] constexpr bool operator!=(const vec2& rhs) noexcept;

	[[nodiscard]] constexpr double GetLengthSquared() noexcept;
	vec2 GetNormalized() noexcept;
	vec2 GetRotated(double radians) noexcept;
};

#include "Vector2.inl"