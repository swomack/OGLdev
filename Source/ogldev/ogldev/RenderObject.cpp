#include "RenderObject.h"
#include "RenderGeometry.h"
#include "RenderMaterial.h"
#include "Utility.h"

#include <iostream>
#include <algorithm>

using namespace std;
using namespace ogldev_math_utility;

RenderObject::RenderObject(string name) : parent(NULL), position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1)
{
	this->name = name;

	updateMatrix();
	updateWorldMatrix();
}

RenderObject::~RenderObject()
{

}

void RenderObject::setParent(RenderObject * parent_object)
{
	parent = parent_object;
}

void RenderObject::addChild(RenderObject * child_object)
{
	children.push_back(child_object);
	child_object->setParent(this);
}

void RenderObject::removeChild(RenderObject * child_object)
{
	remove(children.begin(), children.end(), child_object);
	child_object->setParent(NULL);
}

RenderObject * RenderObject::getObjectByName(std::string name)
{
	if (children.size() <= 0)
		return nullptr;

	auto res = find_if(children.begin(), children.end(), [&name](auto element) {
		if (element->getName() == name)
			return true;

		return false;
	});

	if (res != children.end())
		return *res;

	for (int i = 0; i < children.size(); i++)
	{
		auto elem = children[i]->getObjectByName(name);

		if (elem == nullptr)
			continue;

		return elem;
	}

	return nullptr;
}

string RenderObject::getName()
{
	return name;
}

std::vector<RenderObject*>& RenderObject::getChildren()
{
	return this->children;
}

void RenderObject::setPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void RenderObject::setPosition(const Vector3 & position)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->position.z = position.z;
}

void RenderObject::setRotation(float x, float y, float z)
{
	rotation.x = x;
	rotation.y = y;
	rotation.z = z;
}

void RenderObject::rotateX(float x)
{
	rotation.x = x;
}

void RenderObject::rotateY(float y)
{
	rotation.y = y;
}

void RenderObject::rotateZ(float z)
{
	rotation.z = z;
}

void RenderObject::setScale(float x, float y, float z)
{
	scale.x = x;
	scale.y = y;
	scale.z = z;
}

void RenderObject::scaleX(float x)
{
	scale.x = x;
}

void RenderObject::scaleY(float y)
{
	scale.y = y;
}

void RenderObject::scaleZ(float z)
{
	scale.z = z;
}

void RenderObject::updateMatrix()
{
	Matrix4f scale_mat;

	scale_mat.m[0][0] = scale.x;	scale_mat.m[0][1] = 0.0f;		scale_mat.m[0][2] = 0.0f;		scale_mat.m[0][3] = 0.0f;
	scale_mat.m[1][0] = 0.0f;		scale_mat.m[1][1] = scale.y;	scale_mat.m[1][2] = 0.0f;		scale_mat.m[1][3] = 0.0f;
	scale_mat.m[2][0] = 0.0f;		scale_mat.m[2][1] = 0.0f;		scale_mat.m[2][2] = scale.z;	scale_mat.m[2][3] = 0.0f;
	scale_mat.m[3][0] = 0.0f;		scale_mat.m[3][1] = 0.0f;		scale_mat.m[3][2] = 0.0f;		scale_mat.m[3][3] = 1.0f;

	Matrix4f rot_x_mat;

	rot_x_mat.m[0][0] = 1.0f; rot_x_mat.m[0][1] = 0.0f;								rot_x_mat.m[0][2] = 0.0f;							rot_x_mat.m[0][3] = 0.0f;
	rot_x_mat.m[1][0] = 0.0f; rot_x_mat.m[1][1] = cosf(degreeToRad(rotation.x));	rot_x_mat.m[1][2] = -sinf(degreeToRad(rotation.x));	rot_x_mat.m[1][3] = 0.0f;
	rot_x_mat.m[2][0] = 0.0f; rot_x_mat.m[2][1] = sinf(degreeToRad(rotation.x));	rot_x_mat.m[2][2] = cosf(degreeToRad(rotation.x));	rot_x_mat.m[2][3] = 0.0f;
	rot_x_mat.m[3][0] = 0.0f; rot_x_mat.m[3][1] = 0.0f;								rot_x_mat.m[3][2] = 0.0f;							rot_x_mat.m[3][3] = 1.0f;




	Matrix4f rot_y_mat;

	rot_y_mat.m[0][0] = cosf(degreeToRad(rotation.y));	rot_y_mat.m[0][1] = 0.0f;	rot_y_mat.m[0][2] = -sinf(degreeToRad(rotation.y));	rot_y_mat.m[0][3] = 0.0f;
	rot_y_mat.m[1][0] = 0.0f;							rot_y_mat.m[1][1] = 1.0f;	rot_y_mat.m[1][2] = 0.0f;							rot_y_mat.m[1][3] = 0.0f;
	rot_y_mat.m[2][0] = sinf(degreeToRad(rotation.y));	rot_y_mat.m[2][1] = 0.0f;	rot_y_mat.m[2][2] = cosf(degreeToRad(rotation.y));	rot_y_mat.m[2][3] = 0.0f;
	rot_y_mat.m[3][0] = 0.0f;							rot_y_mat.m[3][1] = 0.0f;	rot_y_mat.m[3][2] = 0.0f;							rot_y_mat.m[3][3] = 1.0f;



	Matrix4f rot_z_mat;

	rot_z_mat.m[0][0] = cosf(degreeToRad(rotation.z));	rot_z_mat.m[0][1] = -sinf(degreeToRad(rotation.z));	rot_z_mat.m[0][2] = 0.0f;	rot_z_mat.m[0][3] = 0.0f;
	rot_z_mat.m[1][0] = sinf(degreeToRad(rotation.z));	rot_z_mat.m[1][1] = cosf(degreeToRad(rotation.z));	rot_z_mat.m[1][2] = 0.0f;	rot_z_mat.m[1][3] = 0.0f;
	rot_z_mat.m[2][0] = 0.0f;							rot_z_mat.m[2][1] = 0.0f;							rot_z_mat.m[2][2] = 1.0f;	rot_z_mat.m[2][3] = 0.0f;
	rot_z_mat.m[3][0] = 0.0f;							rot_z_mat.m[3][1] = 0.0f;							rot_z_mat.m[3][2] = 0.0f;	rot_z_mat.m[3][3] = 1.0f;


	Matrix4f translation_mat;

	translation_mat.m[0][0] = 1.0f; translation_mat.m[0][1] = 0.0f; translation_mat.m[0][2] = 0.0f; translation_mat.m[0][3] = position.x;
	translation_mat.m[1][0] = 0.0f; translation_mat.m[1][1] = 1.0f; translation_mat.m[1][2] = 0.0f; translation_mat.m[1][3] = position.y;
	translation_mat.m[2][0] = 0.0f; translation_mat.m[2][1] = 0.0f; translation_mat.m[2][2] = 1.0f; translation_mat.m[2][3] = position.z;
	translation_mat.m[3][0] = 0.0f; translation_mat.m[3][1] = 0.0f; translation_mat.m[3][2] = 0.0f; translation_mat.m[3][3] = 1.0f;

	local_matrix = translation_mat * rot_z_mat * rot_y_mat * rot_x_mat * scale_mat;
}

void RenderObject::updateWorldMatrix()
{
	updateMatrix();
	if (parent == NULL)
	{
		world_matrix.copy(local_matrix);
	}
	else
	{
		world_matrix = parent->world_matrix * local_matrix;
	}

	for_each(children.begin(), children.end(), [](auto element) {
		element->updateWorldMatrix();
	});
}

