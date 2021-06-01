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

vec3 vec3::GetNormalized() const noexcept
{
	return vec3(*this) / std::sqrt(GetLengthSquared());
}

float DotProduct(const vec3& v1, const vec3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float GetAngle(const vec3& v1, const vec3& v2)
{
	return acos(DotProduct(v1.GetNormalized(), v2.GetNormalized()));
}

vec3 CrossProduct(const vec3& v1, const vec3& v2)
{

}