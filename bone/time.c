#include <Windows.h>

__int64 get_gmt(){
	FILETIME ft;
	unsigned __int64 utc = 0;
	GetSystemTimeAsFileTime(&ft);
	utc |= ft.dwHighDateTime;
	utc <<= 32;
	utc |= ft.dwLowDateTime;
	utc /= 10000;
	return utc - 11644473600000L;
}