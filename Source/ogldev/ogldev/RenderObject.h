#pragma once

#include <vector>
#include <string>

class RenderObject
{
private:
	std::vector<RenderObject*> children;
	RenderObject* parent;
	std::string name;
public:
	RenderObject();
	~RenderObject();

	void setParent(RenderObject* parent_object);
	void addChild(RenderObject* child_object);
	void removeChild(RenderObject* child_object);
};
