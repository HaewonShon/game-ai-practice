#pragma once

#include "Vector2.h"
#include "Vector3.h"

struct [[nodiscard]] mat3
{
	double element[3][3];

	inline mat3() = default;
	inline constexpr mat3(double val);
	inline constexpr mat3(const vec3& col1, const vec3& col2, const vec3& col3);
	 
	inline constexpr double& operator()(int column, int row);
	inline constexpr double operator()(int column, int row) const;
	 
	inline constexpr mat3& operator+=(const mat3& rhs) noexcept;
	inline constexpr mat3& operator-=(const mat3& rhs) noexcept;
	inline constexpr mat3& operator*=(double rhs) noexcept;
	inline constexpr mat3& operator/=(double rhs) noexcept;
	inline constexpr mat3& operator*=(const mat3& rhs) noexcept;
	 	 
	inline constexpr mat3 operator+(const mat3& rhs) noexcept;
	inline constexpr mat3 operator-(const mat3& rhs) noexcept;
	inline constexpr mat3 operator*(double rhs) noexcept;
	inline constexpr mat3 operator/(double rhs) noexcept;
	inline constexpr mat3 operator*(const mat3& rhs) noexcept;
	 
	inline [[nodiscard]] constexpr bool operator==(const mat3& rhs) noexcept;
	inline [[nodiscard]] constexpr bool operator!=(const mat3& rhs) noexcept;

	inline double* GetElementPtr() { return &element[0][0]; }
};

namespace matrix3
{
	inline constexpr mat3 Translate(const vec2& t) noexcept;
	inline constexpr mat3 Scale(const vec2& s) noexcept;
	inline mat3 Rotate(double radian) noexcept;
}

#include "Matrix3.inl"