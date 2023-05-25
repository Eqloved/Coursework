#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;

struct Initial
{
	char surname[15];
	char name[15];
	char secondname[15];
};

struct Birth_date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Subject
{
	char Subject_name[20];
	unsigned short subject_mark;
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
	Session _Session[10];
	float AVGmark;
	int SessQuan;
	char gender;
	char institute[20];
	char department[20];
	char groupnumber[20];
	char recordbook[20];
	unsigned short admission_year;
};


void RecordEntry(Record* (&d), int& n); //Ввод данных
void ReadRecord(Record* (&d), int& n, string filename); //Считывание данных из файла
void Print(Record* d, int n); //Вывод данных
void ChangeRecord(Record* (&d), int n); //Изменение данных
void DeleteRecord(Record* (&d), int& n); //Удаление данных
void AddRecord(Record* (&d), int& n); //Добавление данных
void Copy_Task(Record* (&d_n), Record* (&d_o), int n); //Копия(для задания)
void Copy(Record& Rec_new, Record& Rec_old); // Копирование данных
void FindAVGmark(Record* (&d), int n); //Поиск среднего значения оценки по предмету
void Sorting(Record* d, int n); //Сортировка
void SaveRecord(Record* d, int n, string filename); //Сохранение данных
void Task(Record* d, int n);
