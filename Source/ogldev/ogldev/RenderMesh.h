#pragma once

#include "RenderObject.h"

class RenderGeometry;
class RenderMaterial;

class RenderMesh : public RenderObject
{
private:
	RenderGeometry* geometry;
	RenderMaterial* material;
	int render_order;
	bool transparent;

public:
	RenderMesh();
	RenderMesh(RenderGeometry* geometry, RenderMaterial* material);
	~RenderMesh();

	void setGeometry(RenderGeometry* geometry);
	void setMaterial(RenderMaterial* material);
	void setTransparent(bool transparent);

	RenderGeometry* getGeometry();
	RenderMaterial* getMaterial();
	bool getTransparent();
};
