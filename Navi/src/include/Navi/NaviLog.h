#pragma once

namespace Navi
{

class Log
{
public:
	static Log& get();
	void logError(const char* message, ...);
};

}
