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

	void setPosition(float x = 0, float y = 0, float z = 0);
	void setPosition(const Vector3& position);
	void setRotation(float x = 0, float y = 0, float z = 0);
	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);
	void setScale(float x = 1, float y = 1, float z = 1);
	void scaleX(float x);
	void scaleY(float y);
	void scaleZ(float z);
	void updateMatrix();
	void updateWorldMatrix();

protected:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
	Matrix4f local_matrix;
	Matrix4f world_matrix;

	friend class OpenglRenderer;
};
