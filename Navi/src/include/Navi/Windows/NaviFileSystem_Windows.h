#pragma once
#include <Navi/NaviFileSystem.h>

namespace Navi
{
	class FileSystem_Windows : public Navi::FileSystem
	{
	public:
		explicit FileSystem_Windows(const std::string& appToRootPath);
		std::string getAppPath() const override;
	};
}