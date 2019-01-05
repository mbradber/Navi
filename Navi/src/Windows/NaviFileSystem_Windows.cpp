#include <Navi/Windows/NaviFileSystem_Windows.h>
#include <windows.h>
#include "Shlwapi.h"

namespace Navi
{

FileSystem* FileSystem::get(const std::string& rootPath)
{
	static FileSystem_Windows fs(rootPath);
	return &fs;
}

std::string FileSystem::getPathSeparator() const
{
	return "\\";
}

FileSystem_Windows::FileSystem_Windows(const std::string& appToRootPath)
	: FileSystem(appToRootPath)
{
}

std::string FileSystem_Windows::getAppPath() const
{
	// TODO: add unicode path support
	CHAR ownPath[MAX_PATH];
	HMODULE hModule = GetModuleHandle(NULL);
	GetModuleFileName(hModule, ownPath, sizeof(ownPath));
	PathRemoveFileSpec(ownPath);

	std::string appPath = ownPath;
	appPath += getPathSeparator();
	return appPath;
}

}