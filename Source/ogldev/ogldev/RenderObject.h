#pragma once

#include "GodObject.h"

#include <vector>
#include <string>

class RenderObject : public GodObject
{
private:
	std::vector<RenderObject*> children;
	RenderObject* parent;
	std::string name;

public:
	RenderObject();
	~RenderObject();

	virtual void setParent(RenderObject* parent_object);
	virtual void addChild(RenderObject* child_object);
	virtual void removeChild(RenderObject* child_object);

	std::vector<RenderObject*>& get_children();
};
