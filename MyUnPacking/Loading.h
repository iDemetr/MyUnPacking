#include <iostream>
#include <Windows.h>

using namespace std;

void Loading(int MiliSek,int Kolich_Tochek)
{
	int i = 0;
	do
	{                                                   //�������� ��������.
		i++;
		cout << ". ";
		Sleep(MiliSek);
	} while (i != Kolich_Tochek);
}