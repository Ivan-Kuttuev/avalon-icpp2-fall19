#include "CharString.hpp"
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




	void removeChars(charString* str, int count, int position)
	{
		charString* savedPtr = str;

		int currentPos = 1;
		while (currentPos !=position - 1 )
		{
			str = str->nextSymbol;
			++currentPos;
		}


		

		for (int i = 1; i <= count ; ++i)
		{
			charString* temp = str->nextSymbol;
			str ->nextSymbol= temp->nextSymbol;
			delete temp;
			

		}
	}

}