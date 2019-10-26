#include "Date.hpp"
#include <iostream>

using namespace std;
using namespace ext;

int main()
{
	Date date{ 2018,Month::December,1 };
	Date dateto{ 2020,Month::September,4 };

	TimeDelta delta1 = countJND(date);


	cout << delta1.delta << endl;

	TimeDelta distance = countDistance(date, dateto);







	cout << distance.delta << endl;

	print(date, DateFormat::MonthAsInt); //2018 12 1
	cout << endl;

	print(date, DateFormat::MonthAsString); //2018 december 1
	cout << endl;

	//print(delta1);
	//	cout << endl;


	Month month = Month::May;

	print(month, DateFormat::MonthAsInt);  // 5
	cout << endl;

	print(month, DateFormat::MonthAsString);  // may
	cout << endl;



	Season season1 = getSeason(date);
	cout << season1 << endl;

	Season season2 = getSeason(month);
	cout << season2 << endl;

	Date first = { 2003 , Month::May , 5 };
	Date second = { 2003 , Month::May , 5 };
	Date third = { 2004 , Month::April , 5 };

	cout << (first == second) << endl; //1
	cout << (second != third) << endl; //1
	cout << (first < third) << endl; //1
	cout << (first <= second) << endl; //1
	cout << (third <= first) << endl; //0
	cout << (first > second) << endl; //0
	cout << (third > first) << endl; //1
	cout << (first >= second) << endl; //1
	cout << (second >= third) << endl; //0

	/*int mult1 = 4;*/

	/*cout << (delta1 * mult1) << endl;*/

}