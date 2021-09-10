#include <iostream>
#include "HT.h"
#include "testib.h"
using namespace std;
using namespace HT;

namespace testlib {
		void printStr(char* str) {
		cout << "ERROR:\t";
		int i = 0;
		while (str[i]) {
			cout << str[i];
			i++;
		}
		cout << endl;
	}

bool create(int capacity, int snapshotIntervalSec, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName)
{
	HTHANDLE* HT;
	try {
		HT = Create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName);
		if (HT == NULL)
			throw "Invalid handle";
		Close(HT);
	}
	catch (const char* err) {
		cout << err << endl;
		return false;
	}
	return true;
}

bool insert(int capacity, int snapshotIntervalSec, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName)
{
	HTHANDLE* HT;
	try {
		HT = Open(fileName);
		if (HT == NULL)
			throw "Invalid handle";
		Element* el;
		Element* el1 = new Element("key1", 5, "hello", 7);
		Element* el2 = new Element("keykey", 7, "hifromne", 8);
		if (!Insert(HT, el1)) {
			printStr(GetLastError(HT));
			return false;
		}
		if ((el = Get(HT, el1)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		Close(HT);
	}
	catch (const char* err) {
		cout << err << endl;
		return false;
	}
	return true;
}

bool update(int capacity, int snapshotIntervalSec, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName)
{
	HTHANDLE* HT;
	try {
		HT = Open(fileName);
		if (HT == NULL)
			throw "Invalid handle";
		Element* el;
		Element* el1 = new Element("key1", 5, "hello", 7);
		Element* el3 = new Element("key1", 5, "world", 6);
		if (!Update(HT, el1, el3->payload, el3->payloadlength)) {
			printStr(GetLastError(HT));
			return false;
		}
		if ((el = Get(HT, el1)) == NULL) {
			printStr(GetLastError(HT));
			Close(HT);
			return false;
		}
		else
			print(el);
		Close(HT);
	}
	catch (const char* err) {
		cout << err << endl;
		return false;
	}
	return true;
}

//bool mydelete(int capacity, int snapshotIntervalSec, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName)
//{
//	const wchar_t* fileName = L"D:\\3\\OS\\OS_10\\test.ht";
//	try {
//		HTHANDLE* HT = Open(fileName);
//		if (HT == NULL)
//			throw "Invalid handle";
//		Element* el;
//		Element* el1 = new Element("key1", 5, "hello", 7);
//		if (!Delete(HT, el1)) {
//			printStr(GetLastError(HT));
//			Close(HT);
//			return false;
//		}
//		if ((el = Get(HT, el1)) == NULL)
//		{
//			Close(HT);
//			return true;
//		}
//		Close(HT);
//		return false;
//	}
//	catch (const char* err) {
//		cout << err << endl;
//		return false;
//	}
//	return true;
//}
}
