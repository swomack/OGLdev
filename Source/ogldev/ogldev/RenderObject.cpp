#include "RenderObject.h"
#include "RenderGeometry.h"
#include "RenderMaterial.h"

#include <iostream>
#include <algorithm>

using namespace std;

RenderObject::RenderObject()
{
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

