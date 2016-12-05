#pragma once

#include "RenderObject.h"

class RenderGeometry;
class RenderMaterial;

class RenderMesh : public RenderObject
{
private:
	RenderGeometry* geometry;
	RenderMaterial* material;

public:
	RenderMesh();
	RenderMesh(RenderGeometry* geometry, RenderMaterial* material);
	~RenderMesh();

	void setGeometry(RenderGeometry* geometry);
	void setMaterial(RenderMaterial* material);
};
