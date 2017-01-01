#include "Utility.h"

using namespace std;
using namespace std::experimental::filesystem;
namespace ogl_dev
{
	string readFile(path filePath)
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
}