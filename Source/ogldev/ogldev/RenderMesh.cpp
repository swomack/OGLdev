#include "RenderMesh.h"

using namespace std;

RenderMesh::RenderMesh(string name) :	RenderObject(name), 
										geometry(NULL), material(NULL), 
										render_order(0),transparent(false)
{
}

RenderMesh::RenderMesh(RenderGeometry * geometry, RenderMaterial * material, string name) 
	:	RenderObject(name), geometry(geometry), material(material), 
		render_order(0), transparent(false)
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

void RenderMesh::setTransparent(bool transparent)
{
	this->transparent = transparent;
}

RenderGeometry * RenderMesh::getGeometry()
{
	return this->geometry;
}

RenderMaterial * RenderMesh::getMaterial()
{
	return this->material;
}

bool RenderMesh::getTransparent()
{
	return this->transparent;
}
