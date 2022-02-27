//#include <iostream>
//#include <stdio.h>
//#include <errno.h>
//#include <windows.h>
//
//#define BUF_SIZE 256
//
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	FILE* fIn, * fOut;
//	char buf[BUF_SIZE];
//	size_t bufIn, bufOut;
//
//	DWORD dwStart = GetTickCount();
//
//	if (argc != 3)
//	{
//		return 1;
//	}
//
//	if ((fIn = fopen(argv[1], "rt")) == NULL)
//	{
//		perror(argv[1]);
//		return 2;
//	}
//	if ((fOut = fopen(argv[2], "wt")) == NULL)
//	{
//		perror(argv[2]);
//		return 3;
//	}
//
//	while ((bufIn = fread(buf, 1, BUF_SIZE, fIn)) > 0)
//	{
//		bufOut = fwrite(buf, 1, bufIn, fOut);
//		if (bufOut != bufIn)
//		{
//			perror("Неисправимая ошибка записи.");
//			return 4;
//		}
//	}
//	fclose(fIn);
//	fclose(fOut);
//
//	DWORD dwEnd = GetTickCount();
//
//	DWORD time = (dwEnd - dwStart);
//
//	cout << "File " << argv[1] << " copied successfully" << endl;
//	cout << "Time:  " << time << endl;
//}


//#include <windows.h>
//#include <stdio.h>
//#include <locale.h>
//#include <tchar.h>
//#include <iostream>
//#define BUF_SIZE 256
//
//using namespace std;
//
//int _tmain(int argc, LPTSTR argv[]) {
//    setlocale(LC_ALL, "Russian");
//    HANDLE hIn, hOut;
//    DWORD nIn, nOut;
//    CHAR Buffer[BUF_SIZE];
//
//    DWORD dwStart = GetTickCount();
//
//    if (argc != 3) {
//        cout << "Неверное количество аргументов командной строки" << endl;
//        return 1;
//    }
//
//    hIn = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
//    if (hIn == INVALID_HANDLE_VALUE) {
//        printf("Ошибка открытия исходного файла. Код ошибки: %x\n", GetLastError());
//        return 2;
//    }
//
//   hOut = CreateFile(argv[2], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//    if (hOut == INVALID_HANDLE_VALUE) {
//        printf("Ошибка создания целевого файла. Код ошибки: %x\n", GetLastError());
//        return 3;
//    }
//
//    while (ReadFile(hIn, Buffer, BUF_SIZE, &nIn, NULL) && nIn > 0) {
//        WriteFile(hOut, Buffer, nIn, &nOut, NULL);
//        if (nIn != nOut) {
//            printf("Ошибки записи: %x \n", GetLastError());
//            return 4;
//        }
//    }
//
//    CloseHandle(hIn);
//    CloseHandle(hOut);
//
//    DWORD dwEnd = GetTickCount();
//    
//    DWORD time = (dwEnd - dwStart);
//
//    cout << "File copied successfully" << endl;
//    cout << "Time:  " << time << endl;
//    return 0;
//}

#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    DWORD dwStart = GetTickCount();

    if (argc != 3) {
        cout << "Wrong arguments number" << endl;
        return 1;
    }

    if (!CopyFileA(argv[1], argv[2], FALSE)) {
        cout << "Not possible to copy " << argv[1] << ". Make sure this file exists." << endl;
        return 2;
    }

    DWORD dwEnd = GetTickCount();
        
    DWORD time = (dwEnd - dwStart);

    cout << "File copied successfully" << endl;
    cout << "Time:  " << time << endl;

    return 0;
}