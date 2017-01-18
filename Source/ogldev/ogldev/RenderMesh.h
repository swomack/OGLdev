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
	RenderMesh(std::string name = "");
	RenderMesh(RenderGeometry* geometry, RenderMaterial* material, std::string name = "");
	~RenderMesh();

	void setGeometry(RenderGeometry* geometry);
	void setMaterial(RenderMaterial* material);
	void setTransparent(bool transparent);

	RenderGeometry* getGeometry();
	RenderMaterial* getMaterial();
	bool getTransparent();
};
