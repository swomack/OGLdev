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

	virtual void setPosition(std::vector<Vector3> positions);
	virtual void setPosition(Vector3 *positions, int n);

	virtual unsigned int getNumberofDrawableVertices();

	void setPrimitiveType(unsigned int primitive_type);

	unsigned int getPrimitiveType();

public:

	vertex_attributes geometry_vertex_attributes;

protected:

	unsigned int primitive_type;
};

