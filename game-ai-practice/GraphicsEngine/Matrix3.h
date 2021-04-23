#pragma once

#include "Vector2.h"
#include "Vector3.h"

struct [[nodiscard]] matrix3
{
	double element[3][3];

	matrix3() = default;
	constexpr matrix3(double val);
	constexpr matrix3(const vec3& col1, const vec3& col2, const vec3& col3);

	constexpr double& operator()(int column, int row);
	constexpr double operator()(int column, int row) const;

	constexpr matrix3& operator+=(const matrix3& rhs) noexcept;
	constexpr matrix3& operator-=(const matrix3& rhs) noexcept;
	constexpr matrix3& operator*=(double rhs) noexcept;
	constexpr matrix3& operator/=(double rhs) noexcept;
		 
	constexpr matrix3 operator+(const matrix3& rhs) noexcept;
	constexpr matrix3 operator-(const matrix3& rhs) noexcept;
	constexpr matrix3 operator*(double rhs) noexcept;
	constexpr matrix3 operator/(double rhs) noexcept;
	
	[[nodiscard]] constexpr bool operator==(const matrix3& rhs) noexcept;
	[[nodiscard]] constexpr bool operator!=(const matrix3& rhs) noexcept;
};

namespace
{
	constexpr matrix3 Translation(const vec2& t) noexcept;
	constexpr matrix3 Scale(const vec2& s) noexcept;
	matrix3 rotation(double radian) noexcept;
}

#include "Matrix3.inl"