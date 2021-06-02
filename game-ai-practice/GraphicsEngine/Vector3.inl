#pragma once

#include <cmath>

constexpr vec3& vec3::operator+=(const vec3& rhs) noexcept
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

constexpr vec3& vec3::operator-=(const vec3& rhs) noexcept
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

constexpr vec3& vec3::operator*=(float val) noexcept
{
	x *= val;
	y *= val;
	z *= val;
	return *this;
}

constexpr vec3& vec3::operator/=(float val) noexcept
{
	x /= val;
	y /= val;
	z /= val;
	return *this;
}

constexpr vec3 vec3::operator+(const vec3& rhs) noexcept
{
	vec3 v(*this);
	v += rhs;
	return v;
}

constexpr vec3 vec3::operator-(const vec3& rhs) noexcept
{
	vec3 v(*this);
	v -= rhs;
	return v;
}

constexpr vec3 vec3::operator*(float val) noexcept
{
	vec3 v(*this);
	v *= val;
	return v;
}

constexpr vec3 vec3::operator/(float val) noexcept
{
	vec3 v(*this);
	v /= val;
	return v;
}

constexpr bool vec3::operator==(const vec3& rhs) const noexcept
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

constexpr bool vec3::operator!=(const vec3& rhs) const noexcept
{
	return !(*this == rhs);
}

constexpr float vec3::GetLengthSquared() const noexcept
{
	return x * x + y * y + z * z;
}

float vec3::GetLength() const noexcept
{
	return std::sqrt(GetLengthSquared());
}

vec3 vec3::GetNormalized() const noexcept
{
	return vec3(*this) / GetLength();
}