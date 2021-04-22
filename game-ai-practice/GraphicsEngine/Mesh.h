#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include <vector>

class Mesh
{
public:
	void AddVertex(const vec2& v);
	void SetColor(const vec3& c);

	void SetTranslation(const vec2& v);
	void SetScale(const vec2& v);
	void SetRotation(double radian);
private:
	std::vector<vec2> vertices;
	vec3 color;

	vec2 translation;
	vec2 scale;
	double rotation;
};