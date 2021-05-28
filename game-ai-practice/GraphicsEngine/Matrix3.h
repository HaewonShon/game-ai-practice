#pragma once

#include "Vector2.h"
#include "Vector3.h"

struct [[nodiscard]] mat3
{
	float element[3][3];

	inline mat3() = default;
	inline constexpr mat3(float val);
	inline constexpr mat3(const vec3& col1, const vec3& col2, const vec3& col3);
	 
	inline constexpr float& operator()(int column, int row);
	inline constexpr float operator()(int column, int row) const;
	 
	inline constexpr mat3& operator+=(const mat3& rhs) noexcept;
	inline constexpr mat3& operator-=(const mat3& rhs) noexcept;
	inline constexpr mat3& operator*=(float rhs) noexcept;
	inline constexpr mat3& operator/=(float rhs) noexcept;
	inline constexpr mat3& operator*=(const mat3& rhs) noexcept;
	 	 
	inline constexpr mat3 operator+(const mat3& rhs) noexcept;
	inline constexpr mat3 operator-(const mat3& rhs) noexcept;
	inline constexpr mat3 operator*(float rhs) noexcept;
	inline constexpr mat3 operator/(float rhs) noexcept;
	inline constexpr mat3 operator*(const mat3& rhs) noexcept;
	 
	inline [[nodiscard]] constexpr bool operator==(const mat3& rhs) noexcept;
	inline [[nodiscard]] constexpr bool operator!=(const mat3& rhs) noexcept;

	inline float* GetElementPtr() { return &element[0][0]; }
};

namespace matrix3
{
	inline constexpr mat3 Translate(const vec2& t) noexcept;
	inline constexpr mat3 Scale(const vec2& s) noexcept;
	inline mat3 Rotate(double radian) noexcept;
}

#include "Matrix3.inl"