#include "CharArray.hpp"

namespace ext
{

	int coutLengh(charArray str)
	{
		int length = 0;
		while (str[length] != '\0')
		{
			++length;
		}
		return length;
	}




	char characterAt(charArray str, int number)
	{
		return str[number -1];
	}


	void concatenate(charArray & first, charArray second)
	{
		int lenghFirst = coutLengh(first);
		int lenghSecond = coutLengh(second);
		
		charArray result = new char[lenghFirst + lenghSecond + 1];

		for (int i = 0; i < lenghFirst; i++)
		{
			result[i] = first[i];
		}

		for (int i = 0; i < lenghSecond; i++)
		{
			result[lenghFirst +  i] = second[i];
		}
		result[lenghFirst + lenghSecond] = '\0';
		delete[] first;

		first = result;
	}

	void append(charArray& array ,char sim)
	{
		int lenghArray = coutLengh(array);
		

		charArray result = new char[lenghArray  + 1];

		for (int i = 0; i < lenghArray; i++)
		{
			result[i] = array[i];
		}

		
		result[lenghArray] = sim;
		result[lenghArray + 1] = '\0';
		delete[] array;

		array = result;
	}

	charArray substring(charArray array, int firstPozition, int lengh)
	{
		charArray result =  new char[lengh];
		for (int i = 0; i < lengh; i++)
		{
			result[i] = array[i + firstPozition];
		}
		return result;
	}
}