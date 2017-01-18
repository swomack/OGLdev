#include "RenderObject.h"
#include "RenderGeometry.h"
#include "RenderMaterial.h"

#include <iostream>
#include <algorithm>

using namespace std;

RenderObject::RenderObject(string name)
{
	this->name = name;
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

