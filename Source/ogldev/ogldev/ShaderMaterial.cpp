#include "ShaderMaterial.h"
#include "Utility.h"

Shadermaterial::Shadermaterial(std::string vertex_shader_source, std::string fargment_shader_source, std::string geometry_shader_source, std::string tessellation_shader_source)
{
	this->vertex_shader_source = vertex_shader_source;
	this->fragment_shader_source = fragment_shader_source;
	this->geometry_shader_source = geometry_shader_source;
	this->tessellation_shader_source = tessellation_shader_source;
}

Shadermaterial::~Shadermaterial()
{
}
