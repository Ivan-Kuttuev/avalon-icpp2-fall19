#pragma once
const int SIZE = 20;

struct Book
{
	int id;
	char title[SIZE]{};
	char author[SIZE]{};
	float price;
	int quantity;
};

void add();

void edit();

void find();

void view_list();

void show_statistics();


