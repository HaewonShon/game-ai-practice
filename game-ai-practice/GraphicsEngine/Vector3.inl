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

constexpr vec3& vec3::operator*=(double val) noexcept
{
	x *= val;
	y *= val;
	z *= val;
	return *this;
}

constexpr vec3& vec3::operator/=(double val) noexcept
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

constexpr vec3 vec3::operator*(double val) noexcept
{
	vec3 v(*this);
	v *= val;
	return v;
}

constexpr vec3 vec3::operator/(double val) noexcept
{
	vec3 v(*this);
	v /= val;
	return v;
}

constexpr bool vec3::operator==(const vec3& rhs) noexcept
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

constexpr bool vec3::operator!=(const vec3& rhs) noexcept
{
	return !(*this == rhs);
}

constexpr double vec3::GetLengthSquared() noexcept
{
	return x * x + y * y + z * z;
}

vec3 vec3::GetNormalized() noexcept
{
	return vec3(*this) / std::sqrt(GetLengthSquared());
}