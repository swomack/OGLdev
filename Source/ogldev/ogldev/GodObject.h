#pragma once

#include "Utility.h"
#include <string>

class GodObject
{
public:
	uuid id;
public:
	GodObject();
	~GodObject();

	std::string get_string_id();
};
