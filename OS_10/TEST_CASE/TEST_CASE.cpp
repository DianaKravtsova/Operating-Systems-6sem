// OS10_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "testib.h"
using namespace std;
using namespace testlib;

int main()
{

	int capacity = 1;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxPayloadLength = 10;
	const wchar_t* fileName = L"D:\\3\\OS\\OS_10\\test.ht";

	cout << "CREATE\n";
	if (create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName)) 	cout << "Create test" << endl;
	else cout << "Error create test" << endl;
	cout << "________________________\n";
	snapshotIntervalSec = 2;
	maxKeyLength = 1;
	maxPayloadLength = 10;
	cout << "INSERT\n";
	if (insert(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName)) cout << "Insert test" << endl;
	else 	cout << "Error insert test" << endl;
	cout << "________________________\n";
	capacity = 5;
	snapshotIntervalSec = 2;
	maxKeyLength = 7;
	maxPayloadLength = 2;
	cout << "UPDATE\n";
	if (update(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName)) 	cout << "Update test" << endl;
	else cout << "Error update test" << endl;
	cout << "________________________\n";
	/*cout << "DELETE\n";
	if (mydelete(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName)) 	cout << "Delete test" << endl;
	else cout << "Error delete test" << endl;
	cout << "_________________________\n";*/

	return 0;
}
