#include <Navi/NaviLog.h>
#include <stdarg.h>
#include <stdio.h>

namespace Navi
{

Log& Log::get()
{
	static Log log;
	return log;
}

void Log::logError(const char* message, ...)
{
	va_list argptr;
	va_start(argptr, message);
	vfprintf(stderr, message, argptr);
	va_end(argptr);
}

}