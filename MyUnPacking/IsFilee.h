#include <fstream>

bool isfile(std::string filepath)                               //Функция проверки наличия файла.
{
	bool check = false;

	std::ifstream fin(filepath.c_str());

	if (fin.is_open())

		check = true;

	fin.close();

	return check;
}