#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;

struct Initial
{
	char surname[20];
	char name[20];
	char secondname[20];
};

struct Birth_date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Subject
{
	char Subject_name[40];
	int subject_mark;
};

struct Session
{
	Subject _Subject[11];
	int SubQuantity;
};

struct Record
{
	Initial _Initial;
	Birth_date _Birhtdate;
	float AVGmark;
	int admission_year;
	char gender;
	char institute[30];
	char department[20];
	char groupnumber[20];
	char recordbook[20];
	int SessQuan;
	Session _Session[100];
};
class RecordFunctions
{
public:
	static void RecordEntry(Record* (&d), int& n)
	{
		cout << "Введите количество студентов: ";
		while (!(cin >> n))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		d = new Record[n]; //Выделение памяти

		for (int i = 0; i < n; i++)
		{
			cout << "Введите фамилию: ";
			cin >> d[i]._Initial.surname;
			cout << "Введите имя: ";
			cin >> d[i]._Initial.name;
			cout << "Введите отчество: ";
			cin >> d[i]._Initial.secondname;

			cout << "Введите дату рождения (день): ";
			while (!(cin >> d[i]._Birhtdate.day))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите дату рождения (месяц): ";
			while (!(cin >> d[i]._Birhtdate.month))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите дату рождения (год): ";
			while (!(cin >> d[i]._Birhtdate.year))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите год поступления: ";
			while (!(cin >> d[i].admission_year))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите пол (М или Ж): ";
			cin >> d[i].gender;

			cout << "Введите факультет(институт): ";
			cin >> d[i].institute;

			cout << "Введите кафедру: ";
			cin >> d[i].department;

			cout << "Введите номер группы: ";
			cin >> d[i].groupnumber;

			cout << "Введите номер зачетной книжки: ";
			cin >> d[i].recordbook;

			cout << "Введите количество сессий: ";
			while (!(cin >> d[i].SessQuan))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			for (int j = 0; j < d[i].SessQuan; j++)
			{
				cout << "Введите количество предметов в сессии № " << j + 1 << ":";
				while (!(cin >> d[i]._Session[j].SubQuantity))
				{
					cout << "Введите целое число: ";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				for (int m = 0; m < d[i]._Session[j].SubQuantity; m++)
				{
					cout << "Введите название предмета: ";
					cin.ignore();
					cin.getline(d[i]._Session[j]._Subject[m].Subject_name, 40);

					cout << "Введите оценку за предмет: ";
					while (!(cin >> d[i]._Session[j]._Subject[m].subject_mark))
					{
						cout << "Введите целое число: ";
						cin.clear();
						cin.ignore(1000, '\n');
					}

				}
			}

			cout << "_______________________________________" << endl;
		}
	}
	static void ReadRecord(Record* (&d), int& n, string filename)
	{
		ifstream reading(filename, ios::in);

		if (reading)
		{
			reading.read((char*)&n, sizeof(n));

			d = new Record[n];

			for (int i = 0; i < n; i++)
			{

				reading.read(d[i]._Initial.surname, sizeof(d[i]._Initial.surname));
				reading.read(d[i]._Initial.name, sizeof(d[i]._Initial.name));
				reading.read(d[i]._Initial.secondname, sizeof(d[i]._Initial.secondname));

				reading.read((char*)&d[i]._Birhtdate.day, sizeof(d[i]._Birhtdate.day));
				reading.read((char*)&d[i]._Birhtdate.month, sizeof(d[i]._Birhtdate.month));
				reading.read((char*)&d[i]._Birhtdate.year, sizeof(d[i]._Birhtdate.year));

				reading.read((char*)&d[i].admission_year, sizeof(d[i].admission_year));

				reading.read((char*)&d[i].gender, sizeof(d[i].gender));

				reading.read(d[i].institute, sizeof(d[i].institute));

				reading.read(d[i].department, sizeof(d[i].department));

				reading.read(d[i].groupnumber, sizeof(d[i].groupnumber));

				reading.read(d[i].recordbook, sizeof(d[i].recordbook));;

				reading.read((char*)&d[i].SessQuan, sizeof(d[i].SessQuan));;

				for (int j = 0; j < d[i].SessQuan; j++)
				{
					reading.read((char*)&d[i]._Session[j].SubQuantity, sizeof(d[i]._Session[j].SubQuantity));

					for (int m = 0; m < d[i]._Session[j].SubQuantity; m++)
					{
						reading.read((char*)&d[i]._Session[j]._Subject[m].Subject_name, sizeof(d[i]._Session[j]._Subject[m].Subject_name));
						reading.read((char*)&d[i]._Session[j]._Subject[m].subject_mark, sizeof(d[i]._Session[j]._Subject[m].subject_mark));
					}
				}


			}
			cout << "Данные считаны!" << endl;

		}
		else
			cout << "Ошибка открытия файла!" << endl;

		reading.close();
	}
	static void Print(Record* d, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "ФИО: " << d[i]._Initial.surname << " " << d[i]._Initial.name << " " << d[i]._Initial.secondname << endl;
			cout << "Дата рождения: " << d[i]._Birhtdate.day << "" << d[i]._Birhtdate.month << "" << d[i]._Birhtdate.year << "" << endl;
			cout << "Дата поступления: " << d[i].admission_year << "" << endl;
			cout << "Пол: " << d[i].gender << "" << endl;
			cout << "Факультет(институт): " << d[i].institute << "" << endl;
			cout << "Кафедра:" << d[i].department << "" << endl;
			cout << "Номер группы: " << d[i].groupnumber << "" << endl;
			cout << "Номер зачетной книжки: " << d[i].recordbook << "" << endl;
			cout << "Количество сессий: " << d[i].SessQuan << "" << endl;
			for (int m = 0; m < d[i].SessQuan; m++)
			{
				cout << "Количество предметов: " << m + 1 << " " << endl;
				for (int j = 0; j < d[i]._Session[m].SubQuantity; j++)
				{
					cout << "Предмет: " << d[i]._Session[m]._Subject[j].Subject_name << "" << endl;
					cout << "Оценка: " << d[i]._Session[m]._Subject[j].subject_mark << endl;
				}
			}

			cout << "_______________________________________________" << endl;
		}
	}
	static void ChangeRecord(Record* (&d), int n)
	{
		int _n;
		cout << "Введите номер элемента, который хотите изменить" << endl;
		while (!(cin >> _n))
		{
			cout << "Введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		_n--;

		system("cls");

		if (_n >= 0 && _n < n)
		{
			cout << "Введите фамилию: ";
			cin >> d[_n]._Initial.surname;
			cout << "Введите имя: ";
			cin >> d[_n]._Initial.name;
			cout << "Введите отчество: ";
			cin >> d[_n]._Initial.secondname;

			cout << "Введите дату рождения (день): ";
			while (!(cin >> d[_n]._Birhtdate.day))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите дату рождения (месяц): ";
			while (!(cin >> d[_n]._Birhtdate.month))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите дату рождения (год): ";
			while (!(cin >> d[_n]._Birhtdate.year))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите год поступления: ";
			while (!(cin >> d[_n].admission_year))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите пол (М или Ж): ";
			cin >> d[_n].gender;

			cout << "Введите факультет(институт): ";
			cin >> d[_n].institute;

			cout << "Введите кафедру: ";
			cin >> d[_n].department;

			cout << "Введите номер группы: ";
			cin >> d[_n].groupnumber;

			cout << "Введите номер зачетной книжки: ";
			cin >> d[_n].recordbook;

			cout << "Введите количество сессий: ";
			while (!(cin >> d[_n].SessQuan))
			{
				cout << "Введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			for (int j = 0; j < d[_n].SessQuan; j++)
			{
				cout << "Введите количество предметов в сессии № " << j + 1 << ":";
				while (!(cin >> d[_n]._Session[j].SubQuantity))
				{
					cout << "Введите целое число: ";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				for (int m = 0; m < d[_n]._Session[j].SubQuantity; m++)
				{
					cout << "Введите название предмета: ";
					cin.ignore();
					cin.getline(d[_n]._Session[j]._Subject[m].Subject_name, 40);

					cout << "Введите оценку за предмет: ";
					while (!(cin >> d[_n]._Session[j]._Subject[m].subject_mark))
					{
						cout << "Введите целое число: ";
						cin.clear();
						cin.ignore(1000, '\n');
					}

				}
			}

			cout << "_______________________________________" << endl;
		}
		else
			cout << "Неправильный номер введенного элемента" << endl;
	}
	static void DeleteRecord(Record* (&d), int& n)
	{
		int _n;
		cout << "Введите номер элемента, который хотите удалить(от 1 до " << n << "): ";
		cin >> _n;
		while (!(cin >> _n))
		{
			cout << "Неправильный номер элемента, введите номер заново: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		_n--;

		system("cls");

		if (_n >= 0 && _n < n)
		{
			Record* mass = new Record[n];

			Copy_Task(mass, d, n);

			--n;
			d = new Record[n];

			int q = 0;

			for (int i = 0; i <= n; i++)
			{
				if (i != _n)
				{
					d[q] = mass[i];
					++q;
				}
			}
			system("cls");
			delete[]mass;

			cout << "Данные были удалены!" << endl;
		}
		else
			cout << "Неверно введен номер элемента" << endl;
	}
	/*static void FindAVGmark(Record* (&d), int n)
	{
		float c = 0;
		float k = 0;
		float maxAVGmark = 0;

		for (int i = 0; i < n; i++)
		{
			for (int f = 0; f < d[i].SessQuan; f++)
			{
				k += d[i]._Session[f].SubQuantity;
			}
			for (int j = 0; j < d[i].SessQuan; j++)
			{
				for (int m = 0; m < d[i]._Session[j].SubQuantity; m++)
				{
					c += d[i]._Session[j]._Subject[m].subject_mark;
				}
			}
			d[i].AVGmark = c / k;
			while (d[i].AVGmark > d[i + 1].AVGmark)
			{
				maxAVGmark += d[i + 1].AVGmark;
			}
			if (maxAVGmark)
			{

			}
		}
	}*/
	static void Copy_Task(Record* (&d_n), Record* (&d_o), int n)
	{
		for (int i = 0; i < n; i++)
		{
			d_n[i] = d_o[i];
		}
	}
	static void AddRecord(Record* (&d), int& n)
	{
		Record* mass = new Record[n]; //временный массив

		Copy_Task(mass, d, n); //сохраняем данные в временный массив

		n++;
		d = new Record[n]; //новая память

		Copy_Task(d, mass, --n);

		cout << "Введите фамилию: ";
		cin >> d[n]._Initial.surname;
		cout << "Введите имя: ";
		cin >> d[n]._Initial.name;
		cout << "Введите отчество: ";
		cin >> d[n]._Initial.secondname;

		cout << "Введите пол: ";
		cin >> d[n].gender;

		cout << "Введите дату рождения (число): ";
		while (!(cin >> d[n]._Birhtdate.day))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Введите дату рождения (месяц): ";
		while (!(cin >> d[n]._Birhtdate.month))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Введите дату рождения (год): ";
		while (!(cin >> d[n]._Birhtdate.year))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "Введите год поступления: ";
		while (!(cin >> d[n].admission_year))
		{
			cout << "Введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "Введите название факультета: ";
		cin >> d[n].institute;

		cout << "Введите название кафедры: ";
		cin >> d[n].department;

		cout << "Введите номер группы: ";
		cin >> d[n].groupnumber;

		cout << "Введите номер зачетной книжки: ";
		cin >> d[n].recordbook;

		cout << "Введите количество сессий: ";
		while (!(cin >> d[n].SessQuan))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		for (int j = 0; j < d[n].SessQuan; j++)
		{
			cout << "Введите количество предметов в сессии №" << j + 1 << "): ";
			while (!(cin >> d[n]._Session[j].SubQuantity))
			{
				cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}

			for (int m = 0; m < d[n]._Session[j].SubQuantity; m++)
			{
				cout << "Введите название предмета: ";
				cin.ignore();
				cin.getline(d[n]._Session[j]._Subject[m].Subject_name, 40);

				cout << "Введите оценку: ";
				while (!(cin >> d[n]._Session[j]._Subject[m].subject_mark))
				{
					cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
					cin.clear();
					cin.ignore(1000, '\n');
				}

			}
		}

		delete[]mass;
	}
	static void SaveRecord(Record* d, int n, string filename)
	{
		ofstream record(filename, ios::binary); //поток для записи	

		if (record)
		{
			record.write((char*)&n, sizeof(n));
			for (int i = 0; i < n; i++)
			{

				record.write(d[i]._Initial.surname, sizeof(d[i]._Initial.surname));
				record.write(d[i]._Initial.name, sizeof(d[i]._Initial.name));
				record.write(d[i]._Initial.secondname, sizeof(d[i]._Initial.secondname));

				record.write((char*)&d[i]._Birhtdate.day, sizeof(d[i]._Birhtdate.day));
				record.write((char*)&d[i]._Birhtdate.month, sizeof(d[i]._Birhtdate.month));
				record.write((char*)&d[i]._Birhtdate.year, sizeof(d[i]._Birhtdate.year));

				record.write((char*)&d[i].admission_year, sizeof(d[i].admission_year));

				record.write((char*)&d[i].gender, sizeof(d[i].gender));

				record.write(d[i].institute, sizeof(d[i].institute));

				record.write(d[i].department, sizeof(d[i].department));

				record.write(d[i].groupnumber, sizeof(d[i].groupnumber));

				record.write(d[i].recordbook, sizeof(d[i].recordbook));;

				record.write((char*)&d[i].SessQuan, sizeof(d[i].SessQuan));;

				for (int j = 0; j < d[i].SessQuan; j++)
				{
					record.write((char*)&d[i]._Session[j].SubQuantity, sizeof(d[i]._Session[j].SubQuantity));

					for (int m = 0; m < d[i]._Session[j].SubQuantity; m++)
					{
						record.write((char*)&d[i]._Session[j]._Subject[m].Subject_name, sizeof(d[i]._Session[j]._Subject[m].Subject_name));
						record.write((char*)&d[i]._Session[j]._Subject[m].subject_mark, sizeof(d[i]._Session[j]._Subject[m].subject_mark));
					}
				}
			}
			cout << "Данные сохранены!" << endl;
		}
		else
			cout << "Ошибка сохранения файла!" << endl;
		record.close();
	}
	/*static void Task(Record* d, int n)
	{


		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (d[i].gender > d[j].gender)
				{
					swap(d[i], d[j]);
				}
			}
		}
		int Currentgender = d[0].gender;
		int maxMarkindex = 0;
		int minMarkindex = 0;
		double maxMark = 0.0;
		double minMark = 5.0;

		for (int i = 0; i < n; i++)
		{
			if (d[i].gender != Currentgender)
			{
				cout << "Студент с наибольшей успеваемостью среди мужского пола: " << Currentgender << ":" << endl;
				cout << d[maxMarkindex]._Initial.surname << "" << d[maxMarkindex]._Initial.name << "" << d[maxMarkindex]._Initial.secondname << endl;

				cout << "Студент с наименьшей успеваемостью среди женского пола: " << Currentgender << ":" << endl;
				cout << d[minMarkindex]._Initial.surname << "" << d[minMarkindex]._Initial.name << "" << d[minMarkindex]._Initial.secondname << "" << endl;
			}
			cout << "Студент с наибольшей успеваемостью среди мужского пола: " << Currentgender << ":" << endl;
			cout << d[maxMarkindex]._Initial.surname << "" << d[maxMarkindex]._Initial.name << "" << d[maxMarkindex]._Initial.secondname << endl;

			cout << "Студент с наименьшей успеваемостью среди женского пола: " << Currentgender << ":" << endl;
			cout << d[minMarkindex]._Initial.surname << "" << d[minMarkindex]._Initial.name << "" << d[minMarkindex]._Initial.secondname << "" << endl;

			Currentgender = d[i].gender;
			maxMarkindex = i;
			minMarkindex = 0;
			maxMark = 0.0;
			minMark = 5.0;

			double success = 0.0;
			for (int j = 0; j < d[i].SessQuan; j++)
			{
				for (int m = 0; m < d[i]._Session[j].SubQuantity; m++)
				{
					success += d[i]._Session[j]._Subject[m].subject_mark;
				}
			}
			double AVGmark = success / (d[i].SessQuan * d[i]._Session[0].SubQuantity);

			if (AVGmark > maxMark)
			{
				maxMark = AVGmark;
				maxMarkindex = i;
			}
			if (AVGmark < minMark)
			{
				minMark = AVGmark;
				minMarkindex = i;
			}
		}
		cout << "Студент с наибольшей успеваемостью среди пол";
	}*/
	static void Task(Record* d, int n)
	{
		int choicecondition;
		cout << "Выберите среди какого пола найти студентов с наименьше и наибольшей успеваемостью(М(1) или Ж(2)): ";
		cin >> choicecondition;
		switch (choicecondition)
		{
		case(1):
			if (choicecondition == 1)
			{
				float maxAVGmark = 0;
				float minAVGmark = 5.0;
				int maxindex = 0;
				int minindex = 0;
				for (int i = 0; i < n; i++)
				{
					float k = 0;
					for (int f = 0; f < d[i].SessQuan; f++)
					{
						k += d[i]._Session[f].SubQuantity;
					}
					if ((char*)&d[i].gender == "М" || (char*)&d[i].gender == "м")
					{
						float AVGmark = 0;
						for (int j = 0; j < d[i].SessQuan; j++)
						{
							for (int m = 0; m < d[i]._Session[j].SubQuantity; m++)
							{
								for (int k = 0; k < d[i]._Session[j]._Subject[m].subject_mark; k++)
								{
									AVGmark += d[i]._Session[j]._Subject[m].subject_mark;
								}
							}
						}
						d[i].AVGmark = AVGmark / k;
						if (d[i].AVGmark > maxAVGmark) 
						{
							maxAVGmark = d[i].AVGmark;
							maxindex = i;
						}
						if (d[i].AVGmark < minAVGmark) 
						{
							minAVGmark = d[i].AVGmark;
							minindex = i;
						}
					}
					cout << "ФИО студента с наибольшей успеваемостью: " << d[maxindex]._Initial.surname << "" << d[maxindex]._Initial.name << "" << d[maxindex]._Initial.secondname << endl;
					cout << "Средний балл: " << d[maxindex].AVGmark << endl;
					cout << "ФИО студента с наименьшей успеваемостью: " << d[minindex]._Initial.surname << "" << d[minindex]._Initial.name << "" << d[minindex]._Initial.secondname << endl;
					cout << "Средний балл: " << d[minindex].AVGmark << endl;
				}
			}

		case(2):
			if (choicecondition == 2)
			{
				float maxAVGmark = 0;
				float minAVGmark = 5.0;
				int maxindex = 0;
				int minindex = 0;
				for (int i = 0; i < n; i++)
				{
					float k = 0;
					for (int f = 0; f < d[i].SessQuan; f++)
					{
						k += d[i]._Session[f].SubQuantity;
					}
					if ((char*)&d[i].gender == "Ж" || (char*)&d[i].gender == "ж")
					{
						float AVGmark = 0;
						for (int j = 0; j < d[i].SessQuan; j++)
						{
							for (int m = 0; m < d[i]._Session[j].SubQuantity; m++)
							{
								for (int k = 0; k < d[i]._Session[j]._Subject[m].subject_mark; k++)
								{
									AVGmark += d[i]._Session[j]._Subject[m].subject_mark;
								}
							}
						}
						d[i].AVGmark = AVGmark / k;
						if (d[i].AVGmark > maxAVGmark)
						{
							maxAVGmark = d[i].AVGmark;
							maxindex = i;
						}
						if (d[i].AVGmark < minAVGmark)
						{
							minAVGmark = d[i].AVGmark;
							minindex = i;
						}
					}
					cout << "ФИО студента с наибольшей успеваемостью: " << d[maxindex]._Initial.surname << "" << d[maxindex]._Initial.name << "" << d[maxindex]._Initial.secondname << endl;
					cout << "Средний балл: " << d[maxindex].AVGmark << endl;
					cout << "ФИО студента с наименьшей успеваемостью: " << d[minindex]._Initial.surname << "" << d[minindex]._Initial.name << "" << d[minindex]._Initial.secondname << endl;
					cout << "Средний балл: " << d[minindex].AVGmark << endl;
				}
			}
		}
	}

};
