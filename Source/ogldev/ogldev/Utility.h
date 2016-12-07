#pragma once

#include <boost\uuid\uuid.hpp>
#include <boost\uuid\uuid_generators.hpp>
#include <boost\uuid\uuid_io.hpp>

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
