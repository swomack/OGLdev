#pragma once

#include "GodObject.h"
#include "Math3D.h"
#include "PrimitiveDefinitions.h"
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

	virtual void setPosition(std::vector<Vector3>& positions);
	virtual void setPosition(std::vector<Vector3>&& positions);
	virtual void setPosition(Vector3 *positions, int n);

	virtual unsigned int getNumberofDrawableVertices() const;

	virtual size_t getVerticesPositionAttributeSize();
	virtual Vector3* getVerticesPositionAttributeReference();


	void setPrimitiveType(unsigned int primitive_type);
	unsigned int getPrimitiveType() const;

	void setDrawType(draw_type type);
	draw_type getDrawType() const;

	virtual void setIndices(std::vector<unsigned int>&indices);
	virtual void setIndices(std::vector<unsigned int>&& indices);
	virtual unsigned int* getIndices();

public:

	vertex_attributes geometry_vertex_attributes;

protected:

	unsigned int primitive_type;
	draw_type primitive_draw_type;
	std::vector<unsigned int> indices;
};

