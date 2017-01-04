#pragma once

#include "GodObject.h"
#include "Math3D.h"

class RenderMaterial : public GodObject
{
public:
	RenderMaterial();
	~RenderMaterial();

	virtual void setColor(Vector3 color);

protected:
	Vector3 color;
};
