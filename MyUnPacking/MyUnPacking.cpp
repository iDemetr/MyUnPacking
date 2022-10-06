#include <string>
#include "IsFilee.h"
#include "Start.h"

using namespace std;

struct SPort																					//Структура Портов.
{
	char NamePort[15];																			//Название Порта.
	char Contry[15];																			//Название Страны.
	char Sea[15];																				//Название моря.
};

struct SRase																					//Структура Рейсов.
{
	char NameSudna[20];																			//Название Судна.
	char PortOtpr[15];																			//Порт отправления.
	char PortPribit[15];																		//Порт прибытия.
};

SPort FindPort(char FindLocalPort[15], string Path)												//Процедура поиска в файле портов.
{
	SPort Local;

	ifstream f1(Path);
	//f1.open(Path, ios::in);

	while (!f1.eof())
	{
		f1 >> Local.NamePort;
		f1 >> Local.Contry;
		f1 >> Local.Sea;

		if (_stricmp(FindLocalPort, Local.NamePort) == 0)
			break;
	}
	f1.close();
	return Local;
}

SRase FindRase(char FindLocalRase[15], string Path)												//Процедура поиска в файле рейсов.
{
	SRase Local;

	ifstream f2(Path);

	while (!f2.eof())
	{
		f2 >> Local.NameSudna;
		f2 >> Local.PortOtpr;
		f2 >> Local.PortPribit;

		if (_stricmp(FindLocalRase, Local.NameSudna) == 0)
			break;
	}
	f2.close();
	return Local;
}

