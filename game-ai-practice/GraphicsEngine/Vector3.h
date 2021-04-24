#pragma once
#include "Vector2.h"

struct [[nodiscard]] vec3
{
	double x{ .0 };
	double y{ .0 };
	double z{ .0 };

	inline vec3() = default;
	inline vec3(double val) : vec3(val, val, val) {}
	inline vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
	inline vec3(const vec2& v, double _z) : vec3(v.x, v.y, _z) {}
	inline vec3(const vec2& v) : vec3(v, 0.0) {}
	 
	inline constexpr vec3& operator+=(const vec3& rhs) noexcept;
	inline constexpr vec3& operator-=(const vec3& rhs) noexcept;
	inline constexpr vec3& operator*=(double val) noexcept;
	inline constexpr vec3& operator/=(double val) noexcept;
	 
	inline constexpr vec3 operator+(const vec3& rhs) noexcept;
	inline constexpr vec3 operator-(const vec3& rhs) noexcept;
	inline constexpr vec3 operator*(double val) noexcept;
	inline constexpr vec3 operator/(double val) noexcept;
	 
	inline [[nodiscard]] constexpr bool operator==(const vec3& rhs) noexcept;
	inline [[nodiscard]] constexpr bool operator!=(const vec3& rhs) noexcept;
	 
	inline [[nodiscard]] constexpr double GetLengthSquared() noexcept;
	inline vec3 GetNormalized() noexcept;
};

#include "Vector3.inl"