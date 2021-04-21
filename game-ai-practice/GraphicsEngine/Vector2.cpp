#include "Vector2.h"
#include <cmath>
#include <stdexcept>

constexpr vec2& vec2::operator+=(const vec2& rhs) noexcept
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

constexpr vec2& vec2::operator-=(const vec2& rhs) noexcept
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

constexpr vec2& vec2::operator*=(double val) noexcept
{
	x *= val;
	y *= val;
	return *this;
}

constexpr vec2& vec2::operator/=(double val) noexcept
{
	x /= val;
	y /= val;
	return *this;
}

constexpr vec2 vec2::operator+(const vec2& rhs) noexcept
{
	vec2 v(*this);
	v += rhs;
	return v;
}

constexpr vec2 vec2::operator-(const vec2& rhs) noexcept
{
	vec2 v(*this);
	v -= rhs;
	return v;
}

constexpr vec2 vec2::operator*(double val) noexcept
{
	vec2 v(*this);
	v *= val;
	return v;
}

constexpr vec2 vec2::operator/(double val) noexcept
{
	vec2 v(*this);
	v /= val;
	return v;
}

constexpr bool vec2::operator==(const vec2& rhs) noexcept
{
	return (x == rhs.x && y == rhs.y);
}

constexpr bool vec2::operator!=(const vec2& rhs) noexcept
{
	return !(*this == rhs);
}

constexpr double vec2::GetLengthSquared() noexcept
{
	return x * x + y * y;
}

vec2 vec2::GetNormalized() noexcept
{
	return vec2(*this) / std::sqrt(GetLengthSquared());
}

vec2 vec2::GetRotated(double radians) noexcept
{
	double cosVal{ std::cos(radians) };
	double sinVal{ std::sin(radians) };

	return vec2{cosVal * x - sinVal * y, sinVal * x + cosVal * y};
}