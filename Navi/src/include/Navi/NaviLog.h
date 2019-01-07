#pragma once
#include <stdarg.h>

namespace Navi
{

class Log
{
public:
	enum class Category
	{
		None,
		Error,
		Info,
	};

public:
	static Log& get();
	void log(Category category, const char* message, ...);
	void log(Category category, const char* message, va_list args);
};

void logError(const char* msg, ...);

}
