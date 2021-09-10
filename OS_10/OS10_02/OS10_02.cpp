#include <iostream>
#include "HT.h"
using namespace std;
using namespace HT;
void printStr(char* str);
int main()
{
	const wchar_t* fileName = L"D:\\3\\OS\\OS_10\\laba.ht";
	try {
		int capacity = 10;
		int snapshotIntervalSec = 3;
		int maxKeyLength = 10;
		int maxPayloadLength = 10;
		//HTHANDLE* HT = Create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName);
		HTHANDLE* HT = Open(fileName);
		if (HT == NULL)
			throw "Invalid handle";

		Element* el1 = new Element("key", 4, "diana", 6);
		Element* el2 = new Element("keykey", 7, "diana2", 7);
		Element* el3 = new Element("string", 7, "diana33", 8);
		Element* el4 = new Element("strstr", 7, "diana444", 9);
#pragma region INSERT

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
		Element* el;
		cout << "INSERT" << endl;
#pragma region GET AFTER INSERT
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

#pragma region UPDATE
		if (!Update(HT, el1, el3->payload, el3->payloadlength)) {
			printStr(GetLastError(HT));
		}
		if (!Update(HT, el4, el3->payload, el3->payloadlength)) {
			printStr(GetLastError(HT));
		}
#pragma endregion
		if (!Snap(HT))
			printStr(GetLastError(HT));
		cout << "\nUPDATE" << endl;
#pragma region GET AFTER UPDATE
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
		cout << "_____________________" << endl;
#pragma endregion
		Sleep(10000);
#pragma region DELETE
		if (!Delete(HT, el1)) {
			printStr(GetLastError(HT));
		}
		if (!Delete(HT, el2)) {
			printStr(GetLastError(HT));
		}
		if (!Delete(HT, el3)) {
			printStr(GetLastError(HT));
		}
		if (!Delete(HT, el4)) {
			printStr(GetLastError(HT));
		}
#pragma endregion
		cout << "\nDELETE" << endl;
#pragma region GET3
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
		cout << "_____________________" << endl;


		if (Close(HT))
			cout << "\nClose storage\n";
		delete el1;
		delete el2;
		delete el3;
		delete el4;
		delete el;
	}
	catch (const char* mess) {
		cout << mess << endl;
	}

	system("pause");
	return 0;
}
void printStr(char* str) {
	cout << "ERROR:\t" << str << endl;
}