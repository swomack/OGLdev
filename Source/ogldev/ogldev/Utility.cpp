#include "Utility.h"

using namespace std;
using namespace std::experimental::filesystem;

string ogldev_utility::readFile(path filePath)
{
	string result;
	if (!exists(filePath))
		result;

	try
	{
		ifstream inFile;
		inFile.open(filePath);
		stringstream strStream;
		strStream << inFile.rdbuf();
		result = strStream.str();
		inFile.close();
	}
	catch (...)
	{
		fprintf(stderr, "Could not read the file : %s\n", filePath.string().c_str());
	}

	return result;
}

GLuint ogldev_graphics_utlity::generateShaderProgram(const std::string & vertex_shader_source, const std::string & fragment_shader_source, const std::string & geometry_shader_source, const std::string & tessellation_shader_source)
{
	GLuint shader_program = glCreateProgram();

	GLuint v_shader = ogldev_graphics_utlity::generateShaderObject(vertex_shader_source, GL_VERTEX_SHADER);
	GLuint f_shader = ogldev_graphics_utlity::generateShaderObject(fragment_shader_source, GL_FRAGMENT_SHADER);

	// we will consider other shader type laters
	if (!v_shader || !f_shader)
		return 0;

	
	glAttachShader(shader_program, v_shader);
	glAttachShader(shader_program, f_shader);

	glLinkProgram(shader_program);

	GLint success;
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

	if (!success)
	{
		GLchar info_log[1024];
		glGetProgramInfoLog(shader_program, sizeof(info_log), NULL, info_log);
		fprintf(stderr, "Error linking shader program: %s\n", info_log);
		return 0;
	}

	glValidateProgram(shader_program);

	return shader_program;
}

GLuint ogldev_graphics_utlity::generateShaderObject(const std::string & shader_source, GLuint shaderType)
{
	GLuint shader_obj = glCreateShader(shaderType);

	string shader_code = ogldev_utility::readFile(shader_source);

	const GLchar* p[1];
	p[0] = shader_code.c_str();
	GLint length[1];
	length[0] = shader_code.length();

	glShaderSource(shader_obj, 1, p, length);
	glCompileShader(shader_obj);

	GLint success;
	glGetShaderiv(shader_obj, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLchar info_log[1024];
		glGetShaderInfoLog(shader_obj, sizeof(info_log), NULL, info_log);
		fprintf(stderr, "Error compiling shader: %s\n", info_log);
		return 0;
	}

	return shader_obj;
}
