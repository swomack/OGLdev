#include "PrimitiveDefinitions.h"
#include "RenderGeometry.h"
#include <algorithm>

using namespace std;

RenderGeometry::RenderGeometry(): primitive_type(POINT_PRIMITIVE)
{
}

RenderGeometry::~RenderGeometry()
{
}

void RenderGeometry::setPosition(std::vector<Vector3> positions)
{
	geometry_vertex_attributes.positions.clear();

	for_each(positions.begin(), positions.end(), [this](auto element) {
		this->geometry_vertex_attributes.positions.push_back(element);
	});
}

void RenderGeometry::setPosition(Vector3 * positions, int n)
{
	geometry_vertex_attributes.positions.clear();

	for (int i = 0; i < n; i++)
		geometry_vertex_attributes.positions.push_back(positions[i]);
}

unsigned int RenderGeometry::getNumberofDrawableVertices()
{
	return geometry_vertex_attributes.positions.size();
}

size_t RenderGeometry::getVerticesPositionAttributeSize()
{
	return sizeof(Vector3) * geometry_vertex_attributes.positions.size();
}

Vector3* RenderGeometry::getVerticesPositionAttributeReference()
{
	return &(geometry_vertex_attributes.positions[0]);
}

void RenderGeometry::setPrimitiveType(unsigned int primitive_type)
{
	this->primitive_type = primitive_type;
}

unsigned int RenderGeometry::getPrimitiveType()
{
	return primitive_type;
}

