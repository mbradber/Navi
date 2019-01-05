#pragma once
#include <string>

namespace Navi
{

class FileSystem
{
public:
	enum class Category
	{
		NONE,
		SHADER,
		TEXTURE,
		MESH,
	};

public:
	explicit FileSystem(const std::string& appToRootPath)
		:mAppToRootPath(appToRootPath)
	{
	}

	static FileSystem* get(const std::string& rootPath);

	bool readFile(Category category, const std::string& filename, std::string& buffer) const;
	virtual std::string getAppPath() const = 0;
	std::string getRootPath() const;
	std::string getPathSeparator() const;
	std::string getCategoryPath(Category category) const;

protected:
	std::string mAppToRootPath;
};

}
