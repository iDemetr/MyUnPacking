#include <conio.h>
#include "Loading.h"

using namespace std;

void Start()
{																		//�������� ��������.
	cout << " ��������� ���������(Enter)\n";
	_getch();
	cout << " ������ ���������:\n";

	Loading(60, 10);

	for (int i = 0; i < 2; i++)
	{
		system("cls");
		cout << " ��������� ���������(Enter)\n";
		cout << " ������ ���������:\n";

		Loading(60, 10);
		Sleep(100);
	}
}