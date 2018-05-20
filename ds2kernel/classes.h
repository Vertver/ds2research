#pragma once

#include <windows.h>

class __declspec(dllimport)  DS2Kernel
{
public:
	void Init();
	void Shutdown();
	void BeginFrame();

};

class __declspec(dllimport)  IDS2Engine
{
public:
	void GetDS2Engine();

};