#include <iostream>
#include <Windows.h>

using namespace std;
bool printFileTxt(LPWSTR FileName);
bool delRowFileTxt(LPWSTR FileName, DWORD row);

int main()
{
   // printFileTxt((LPWSTR)L"os_09_02.txt");
    if (!delRowFileTxt((LPWSTR)L"os_09_00002.txt", 1))
        cout << "Error del" << endl;
    
   // delRowFileTxt((LPWSTR)L"os_09_02.txt", 3);
    //delRowFileTxt((LPWSTR)L"os_09_02.txt", 8);
    delRowFileTxt((LPWSTR)L"os_09_02.txt", 50);
    printFileTxt((LPWSTR)L"os_09_02.txt");
}

bool delRowFileTxt(LPWSTR FileName, DWORD row)
{
    HANDLE fileHandle = CreateFile(FileName, GENERIC_READ | GENERIC_WRITE,  NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE)
        return false;

    _BY_HANDLE_FILE_INFORMATION fileInformation;
    if (!GetFileInformationByHandle(fileHandle, &fileInformation)) {
        CloseHandle(fileHandle);
        return false;
    }

    char buf[1024];
    char* reBuf = buf;
    ZeroMemory(buf, sizeof(buf));
    DWORD readedBytes = NULL;
    DWORD nPosition = 0;

    if (!ReadFile(fileHandle, buf, fileInformation.nFileSizeLow + 1, &readedBytes, NULL)) {
        CloseHandle(fileHandle);
        return false;
    }
        
   
    DWORD countStr = 0;
    for (DWORD i = 0; i < sizeof(buf); i++)
    {
        if (buf[i] == '\n')
            countStr++;
    }
    
    if (countStr < row) {
        CloseHandle(fileHandle);
        cout << "The file has less " << row << " lines" << endl;
        return false;
    }
        

    LARGE_INTEGER newPointer;
    for (DWORD j = 0; nPosition < sizeof(buf); nPosition++) {
        if (j == row - 1)
            break;
        
        if (buf[nPosition] == '\n')
            j++;
    }

    newPointer.QuadPart = nPosition;
    SetFilePointerEx(fileHandle, newPointer, NULL, FILE_BEGIN);
    SetEndOfFile(fileHandle);
    DWORD endStr = nPosition;
    for (DWORD j = nPosition; endStr < sizeof(buf); endStr++)
    {
        if (buf[endStr] != '\n')
            j++;
        else
            break;
    }
    endStr++;
    char* end = new char[fileInformation.nFileSizeLow  - endStr];

    int check = 0;
    int checkEnd = 0;
    while (*reBuf++) {
        if (check < endStr)
            check++;
        else
        {
            end[checkEnd] = buf[check];
            checkEnd++;
            check++;
        }
    }

    DWORD writenSymbols = 0;

    WriteFile(fileHandle, end, checkEnd, &writenSymbols, NULL);

    CloseHandle(fileHandle);

    return true;
}

bool printFileTxt(LPWSTR FileName) {
    HANDLE fileHandle = CreateFile(FileName, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE) {
        cout << GetLastError() << endl;
        return false;
    }
        

    DWORD n = NULL;
    char buf[1024];

    ZeroMemory(buf, sizeof(buf));
    bool readFile = ReadFile(fileHandle, &buf, 350, &n, NULL);

    cout << "Read file:" << buf << std::endl;
    CloseHandle(fileHandle);
}