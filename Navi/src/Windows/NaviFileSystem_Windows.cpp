#include <Navi/NaviFileSystem.h>
#include <windows.h>
#include "Shlwapi.h"

namespace Navi
{

std::string FileSystem::getPathSeparator() const
{
	return "\\";
}

std::string FileSystem::getAppPath() const
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