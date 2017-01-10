#include "ShaderMaterial.h"
#include "Utility.h"

using namespace std;

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

void ShaderMaterial::addUniform1i(const string uniform_name, int value)
{
	integer_uniforms.push_back(make_pair(uniform_name, value));
}

void ShaderMaterial::addUniform1f(const std::string uniform_name, float value)
{
	float_uniforms.push_back(make_pair(uniform_name, value));
}
