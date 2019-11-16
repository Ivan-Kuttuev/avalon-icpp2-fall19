#include<iostream>
#include "CharArray.hpp"

using namespace std;
using namespace ext;

using charArray = char*;





int main()
{

	charArray str = new char[6]{ "hello" };
	charArray str2 = new char[7]{ " world" };

	char result = characterAt(str, 1);//h
	char result2 = characterAt(str, 4);//l

	concatenate(str, str2);// hello world
    append(str2, '$');

	charArray str_result = substring(str, 4, 4);

}