#pragma once

#include "GodObject.h"
#include "Math3D.h"

#include <vector>
#include <string>

class RenderObject : public GodObject
{
private:
	std::vector<RenderObject*> children;
	RenderObject* parent;
	std::string name;

public:
	RenderObject(std::string name = "");
	~RenderObject();

	virtual void setParent(RenderObject* parent_object);
	virtual void addChild(RenderObject* child_object);
	virtual void removeChild(RenderObject* child_object);
	virtual RenderObject* getObjectByName(std::string name);


	std::string getName();
	std::vector<RenderObject*>& getChildren();

	void setPosition(float x, float y, float z);
	void setPosition(const Vector3& position);
	void updateMatrix();
	void updateWorldMatrix();

protected:
	Vector3 position;
	Matrix4f local_matrix;
	Matrix4f world_matrix;
};
