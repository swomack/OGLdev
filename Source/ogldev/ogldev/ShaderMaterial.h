#pragma once

#include "RenderMaterial.h"
#include "glew.h"
#include <string>

class ShaderMaterial : public RenderMaterial
{
public:
	ShaderMaterial(std::string vertex_shader_source = "", std::string fargment_shader_source = "", std::string geometry_shader_source = "", std::string tessellation_shader_source = "");
	~ShaderMaterial();

	GLuint getShaderProgram();

protected:
	std::string vertex_shader_source;
	std::string fragment_shader_source;
	std::string geometry_shader_source;
	std::string tessellation_shader_source;

	GLuint shader_program_identifier;
};
