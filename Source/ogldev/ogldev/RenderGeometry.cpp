#include "RenderGeometry.h"
#include <algorithm>

using namespace std;

RenderGeometry::RenderGeometry()
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

