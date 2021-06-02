#pragma once

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

constexpr vec2& vec2::operator*=(float val) noexcept
{
	x *= val;
	y *= val;
	return *this;
}

constexpr vec2& vec2::operator/=(float val) noexcept
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

constexpr vec2 vec2::operator*(float val) noexcept
{
	vec2 v(*this);
	v *= val;
	return v;
}

constexpr vec2 vec2::operator/(float val) noexcept
{
	vec2 v(*this);
	v /= val;
	return v;
}

constexpr bool vec2::operator==(const vec2& rhs) const noexcept
{
	return (x == rhs.x && y == rhs.y);
}

constexpr bool vec2::operator!=(const vec2& rhs) const noexcept
{
	return !(*this == rhs);
}

constexpr float vec2::GetLengthSquared() const noexcept
{
	return x * x + y * y;
}

float vec2::GetLength() const noexcept
{
	return std::sqrt(GetLengthSquared());
}

vec2 vec2::GetNormalized() const noexcept
{
	return vec2(*this) / GetLength();
}

vec2 vec2::GetRotated(double radians) const noexcept
{
	float cosVal{ static_cast<float>(std::cos(radians)) };
	float sinVal{ static_cast<float>(std::sin(radians)) };

	return vec2{ cosVal * x - sinVal * y, sinVal * x + cosVal * y };
}