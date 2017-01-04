#pragma once

#include <boost\uuid\uuid.hpp>
#include <boost\uuid\uuid_generators.hpp>
#include <boost\uuid\uuid_io.hpp>

#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <istream>
#include <sstream>

#include "glew.h"

typedef  boost::uuids::uuid uuid;

class IDGenerator
{
public:
	static uuid GenerateID()
	{
		uuid id = boost::uuids::random_generator()();
		return id;
	}
};

namespace ogldev_utility
{
	std::string readFile(std::experimental::filesystem::path filePath);
};

namespace ogldev_graphics_utlity
{

	GLuint generateShaderProgram(const std::string& vertex_shader_source, const std::string& fragment_shader_source, 
		const std::string& geometry_shader_source = "", const std::string& tessellation_shader_source = "");

	GLuint generateShaderObject(const std::string& shader_source, GLuint shaderType);
};
