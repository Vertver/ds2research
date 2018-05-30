//#pragma once
#define KERNEL_API __declspec(dllimport) 

#include <windows.h>

// DS2 Kernel

void DS2Kernel_Init(); // Init Kernel

void DS2Kernel_Shutdown(); // Shutdown kernel

void DS2Kernel_BeginFrame(); // Begin on frame?

// DS2 KERNEL

class KERNEL_API IDS2Engine * GetDS2Engine(); // ENTRY POINT