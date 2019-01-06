#include <Navi/NaviFileSystem.h>
#include <fstream>
#include <sstream>

namespace Navi
{

FileSystem& FileSystem::get(const std::string& appToRootPath)
{
	static FileSystem fs(appToRootPath);
	return fs;
}

std::string FileSystem::getRootPath() const
{
	return getAppPath() + mAppToRootPath + getPathSeparator();
}

std::string FileSystem::getCategoryPath(Category category) const
{
	std::string rootPath = getRootPath();
	std::string separator = getPathSeparator();
	std::string contentPath;

	switch (category)
	{
	case Category::SHADER:
		contentPath = "shaders";
		break;
	default:
		contentPath = "";
	}

	return rootPath + "Navi" + separator + contentPath + separator;
}

bool FileSystem::readFile(Category category, const std::string& filename, std::string& buffer) const
{
	std::string filePath = getCategoryPath(category) + filename;
	std::ifstream fileStream(filePath, std::ifstream::in);

	if (fileStream.good())
	{
		std::stringstream ss;
		ss << fileStream.rdbuf();
		buffer = ss.str();
		return true;
	}

	return false;
}

}