#include "Matrix3.h"
#include <cmath>
#include <stdexcept>

constexpr matrix3::matrix3(double val) : matrix3()
{
	element[0][0] = 0.0;
	element[1][1] = 0.0;
	element[2][2] = 0.0;
}

constexpr matrix3::matrix3(const vec3& col1, const vec3& col2, const vec3& col3) : matrix3()
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

constexpr double& matrix3::operator()(int column, int row)
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

constexpr double matrix3::operator()(int column, int row) const
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


constexpr matrix3& matrix3::operator+=(const matrix3& rhs) noexcept
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

constexpr matrix3& matrix3::operator-=(const matrix3& rhs) noexcept
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

constexpr matrix3& matrix3::operator*=(double val) noexcept
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

constexpr matrix3& matrix3::operator/=(double val) noexcept
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

constexpr matrix3 matrix3::operator+(const matrix3& rhs) noexcept
{
	matrix3 m(*this);
	m += rhs;
	return m;
}

constexpr matrix3 matrix3::operator-(const matrix3& rhs) noexcept
{
	matrix3 m(*this);
	m -= rhs;
	return m;
}

constexpr matrix3 matrix3::operator*(double val) noexcept
{
	matrix3 m(*this);
	m *= val;
	return m;
}

constexpr matrix3 matrix3::operator/(double val) noexcept
{
	matrix3 m(*this);
	m /= val;
	return m;
}

constexpr bool matrix3::operator==(const matrix3& rhs) noexcept
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

constexpr bool matrix3::operator!=(const matrix3& rhs) noexcept
{
	return (*this == rhs);
}

namespace
{
	constexpr matrix3 Translation(const vec2& t) noexcept
	{
		matrix3 m(1.f);
		m(2, 0) = t.x;
		m(2, 1) = t.y;
		return m;
	}
	constexpr matrix3 Scale(const vec2& s) noexcept
	{
		matrix3 m(1.f);
		m(0, 0) = s.x;
		m(1, 1) = s.y;
		return m;
	}
	matrix3 rotation(double radian) noexcept
	{
		double cosVal = std::cos(radian);
		double sinVal = std::sin(radian);
		matrix3 m(1.f);
		m(0, 0) = cosVal;
		m(1, 1) = cosVal;
		m(1, 0) = -sinVal;
		m(0, 1) = sinVal;
		return m;
	}
}