SRase FindPortInRase(char FindLocalPort[15], string Path)										//Процедура поиска портов в файле рейсов.
{
	SRase Local;

	ifstream f2(Path);

	while (!f2.eof())
	{
		f2 >> Local.NameSudna;
		f2 >> Local.PortOtpr;
		f2 >> Local.PortPribit;

		if ((!_stricmp(FindLocalPort, Local.PortOtpr) == 0) && (!_stricmp(FindLocalPort, Local.PortPribit) == 0))
			continue;
		else
			break;
	}
	f2.close();
	return Local;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);																			//Русский язык в консоли.
	SetConsoleOutputCP(1251);																	//Русский язык в файле.

	char ch = 0;																				//Буфер ввода.
	int i = 0;																					//Счетчик.
	int Flag1 = 0;																				//Цикл всей программы.
	int Flag2 = 0;																				//Цикл подпрограммы.

	SPort MySPort;																				//Переменная Структуры Портов.
	SRase MySRase;																				//Переменная Структуры Рейсов.

	string Rase1;																				//Поиск типа string.
	string Buffer;																				//Поиск типа string.
	string PortName = "Ports.txt";																//Путь к файлу Портов.
	string RaseName = "Rase.txt";																//Путь к файлу Рейсов.
	string PathName = "C:Users/User/Desktop/";													//Путь к рабочему столу.

	Start();																					//Анимация загрузки.

	if (isfile(PortName) && isfile(RaseName))													//Проверка наличия исходных файлов.
	{
		cout << "\n\n Исходные файлы обнаружены.\n  ";
		while (Flag1 < 1)																		//Переход в меню.
		{
			cout << "\n Начать поиск Перевозок, осуществляемых судами.			(1)";
			cout << "\n Сформировать все данные в одном файле.				(2)";
			cout << "\n Выйти из программы.						(esc) \n";

			ch = _getch();
			if (ch == 49)																		//Выбран 1 вариант.
			{
				system("cls");

				Flag2 = 0;
				while (Flag2 < 1)																//Цикл многократного поиска.
				{
					cout << "\n --------------------------------------------";
					cout << "\n Введите запрос: ";												//Ввод запроса.

					getline(cin, Rase1);

					char* Rase = new char[Rase1.size()];
					for (size_t r = 0; r < (Rase1.length()) + 1; r++)							//Замена пробелов в воде на Тире(-).
					{
						if (Rase1[r] == ' ')
							Rase1[r] = '-';
						Rase[r] = Rase1[r];
					};

					cout << Rase;

					MySRase = FindRase(Rase, RaseName);											//Сканирование файла рейсов.

					if (_stricmp(Rase, MySRase.NameSudna) == 0)									//Если рейс найден.
					{
						cout << "\n Рейс " << Rase << " обнаружен.\n";
						cout << "\n Порт Отправления: " << MySRase.PortOtpr;					//Вывод порта отправления.

						MySPort = FindPort(MySRase.PortOtpr, PortName);

						if (_stricmp(MySRase.PortOtpr, MySPort.NamePort) == 0)					//Вывод информации о порте.
						{
							cout << "	Страна: " << MySPort.Contry;
							cout << "\n				Море: " << MySPort.Sea;
						}
						else
							cout << "\n Данные о " << MySRase.PortOtpr << " отсутсвуют...";		//Если информация отсутствует.

						cout << "\n\n Порт Прибытия: " << MySRase.PortPribit;

						MySPort = FindPort(MySRase.PortPribit, PortName);

						if (_stricmp(MySRase.PortPribit, MySPort.NamePort) == 0)				//Вывод информации о порте.
						{
							cout << "	Страна: " << MySPort.Contry;
							cout << "\n				Море: " << MySPort.Sea;
						}
						else
							cout << "\n Данные о " << MySRase.PortPribit << " отсутсвуют...";	//Если информация отсутствует.

						cout << "\n\n Продолжить поиск\t\t\t(Enter)\n Выйти в меню программы.\t\t(Esc)\n";
					}
					else
					{
						cout << "\n Данный маршрут не найден.\n Повторить попытку\t\t\t\t(Enter)\n Выйти в меню программы.\t\t\t(Esc)\n\n";
					}
					while (1 > 0)															//Ожидание нажатия клавиши Enter or ESC.
					{
						ch = _getch();
						if (ch == 27)														//Если нажата клавиша ESC 
						{
							system("cls");													//Закончить цикл считывания клавиш
							Flag2 = 1;														//Закончить цикл многократного поиска
							break;															//И перейти в меню.
						}
						if (ch == 13)														//Если продолжить поиск
						{																	//Закончить цикл считывания клавиш.
							break;
						}
						else continue;														//Если нажата случайная клавиша
					}																		//Запросить ее снова.
				}
			}
			/************************************** Составление отдельной таблицы **************************************/
			else
				if (ch == 50)
				{
					system("cls");

					ofstream f3("Input.txt");													//Файл выхода;
					ifstream f1(RaseName);														//файл Рейсов;
					ifstream f2(PortName);														//Файл Портов;

					f3 << " Рейсы: \tПорт Отправления/Прибытия: \tСтрана: \tМоре: \n";

					while (!f1.eof())															//Пока не достигнут конец файла Рейсов.
					{
						f1 >> MySRase.NameSudna;
						f1 >> MySRase.PortOtpr;
						f1 >> MySRase.PortPribit;

						if (strlen(MySRase.NameSudna) >= strlen("        "))					//Корректировка вывода по столбцу Рейсов.
							f3 << "\n" << MySRase.NameSudna << "\t\t " << MySRase.PortOtpr;
						else
							f3 << "\n" << MySRase.NameSudna << "\t\t\t " << MySRase.PortOtpr;

						MySPort = FindPort(MySRase.PortOtpr, PortName);

						if (_stricmp(MySRase.PortOtpr, MySPort.NamePort) == 0)					//Вывод информации о порте.
						{
							if (strlen(MySRase.PortOtpr) >= strlen("       "))					//Корректировка вывода по столбцу Портов. 
							{																									//
								if (strlen(MySPort.Contry) >= strlen("       "))											   //
									f3 << "\t\t" << MySPort.Contry << "\t" << MySPort.Sea << "\n";							  //
								else																						 //
									f3 << "\t\t" << MySPort.Contry << "\t\t" << MySPort.Sea << "\n";						//
							}																							   //
							else																						  //
							{																							 //
								if (strlen(MySPort.Contry) >= strlen("       "))										//
									f3 << "\t\t\t" << MySPort.Contry << "\t" << MySPort.Sea << "\n";				   //
								else																				  //
									f3 << "\t\t\t" << MySPort.Contry << "\t\t" << MySPort.Sea << "\n";				 //
							}																						//
						}																						   //
						else																					  //
							f3 << "\t\t\t---- \t\t---- \n";										//*****************


						if (strlen(MySRase.NameSudna) >= strlen("       "))						//Корректировка вывода по столбцу Рейсов.
							f3 << "\t\t\t " << MySRase.PortPribit;
						else
							f3 << "\t\t\t " << MySRase.PortPribit;

						MySPort = FindPort(MySRase.PortPribit, PortName);

						if (_stricmp(MySRase.PortPribit, MySPort.NamePort) == 0)				//Вывод информации о порте.
						{
							if (strlen(MySRase.PortPribit) >= strlen("       "))				//Корректировка вывода по столбцу Портов. 
							{																									//
								if (strlen(MySPort.Contry) >= strlen("       "))											   //
									f3 << "\t\t" << MySPort.Contry << "\t" << MySPort.Sea << "\n";							  //
								else																						 //
									f3 << "\t\t" << MySPort.Contry << "\t\t" << MySPort.Sea << "\n";						//
							}																							   //
							else																						  //
							{																							 //
								if (strlen(MySPort.Contry) >= strlen("       "))										//
									f3 << "\t\t\t" << MySPort.Contry << "\t" << MySPort.Sea << "\n";				   //
								else																				  //
									f3 << "\t\t\t" << MySPort.Contry << "\t\t" << MySPort.Sea << "\n";				 //
							}																						//
						}																						   //	
						else																					  //
							f3 << "\t\t\t---- \t\t---- \n";										//*****************
					}

					while (!f2.eof())															//Пока не достигнут конец файла Портов.
					{
						f2 >> MySPort.NamePort;
						f2 >> MySPort.Contry;
						f2 >> MySPort.Sea;

						MySRase = FindPortInRase(MySPort.NamePort, RaseName);

						if (!_stricmp(MySPort.NamePort, MySRase.PortOtpr) == 0 && !_stricmp(MySPort.NamePort, MySRase.PortPribit) == 0)
						{
							f3 << "----\t\t\t" << MySPort.NamePort;

							if (strlen(MySPort.NamePort) >= strlen("        "))					//Корректировка вывода по столбцу Портов. 
							{																								  //		
								if (strlen(MySPort.Contry) >= strlen("        "))											 //
									f3 << "\t\t" << MySPort.Contry << "\t" << MySPort.Sea << "\n";							//
								else																					   //
									f3 << "\t\t" << MySPort.Contry << "\t\t" << MySPort.Sea << "\n";					  //
							}																							 //
							else																						//
							{																						   //
								if (strlen(MySPort.Contry) >= strlen("        "))									  //
									f3 << "\t\t\t" << MySPort.Contry << "\t" << MySPort.Sea << "\n";				 //
								else																				//
									f3 << "\t\t\t" << MySPort.Contry << "\t\t" << MySPort.Sea << "\n";			   //
																												  //
							}																	//*****************
						}
					}

					f3.close();
					f2.close();
					f1.close();


					cout << "\n Сохранение";

					Loading(300, 4);															//Анимация загрузки.

					cout << "\n Файл успешно сохранён в Input.txt. \n Перейти в главное меню.				(Enter)\n";
					_getch();
					system("cls");
				}
				else
					if (ch == 27)																//Выход из программы.
					{
						cout << "\n Завершение программы";

						Loading(500, 4);														//Анимация загрузки.

						return 1;
					}
					else
						cout << "\n\n Введена неправильная клавиша...\n";
		}
	}
	else																						// Если файлы не обнаружены.
	{
		if (isfile(RaseName) == false && isfile(PortName) == false)
			cout << "\n Файлы Ports.txt и Rase.txt не обнаружены по пути: " << PathName;

		if (isfile(RaseName) && isfile(PortName) == false)
			cout << "\n Файл Ports.txt не обнаружен по пути: " << PathName;

		if (isfile(RaseName) == false && isfile(PortName))
			cout << "\n Файл Rase.txt не обнаружен по пути: " << PathName;
	}

	_getch();

	cout << "\n Завершение программы";

	Loading(500, 4);																			//Анимация загрузки.

	return 0;
}