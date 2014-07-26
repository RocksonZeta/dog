#include <Windows.h>
#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif
__int64 current_ms()
{
	FILETIME ft;
	unsigned __int64 tmpres = 0;
	static int tzflag;
	GetSystemTimeAsFileTime(&ft);

	tmpres |= ft.dwHighDateTime;
	tmpres <<= 32;
	tmpres |= ft.dwLowDateTime;
	/*converting file time to unix epoch*/
	tmpres -= DELTA_EPOCH_IN_MICROSECS;
	tmpres /= 10;  /*convert into microseconds*/


	return tmpres;
}