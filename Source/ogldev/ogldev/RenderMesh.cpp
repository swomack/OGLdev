#include "RenderMesh.h"

RenderMesh::RenderMesh() : geometry(NULL), material(NULL)
{
}

RenderMesh::RenderMesh(RenderGeometry * geometry, RenderMaterial * material) : geometry(geometry),
																				material(material)
{
}

RenderMesh::~RenderMesh()
{
	
}

void RenderMesh::setGeometry(RenderGeometry * geometry)
{
	this->geometry = geometry;
}

void RenderMesh::setMaterial(RenderMaterial * material)
{
	this->material = material;
}
