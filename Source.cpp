#include "Date.hpp"
#include <iostream>

using namespace std;
using namespace ext;

int main()
{
	Date datefrom{ 2018,Month::December,1 };
	//Date dateto{ 10,Month::September,221 };

	TimeDelta delta = countJND(datefrom);
	//TimeDelta delta = countJND(dateto);

	cout << countJND(datefrom).delta;


	
}