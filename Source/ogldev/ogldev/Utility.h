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

namespace ogl_dev
{
	std::string readFile(std::experimental::filesystem::path filePath);
};
