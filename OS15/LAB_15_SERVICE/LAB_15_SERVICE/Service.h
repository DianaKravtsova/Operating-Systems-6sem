#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>

#define SERVICENAME L"kravts15"
#define TRACEPATH "D:\\3\\OS\\OS15\\Service.trace"

VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
VOID WINAPI ServiceHandler(DWORD fdwControl);

void trace(const char* msg, int r = std::ofstream::app);