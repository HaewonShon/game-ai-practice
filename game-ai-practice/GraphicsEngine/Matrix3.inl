#pragma once

#include <cmath>
#include <stdexcept>

constexpr mat3::mat3(float val) : mat3()
{
	element[0][0] = val;
	element[1][1] = val;
	element[2][2] = val;
}

constexpr mat3::mat3(const vec3& col1, const vec3& col2, const vec3& col3) : mat3()
{
	element[0][0] = col1.x;
	element[0][1] = col1.y;
	element[0][2] = col1.z;

	element[1][0] = col2.x;
	element[1][1] = col2.y;
	element[1][2] = col2.z;

	element[2][0] = col3.x;
	element[2][1] = col3.y;
	element[2][2] = col3.z;
}

constexpr float& mat3::operator()(int column, int row)
{
	if ((column < 0 || column >= 3) || (row < 0 || column >= 3))
	{
		throw std::runtime_error("matrix3 out of range");
	}
	else
	{
		return element[column][row];
	}
}

constexpr float mat3::operator()(int column, int row) const
{
	if ((column < 0 || column >= 3) || (row < 0 || column >= 3))
	{
		throw std::runtime_error("matrix3 out of range");
	}
	else
	{
		return element[column][row];
	}
}


constexpr mat3& mat3::operator+=(const mat3& rhs) noexcept
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			element[i][j] += rhs(i, j);
		}
	}
	return *this;
}

constexpr mat3& mat3::operator-=(const mat3& rhs) noexcept
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			element[i][j] -= rhs(i, j);
		}
	}
	return *this;
}

constexpr mat3& mat3::operator*=(float val) noexcept
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			element[i][j] *= val;
		}
	}
	return *this;
}

constexpr mat3& mat3::operator/=(float val) noexcept
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			element[i][j] /= val;
		}
	}
	return *this;
}

constexpr mat3 mat3::operator+(const mat3& rhs) noexcept
{
	mat3 m(*this);
	m += rhs;
	return m;
}

constexpr mat3 mat3::operator-(const mat3& rhs) noexcept
{
	mat3 m(*this);
	m -= rhs;
	return m;
}

constexpr mat3 mat3::operator*(float val) noexcept
{
	mat3 m(*this);
	m *= val;
	return m;
}

constexpr mat3 mat3::operator/(float val) noexcept
{
	mat3 m(*this);
	m /= val;
	return m;
}

constexpr bool mat3::operator==(const mat3& rhs) noexcept
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (element[i][j] != rhs(i, j))
			{
				return false;
			}
		}
	}
	return true;
}

constexpr bool mat3::operator!=(const mat3& rhs) noexcept
{
	return (*this == rhs);
}

constexpr mat3& mat3::operator*=(const mat3& rhs) noexcept
{
	mat3 mul{1.0};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mul(i, j) = 0;
			for (int k = 0; k < 3; k++)
			{
				mul(i, j) += (*this)(i, k) * rhs(k, j);
			}
		}
	}
	*this = mul;
	return *this;
}

constexpr mat3 mat3::operator*(const mat3& rhs) noexcept
{
	mat3 m(*this);
	m *= rhs;
	return m;
}

namespace matrix3
{
	constexpr mat3 Translate(const vec2& t) noexcept
	{
		mat3 m(1.f);
		m(2, 0) = t.x;
		m(2, 1) = t.y;
		return m;
	}
	constexpr mat3 Scale(const vec2& s) noexcept
	{
		mat3 m(1.f);
		m(0, 0) = s.x;
		m(1, 1) = s.y;
		return m;
	}
	mat3 Rotate(double radian) noexcept
	{
		float cosVal = static_cast<float>(std::cos(radian));
		float sinVal = static_cast<float>(std::sin(radian));
		mat3 m(1.f);
		m(0, 0) = cosVal;
		m(1, 1) = cosVal;
		m(1, 0) = -sinVal;
		m(0, 1) = sinVal;
		return m;
	}
}