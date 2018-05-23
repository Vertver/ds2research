// This is the main project file for VC++ application project 
// generated using an Application Wizard.
#include "classes.h"
#include <windows.h>
#include <iostream>

int main()
{
    // TODO: Please replace the sample code below with your own.
    //Console::WriteLine(S"Hello World");
	printf("DS2 Launcher start...\n");
	IDS2Engine ids;
	ids.GetDS2Engine();
	return 0;
}