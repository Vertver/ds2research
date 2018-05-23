#include <Windows.h>
#include "classes.h"
#pragma comment(lib, "ds2kernel.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#define DS2ENGINE_PRESENCE_MUTEX "Local\\ds2engine_mutex0P"

	HANDLE hCheckPresenceMutex = INVALID_HANDLE_VALUE;
	hCheckPresenceMutex = OpenMutex(READ_CONTROL, FALSE, DS2ENGINE_PRESENCE_MUTEX);
	if (hCheckPresenceMutex == NULL)
	{
		// New mutex
		hCheckPresenceMutex = CreateMutex(NULL, FALSE, DS2ENGINE_PRESENCE_MUTEX);
		if (hCheckPresenceMutex == NULL)
			// Shit happens
			return 2;
	}
	else
	{
		// Already running
		CloseHandle(hCheckPresenceMutex);
		return 1;
	}

	MessageBoxA(NULL, "", "", MB_OK | MB_ICONINFORMATION);
	IDS2Engine ids;
	ids.GetDS2Engine();

	return 0;
}
