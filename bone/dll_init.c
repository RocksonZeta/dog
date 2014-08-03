#include <Windows.h>
#include "sqlite.h"
BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,  
	DWORD fdwReason,     
	LPVOID lpReserved)  
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		init_db();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;  
}