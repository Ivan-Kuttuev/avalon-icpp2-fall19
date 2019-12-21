#include"Exam.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include<string>

using namespace std;


void add()
{
	Book book;
	cin >>  book.Title;
	cin >> book.Author;
	cin >> book.Price;
	cin >> book.Quantity;

	ifstream fin("nextId.txt");
		fin >> book.Id;
		fin.close();
		ofstream fout("nextId.txt");
		fout << (book.Id+1);
		fout.close();

	ofstream fbout("library.bin", istream::out | istream::binary | istream::app);	

	fbout.write(reinterpret_cast<char*>(&book), sizeof(Book));

	fbout.close();
}

//void edit()
//{
//	ifstream fin("library.bin", istream::in | istream::binary);
//
//	fin.seekg(0, ios_base::end); 
//	int size = fin.tellg();
//	int count = size / sizeof(Book);
//	fin.seekg(0, ios_base::beg);
//
//	Book* book = new Book[count];
//	fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
//	fin.close();
//
//	int id;
//	cin >> id;
//
//	Book* ptr = nullptr;
//	for (int i = 0; i < count; ++i)
//	{
//		int temp(book[i].Id);
//		if (id == temp)
//		{
//			ptr = &book[i];
//			break;
//		}
//	}
//
//	
//
//}
//
void show_statistics()
{
	ifstream fin("library.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end);
	int size = fin.tellg();
	int count = size / sizeof(Book);
	fin.seekg(0, ios_base::beg);

	Book* book = new Book[count];
	fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
	fin.close();
	float sum_of_prices = 0.F;
	int sum_of_books = 0;
	for (int i = 0 ; i < count ; i++)
	{
		sum_of_prices += book[i].Price;
		sum_of_books += book[i].Quantity;
	}
	cout << "Всего книг " << sum_of_books << " Общая стоимость " << sum_of_prices << endl;
	delete[] book;
}

void view_list()
{
	ifstream fin("library.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end);
	int size = fin.tellg();
	int count = size / sizeof(Book);
	fin.seekg(0, ios_base::beg);

	Book* book = new Book[count];
	fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
	fin.close();

	for (int i = 0; i < count - 1; i++)
	{
		bool flag = false;

		for (int j = 0; j < count - 1 - i; j++)
		{
			if (book[j].Author > book[j + 1].Author)
			{
				Book tmp;
				tmp = book[j];
				book[j + 1] = tmp;
				flag = true;

			}
		}
	}

	for (int i = 0; i < count - 1; i++)
	{
		bool flag = false;

		for (int j = 0; j < count - 1 - i; j++)
		{
			if (book[j].Title > book[j + 1].Title)
			{
				Book tmp;
				tmp = book[j];
				book[j + 1] = tmp;
				flag = true;

			}
		}
	}

	for (int i = 0; i < count ; i++)
	{
		cout << book->Id << " " << book->Title << " " << book->Author << " " << book->Price << " " << book->Quantity << endl;
	}
}

void find()
{
	ifstream fin("library.bin", istream::in | istream::binary);
	
		fin.seekg(0, ios_base::end); 
		int size = fin.tellg();
		int count = size / sizeof(Book);
		fin.seekg(0, ios_base::beg);
	
		Book* book = new Book[count];
		fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
		fin.close();
	
		string title;
		cin.ignore(100, '\n');
		getline(cin, title);
	
		Book* ptr = nullptr;
		for (int i = 0; i < count; ++i)
		{
			string temp(book[i].Title);
			if (title == temp)
			{
				ptr = &book[i];
				break;
			}
		}

		if (ptr == nullptr)
		{
			cout <<  "not found" << endl;
		}
		else
		{
			cout << ptr->Id << " " << ptr->Title << " " << ptr->Author << " " << ptr->Price << " " << ptr->Quantity << endl;
		}
		delete[] book;
}