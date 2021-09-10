// OS11_CREATE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma warning(disable : 4996)
#include <iostream>
#include "HT.h"
#include <wchar.h>
#include <string>


wchar_t* GetWC(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

int main(int argc, char* argv[])
{
	int capacity = 2000;
	int snapshotIntervalSec = 3;
	int maxKeyLength = 4;
	int maxDataLength = 4;
	wchar_t* fileName;
	const wchar_t* directoryPath = L"D:\\";
	std::wstring filePath(L"D:\\test2.ht");
	try {
		if (argv[1] && argv[2] && argv[3] && argv[4] && argv[5]) {
			capacity = std::stoi(argv[2]);
			snapshotIntervalSec = std::stoi(argv[3]);
			maxKeyLength = std::stoi(argv[4]);
			maxDataLength = std::stoi(argv[5]);
			fileName = GetWC(argv[1]);
			std::wstring s(directoryPath);
			s += std::wstring(fileName);
			filePath = s;
		}
		else {

		}
		HT::HTHANDLE* HT;
		HT = HT::Create(capacity, snapshotIntervalSec, maxKeyLength, maxDataLength, filePath.c_str());
		if (HT == NULL)
			throw "Invalid handle";
		HT::Close(HT);
		std::cout << "HT-Storage Created " << std::endl;
		std::wcout << "filename: " << filePath << std::endl;
		std::cout << "snapshotIntervalSec: " << snapshotIntervalSec << std::endl;
		std::cout << "capacity: " << capacity << std::endl;
		std::cout << "maxKeyLength: " << maxKeyLength << std::endl;
		std::cout << "maxDataLength: " << maxDataLength << std::endl;
	}
	catch (const char* err) {
		std::cout << err << std::endl;
		return 1;
	}
	return 0;
}
