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

	return shader_program;
}

GLuint ogldev_graphics_utlity::generateShaderObject(const std::string & shader_source, GLuint shaderType)
{
	GLuint shader_obj = glCreateShader(shaderType);

	return shader_obj;
}
