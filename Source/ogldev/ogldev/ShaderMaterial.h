#pragma once

#include "RenderMaterial.h"
#include "glew.h"
#include <string>
#include <vector>

class ShaderMaterial : public RenderMaterial
{
public:
	ShaderMaterial(std::string vertex_shader_source = "", std::string fargment_shader_source = "", std::string geometry_shader_source = "", std::string tessellation_shader_source = "");
	~ShaderMaterial();

	GLuint getShaderProgram();

	void addUniform1i(const std::string uniform_name, int value);
	void addUniform1f(const std::string uniform_name, float value);

protected:
	std::string vertex_shader_source;
	std::string fragment_shader_source;
	std::string geometry_shader_source;
	std::string tessellation_shader_source;

	GLuint shader_program_identifier;

	std::vector<std::pair<std::string, int>>   integer_uniforms;
	std::vector<std::pair<std::string, float>> float_uniforms;
};
