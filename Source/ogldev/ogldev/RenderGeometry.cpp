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

void RenderGeometry::setPosition(std::vector<Vector3>& positions)
{
	geometry_vertex_attributes.positions.clear();

	for_each(positions.begin(), positions.end(), [this](auto element) {
		this->geometry_vertex_attributes.positions.push_back(element);
	});
}

void RenderGeometry::setPosition(std::vector<Vector3>&& positions)
{
	geometry_vertex_attributes.positions.clear();

	geometry_vertex_attributes.positions = positions;
}

void RenderGeometry::setPosition(Vector3 * positions, int n)
{
	geometry_vertex_attributes.positions.clear();

	for (int i = 0; i < n; i++)
		geometry_vertex_attributes.positions.push_back(positions[i]);
}

unsigned int RenderGeometry::getNumberofDrawableVertices() const
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

size_t RenderGeometry::getIndicesSize()
{
	return sizeof(unsigned int) * indices.size();
}

void RenderGeometry::setPrimitiveType(unsigned int primitive_type)
{
	this->primitive_type = primitive_type;
}

unsigned int RenderGeometry::getPrimitiveType() const
{
	return primitive_type;
}

void RenderGeometry::setDrawType(draw_type type)
{
	primitive_draw_type = type;
}

draw_type RenderGeometry::getDrawType() const
{
	return primitive_draw_type;
}

void RenderGeometry::setIndices(std::vector<unsigned int>& indices)
{
	this->indices.clear();

	for_each(indices.begin(), indices.end(), [this](auto element) {
		this->indices.push_back(element);
	});
}

void RenderGeometry::setIndices(std::vector<unsigned int>&& indices)
{
	this->indices.clear();
	this->indices = indices;
}

unsigned int * RenderGeometry::getIndices()
{
	if (indices.size() <= 0)
		return nullptr;

	return &this->indices[0];
}

