#include <conio.h>
#include "Loading.h"

using namespace std;

void Start()
{																		//Анимация загрузки.
	cout << " Запустить программу(Enter)\n";
	_getch();
	cout << " Запуск программы:\n";

	Loading(60, 10);

	for (int i = 0; i < 2; i++)
	{
		system("cls");
		cout << " Запустить программу(Enter)\n";
		cout << " Запуск программы:\n";

		Loading(60, 10);
		Sleep(100);
	}
}