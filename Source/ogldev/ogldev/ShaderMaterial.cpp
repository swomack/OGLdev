#include "ShaderMaterial.h"
#include "Utility.h"

ShaderMaterial::ShaderMaterial(std::string vertex_shader_source, std::string fargment_shader_source, std::string geometry_shader_source, std::string tessellation_shader_source) : shader_program_identifier(0)
{
	this->vertex_shader_source = vertex_shader_source;
	this->fragment_shader_source = fargment_shader_source;
	this->geometry_shader_source = geometry_shader_source;
	this->tessellation_shader_source = tessellation_shader_source;

	shader_program_identifier = ogldev_graphics_utlity::generateShaderProgram(this->vertex_shader_source, this->fragment_shader_source);
}

ShaderMaterial::~ShaderMaterial()
{

}

GLuint ShaderMaterial::getShaderProgram()
{
	return shader_program_identifier;
}
