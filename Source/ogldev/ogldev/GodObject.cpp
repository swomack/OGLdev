#include "GodObject.h"
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace std;

GodObject::GodObject()
{
	id = IDGenerator::GenerateID();
}

GodObject::~GodObject()
{
}

string GodObject::get_string_id()
{
	std::string tmp = boost::lexical_cast<std::string>(id);
	return tmp;
}
