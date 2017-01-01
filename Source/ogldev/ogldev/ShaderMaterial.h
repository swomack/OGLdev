#pragma once

#include "RenderMaterial.h"
#include <string>

class Shadermaterial : public RenderMaterial
{
public:
	Shadermaterial(std::string vertex_shader_source = "", std::string fargment_shader_source = "", std::string geometry_shader_source = "", std::string tessellation_shader_source = "");
	~Shadermaterial();

protected:
	std::string vertex_shader_source;
	std::string fragment_shader_source;
	std::string geometry_shader_source;
	std::string tessellation_shader_source;
};
