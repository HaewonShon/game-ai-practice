#pragma once

	struct [[nodiscard]] vec2
	{
		double x{ .0 };
		double y{ .0 };

		inline vec2() = default;
		inline vec2(double val) : vec2(val, val) {}
		inline vec2(double _x, double _y) : x(_x), y(_y) {}
		 
		inline constexpr vec2& operator+=(const vec2& rhs) noexcept;
		inline constexpr vec2& operator-=(const vec2& rhs) noexcept;
		inline constexpr vec2& operator*=(double val) noexcept;
		inline constexpr vec2& operator/=(double val) noexcept;
		 
		inline constexpr vec2 operator+(const vec2& rhs) noexcept;
		inline constexpr vec2 operator-(const vec2& rhs) noexcept;
		inline constexpr vec2 operator*(double val) noexcept;
		inline constexpr vec2 operator/(double val) noexcept;
		 
		inline [[nodiscard]] constexpr bool operator==(const vec2& rhs) noexcept;
		inline [[nodiscard]] constexpr bool operator!=(const vec2& rhs) noexcept;
		 
		inline [[nodiscard]] constexpr double GetLengthSquared() noexcept;
		inline vec2 GetNormalized() noexcept;
		inline vec2 GetRotated(double radians) noexcept;
	};

#include "Vector2.inl"