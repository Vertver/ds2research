#include <Windows.h>
#include <stdint.h>

#include "classes.h"
#include "entry.h"
#include "MemoryManager.h"

#pragma comment(lib, "ds2kernel.lib")
#pragma comment(lib, "ds2MemoryManager.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/* Create Engine Mutex*/
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

	/* Check for ds2MemoryManager.dll */
	ChechDS2Memory();

	//g_memory_manager_static_loaded();
	g_memory_manager_static_loaded();

	/* Check for ds2kernel.dll */
	ChechDS2Kernel();

	GetDS2Engine();

	return 1;
}

int ChechDS2Memory()
{
	HMODULE			hMemory = NULL;
	if (hMemory)
		return 2;
	hMemory = LoadLibrary("ds2MemoryManager.dll");
	if (0 == hMemory)
	{
		MessageBoxA(NULL, "Cannot find ds2MemoryManager.dll", "DS2 Engine Error!", MB_ICONWARNING | MB_OK);
		exit(-2);
	}
	return 1;
}

int ChechDS2Kernel()
{
	HMODULE			hKernel = NULL;
	if (hKernel)
		return 2;
	hKernel = LoadLibrary("ds2kernel.dll");
	if (0 == hKernel)
	{
		MessageBoxA(NULL, "Cannot find ds2kernel.dll", "DS2 Engine Error!", MB_ICONWARNING | MB_OK);
		exit(-2);
	}
	return 1;
}

/*
int32_t fun_100097d8(int32_t ecx, int32_t a2) {
	int1_t zf3;
	uint32_t eax4;

	if (!zf3) {
		if (!(eax4 & 0xff000000)) {
			return ecx - 1 - a2;
		}
	}
}
*/
