#include <iostream>
#pragma comment(lib,"D:\\3\\OS\\OS_10\\Debug\\lib.lib")
#include "../lib/HT.h"
using namespace std;
using namespace HT;

void printStr(char* str);
int main()
{
	int capacity = 10;
	int capacity2 = 4;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxKeyLength2 = 4;
	int maxPayloadLength = 10;
	const wchar_t* fileName = L"D:\\3\\OS\\OS_10\\laba1.ht";
	const wchar_t* fileName2 = L"D:\\3\\OS\\OS_10\\laba2.ht";
	try {
		HTHANDLE* HT = Create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName);
		HTHANDLE* HT2 = Create(capacity2, snapshotIntervalSec, maxKeyLength2, maxPayloadLength, fileName2);

		//HTHANDLE* HT = Open(fileName);
		//HTHANDLE* HT2 = Open(fileName2);
		if (HT == NULL)
			throw "Invalid handle";
		if (HT2 == NULL)
			throw "Invalid handle";

		Element* el1 = new Element("test", 5, "str1", 5);
		Element* el2 = new Element("testt", 6, "str22", 6);
		Element* el3 = new Element("testtt", 7, "str333", 7);
		Element* el4 = new Element("testttt", 8, "str4444", 8);
#pragma region INSERT1

		if (!Insert(HT, el1)) {
			printStr(GetLastError(HT));
		}
		if (!Insert(HT, el2)) {
			printStr(GetLastError(HT));
		}
		if (!Insert(HT, el3)) {
			printStr(GetLastError(HT));
		}
		if (!Insert(HT, el4)) {
			printStr(GetLastError(HT));
		}
#pragma endregion
#pragma region INSERT2

		if (!Insert(HT2, el1)) {
			printStr(GetLastError(HT));
		}
		if (!Insert(HT2, el2)) {
			printStr(GetLastError(HT));
		}
		if (!Insert(HT2, el3)) {
			printStr(GetLastError(HT));
		}
		if (!Insert(HT2, el4)) {
			printStr(GetLastError(HT));
		}
#pragma endregion
		Element* el;
		cout << "\tINSERT1" << endl;
#pragma region GET1
		if ((el = Get(HT, el1)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el2)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el3)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el4)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		cout << "_____________________" << endl;
#pragma endregion
		cout << "\n\tINSERT2" << endl;
#pragma region GET2
		if ((el = Get(HT2, el1)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT2, el2)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT2, el3)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT2, el4)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		cout << "_____________________" << endl;
#pragma endregion

		Close(HT);
		Close(HT2);
		HTHANDLE* HT3 = Open(fileName);
		HTHANDLE* HT4 = Open(fileName2);

		cout << "\n\tGET1" << endl;
#pragma region GET1
		if ((el = Get(HT3, el1)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT3, el2)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT3, el3)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		cout << "_____________________" << endl;
#pragma endregion
		cout << "\n\tGET2" << endl;

#pragma region GET2
		if ((el = Get(HT4, el1)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT4, el2)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT4, el3)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT4, el4)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		cout << "_____________________" << endl;
#pragma endregion
		Close(HT);
		Close(HT2);
		delete el1;
		delete el2;
		delete el3;
		delete el4;
		delete el;
	}
	catch (const char* err) {
		cout << err << endl;
	}
	
	system("pause");
	return 0;
}
void printStr(char* str) {
	cout << "ERROR:\t";
	int i = 0;
	while (str[i]) {
		cout << str[i];
		i++;
	}
	cout << endl;
}