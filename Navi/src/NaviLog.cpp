#include <Navi/NaviLog.h>
#include <stdarg.h>
#include <stdio.h>
#include <string>

namespace Navi
{

void logError(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	Navi::Log::get().log(Navi::Log::Category::Error, msg, args);
	va_end(args);
}

Log& Log::get()
{
	static Log log;
	return log;
}

void Log::log(Category category, const char* message, ...)
{
	va_list args;
	va_start(args, message);
	log(category, message, args);
	va_end(args);
}

void Log::log(Category category, const char* message, va_list args)
{
	std::string prefix;
	FILE* channel;

	switch (category)
	{
	case Category::Error :
		prefix = "**** ERROR **** : ";
		channel = stderr;
		break;
	default:
		channel = stdout;
	}

	std::string output = prefix + message;
	vfprintf(channel, output.c_str(), args);
}

}