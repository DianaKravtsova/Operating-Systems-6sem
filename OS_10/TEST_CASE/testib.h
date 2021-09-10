#pragma once
#include <Windows.h>
#include <string.h>
#include <iostream>
#include<iomanip>

namespace testlib{
	
	void printStr(char* str);
	bool create(int capacity, int snapshotIntervalSec, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName);
	bool insert(int capacity, int snapshotIntervalSec, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName);
	bool update(int capacity, int snapshotIntervalSec, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName);
	bool mydelete(int capacity, int snapshotIntervalSec, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName);

}