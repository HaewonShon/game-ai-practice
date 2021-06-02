#pragma once


float DotProduct(const vec3& v1, const vec3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float DotProduct(const vec2& v1, const vec2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

float GetAngle(const vec3& v1, const vec3& v2)
{
	return acos(DotProduct(v1.GetNormalized(), v2.GetNormalized()));
}


float GetAngle(const vec2& v1, const vec2& v2)
{
	return acos(DotProduct(v1.GetNormalized(), v2.GetNormalized()));
}

vec3 CrossProduct(const vec3& v1, const vec3& v2)
{
	return vec3{ v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v2.x * v1.y };
}