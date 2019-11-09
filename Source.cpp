#include <string>
#include <iostream>
#include "Extention.hpp"

using namespace ext;
using namespace std;

const int SIZE = 100;

struct Student
{
	int Id;
	int Graid;
	string Name;
};

void SortId(Student arrayid[] )
{
	Student swap;
	

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arrayid[i].Id < arrayid[j].Id)
			{
				swap = arrayid[j];
				arrayid[j] = arrayid[i];
				arrayid[i] = swap;
				
			}
		}
	}
	for (int i = 0; i < 100; i++)
	{
		cout << arrayid[i].Id << "  " << arrayid[i].Graid << "  " << arrayid[i].Name << endl;
	}
	
}

void SortGrade(Student arraygraid[], int size)
{
	Student swap;


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arraygraid[i].Graid < arraygraid[j].Graid)
			{
				swap = arraygraid[j];
				arraygraid[j] = arraygraid[i];
				arraygraid[i] = swap;

			}
		}
	}
	if (size < 100)
	{
		cout << "чтобы стать лучше " << size << "%" << " нужно набрать минимум " << arraygraid[size].Graid + 1 <<" балов";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << arraygraid[i].Id << "  " << arraygraid[i].Graid << "  " << arraygraid[i].Name << endl;
		}
	}
}

void SortName(Student arrayname[])
{
	string swap;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arrayname[i].Name < arrayname[j].Name)
			{
				swap = arrayname[j].Name;
				arrayname[j].Name = arrayname[i].Name;
				arrayname[i].Name = swap;

			}
		}
	}
	for (int i = 0; i < 100; i++)
	{
		cout << arrayname[i].Id << "  " << arrayname[i].Graid << "  " << arrayname[i].Name << endl;
	}
}


int main()
{
	Student array[SIZE];

	string data[SIZE];

	setlocale(LC_ALL, "Russian");

	for (int i = 0; i < SIZE; ++i)
	{
		array[i].Id = GetRandomValue(1, 1000);
		array[i].Graid = GetRandomValue(0, 100);


		int length = GetRandomValue(3, 6);
		char letter = GetRandomValue('A', 'Z');
		data[i] += letter;



		for (int j = 1; j < length; ++j)
		{
			data[i] += GetRandomValue('a', 'z');
		}
	
		array[i].Name = data[i];

		data[i] = "";
	}

	int howtosort;
	cout << "Чтобы сортировать по id введите 1 , по оценке 2 , по имени 3 ; 4 чтобы узнать какие оценки надо получить чтобы быть лучше 25 , 50 ,75 % студентов";
	cin >> howtosort;
	
	switch (howtosort)
	{
	case 1:
		SortId(array);
		break;
	case 2:
		SortGrade(array, SIZE);
		break;
	case 3:
		SortName(array);
		break;
	case 4:
		SortGrade(array, 25);
		SortGrade(array, 50);
		SortGrade(array, 75);
		break;

	default:
		cout << "Ошибка при вводе";
			break;

	}








}
