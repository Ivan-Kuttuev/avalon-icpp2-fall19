#include "Header.hpp"
#include<iostream>
namespace ext
{
	void append(charString* &str, char symbol)
	{
		charString* ptr = new charString{ symbol };

		if (str == nullptr)
		{
			str = ptr;
			return;
		}

		charString* temp = str;

		while (temp->nextSymbol != nullptr)
		{
			temp = temp->nextSymbol;
		}
		temp->nextSymbol = ptr;
	}

	void print(charString* str)
	{
		while(str!= nullptr)
		{
			std::cout << str->symbol;
			str = str->nextSymbol;
		}
	}
}