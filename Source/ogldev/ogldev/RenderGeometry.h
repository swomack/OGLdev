#pragma once

#include "GodObject.h"
#include "Math3D.h"
#include <vector>

struct vertex_attributes
{
	std::vector<Vector3> positions;
};

class RenderGeometry : public GodObject
{
public:
	RenderGeometry();
	~RenderGeometry();

	void setPosition(std::vector<Vector3> positions);
	void setPosition(Vector3 *positions, int n);

public:

	vertex_attributes geometry_vertex_attributes;
};

