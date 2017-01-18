#include "ShaderMaterial.h"
#include "Utility.h"

using namespace std;

ShaderMaterial::ShaderMaterial(std::string vertex_shader_source, std::string fargment_shader_source, std::string geometry_shader_source, std::string tessellation_shader_source) : shader_program_identifier(0), uniforms_needs_update(false)
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
	uniforms_needs_update = true;
}

void ShaderMaterial::addUniform1f(const std::string uniform_name, float value)
{
	float_uniforms.push_back(make_pair(uniform_name, value));
	uniforms_needs_update = true;
}

std::vector<std::pair<std::string, int>> ShaderMaterial::getUniforms1i()
{
	return integer_uniforms;
}

std::vector<std::pair<std::string, float>> ShaderMaterial::getUniforms1f()
{
	return float_uniforms;
}

#define UPDATE_UNIFORM(a, b, c, d) \
			auto res = find_if(a.begin(), a.end(), [&b](auto element) {	\
							if (element.first == b)						\
								return true;							\
							return false;								\
						});												\
																		\
			if (res == a.end())											\
				return;													\
																		\
			(*res).second = c;											\
			d = true;													

void ShaderMaterial::updateUniform1i(string uniform_name, int new_value)
{
	UPDATE_UNIFORM(integer_uniforms, uniform_name, new_value, uniforms_needs_update)
}

void ShaderMaterial::updateUniform1f(string uniform_name, float new_value)
{
	UPDATE_UNIFORM(float_uniforms, uniform_name, new_value, uniforms_needs_update)
}

void ShaderMaterial::setUniformNeedsUpdate(bool value)
{
	uniforms_needs_update = value;
}

bool ShaderMaterial::getUniformNeedsUpdate()
{
	return uniforms_needs_update;
}
