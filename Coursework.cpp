#include "Function.h"

int MenuCondition;
void Menu()
{
	cout << "Выберите действие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод данных" << endl
		<< "(3) Изменение данных" << endl
		<< "(4) Удаление данных" << endl
		<< "(5) Добавление данных" << endl
		<< "(6) Поиск согласно заданию" << endl
		<< "(7) Сохраниить данные в файл" << endl
		<< "Ваш выбор:";
	cin >> MenuCondition;
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();

	int _action = 0;
	int amountofdata = 0;
	string filename;

	Record* d = new Record[amountofdata];

	while (MenuCondition != 0)
	{
		switch (MenuCondition)
		{
		case (1):
			system("cls");

			cout << "Ввод вручную или из файла(1 или 2)?: ";
			cin >> _action;

			system("cls");

			if (_action == 1) {
				RecordEntry(d, amountofdata);
			}
			else
			{
				/*cout << "Введите название  файла: ";
				cin >> filename;input.txt*/

				ReadRecord(d, amountofdata, "input.txt");
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case (2):
			system("cls");

			if (amountofdata != 0)
			{
				Print(d, amountofdata);
			}
			else
				cout << "Файл пуст!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case (3):
			system("cls");

			if (amountofdata != 0)
			{
				ChangeRecord(d, amountofdata);
			}
			else
				cout << "Файл пуст!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case(4):
			system("cls");
			if (amountofdata != 0)
			{
				DeleteRecord(d, amountofdata);
			}
			else
				cout << "Данные отсутствуют!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case (5):
			system("cls");
			if (amountofdata != 0)
			{
				AddRecord(d, amountofdata);
				amountofdata++;
			}
			else
				cout << "Данные отсутствуют!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case (6):
			system("csl");
			if (amountofdata != 0)
			{
				Task(d, amountofdata);
			}
			else
				cout << "Данные отсутствуют!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case (7):
			system("cls");
			cout << "Введите название файла: ";
			cin >> filename;

			if (amountofdata != 0) {
				SaveRecord(d, amountofdata, filename);
			}
			else
				cout << "Невозможно выполнить сохранение!";

			system("pause");
			system("cls");
			Menu();
			break;
		case (0):
			system("cls");
			break;
		}
	}
};
