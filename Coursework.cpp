#include "Function.h"

int MenuCondition;

void Menu()
{
	cout << "Выберите действие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод/считывание данных" << endl
		<< "(2) Вывод данных" << endl
		<< "(3) Изменение данных" << endl
		<< "(4) Удаление данных" << endl
		<< "(5) Добавление данных" << endl
		<< "(6) Поиск согласно заданию" << endl
		<< "(7) Сохраниить данные в файл" << endl
		<< "Ваш выбор:";
	cin >> MenuCondition;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();

	int _action = 0;
	int amountofdata = 0;
	string filename;
	Record* d = new Record[amountofdata];

	while (true)
	{
		switch (MenuCondition)
		{
		case (1):
			system("cls");

			cout << "Ввести данные вручную или считать из файла(1 или 2)?: ";
			cin >> _action;

			system("cls");

			if (_action == 1) 
			{
				RecordFunctions::RecordEntry(d, amountofdata);
			}
			if(_action == 2)
			{
				cout << "Введите название  файла: ";
				cin >> filename;
				RecordFunctions::ReadRecord(d, amountofdata, filename);
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case (2):
			system("cls");

			if (amountofdata != 0)
			{
				RecordFunctions::Print(d, amountofdata);
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
				RecordFunctions::ChangeRecord(d, amountofdata);
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
				RecordFunctions::DeleteRecord(d, amountofdata);
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
				RecordFunctions::AddRecord(d, amountofdata);
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
				RecordFunctions::Task(d, amountofdata);
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
				RecordFunctions::SaveRecord(d, amountofdata, filename);
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

	return 0;
};
