#pragma once
#include "Vector3.h"

float DotProduct(const vec3& v1, const vec3& v2);
float DotProduct(const vec2& v1, const vec2& v2);

float GetAngle(const vec3& v1, const vec3& v2);
float GetAngle(const vec2& v1, const vec2& v2);

vec3 CrossProduct(const vec3& v1, const vec3& v2);

#include "Math.inl"