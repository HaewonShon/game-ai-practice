#pragma once

struct [[nodiscard]] vec2
{
	float x{ .0 };
	float y{ .0 };

	inline vec2() = default;
	inline vec2(float val) : vec2(val, val) {}
	inline vec2(float _x, float _y) : x(_x), y(_y) {}
		 
	inline constexpr vec2& operator+=(const vec2& rhs) noexcept;
	inline constexpr vec2& operator-=(const vec2& rhs) noexcept;
	inline constexpr vec2& operator*=(float val) noexcept;
	inline constexpr vec2& operator/=(float val) noexcept;
		 
	inline constexpr vec2 operator+(const vec2& rhs) noexcept;
	inline constexpr vec2 operator-(const vec2& rhs) noexcept;
	inline constexpr vec2 operator*(float val) noexcept;
	inline constexpr vec2 operator/(float val) noexcept;
		 
	inline [[nodiscard]] constexpr bool operator==(const vec2& rhs) const noexcept;
	inline [[nodiscard]] constexpr bool operator!=(const vec2& rhs) const noexcept;
		 
	inline [[nodiscard]] constexpr float GetLengthSquared() const noexcept;
	inline float GetLength() const noexcept;
	inline vec2 GetNormalized() const noexcept;
	inline vec2 GetRotated(double radians) const noexcept;
};

#include "Vector2.inl"