#include <iostream>
#include <Windows.h>
#include <ctime>

BOOL printWatchRowFileTxt(LPCWSTR FileName, DWORD mlsec);
int getCountStr(LPCWSTR FileName);
void main()
{
    printWatchRowFileTxt(L"D:\\3\\OS\\OS_09\\OS_09_03\\test.txt", 20000);
}


BOOL printWatchRowFileTxt(LPCWSTR FileName, DWORD mlsec) {
    std::wstring wFilePath = std::wstring(FileName);
    std::string filePath = std::string(wFilePath.begin(), wFilePath.end());

    std::string dirPath = std::string(wFilePath.begin(), wFilePath.end());

    for (int i = dirPath.length() - 1; i >= 0; i--) {
        if (dirPath[i] != '\\')
            dirPath.pop_back();
        else {
            break;
        }
    }
    HANDLE hDir = FindFirstChangeNotificationA(dirPath.c_str(), FALSE, FILE_NOTIFY_CHANGE_SIZE);
    if (hDir == INVALID_HANDLE_VALUE) {
        std::cout << GetLastError();
        return false;
    }
        
    
    clock_t t1 = clock();
    while (mlsec >= clock() - t1) {
        std::cout << "ya tut3" << std::endl;
        int fileStrsCount = getCountStr(FileName);
        if (WaitForSingleObject(hDir, mlsec) == WAIT_OBJECT_0) {
            int newfileStrsCount = getCountStr(FileName);
            std::cout  << "ya tut"<< std::endl;
            if (fileStrsCount != newfileStrsCount) {
                std::cout << "Count string  " << newfileStrsCount << std::endl;
                fileStrsCount = newfileStrsCount;

            }
            FindNextChangeNotification(hDir);
        }
    }
    FindCloseChangeNotification(hDir);
    return true;
}

int getCountStr(LPCWSTR FileName) {
    char buf[10240];
    Sleep(500);
    HANDLE handleFile = CreateFile(FileName, GENERIC_WRITE | GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    std::cout << "ya tut 2" << std::endl;
    DWORD n = NULL;
    ZeroMemory(buf, sizeof(buf));
    BOOL b = ReadFile( handleFile, &buf, sizeof(buf), &n, NULL); 
    int i = 0;
    int countStr = 0;
    while (buf[i] != '\0') {
        if (buf[i] == '\n')
            countStr++;
        i++;
    }
    countStr++;
    CloseHandle(handleFile);
    return countStr;
}