#include <iostream>
#include "Date.hpp"

using namespace std;
using namespace ext;

struct Point
{
	float x;
	float y;
};



int main()
{
	Date lhs = { 2003 , Month::May , 5 };
	Date rhs = { 2019 , Month::Novemver , 9 };

	TimeDelta lhsdelt = countJND(lhs);
	TimeDelta rhsdelt = countJND(rhs);

	swap(lhs, rhs);

	cout << lhs.year << " " << static_cast<int>(lhs.month) << " " << lhs.day << "   "
		<< rhs.year << " " << static_cast<int>(rhs.month) << " " << rhs.day << endl;

	

	swap(lhsdelt, rhsdelt);

	cout << lhsdelt.delta << " " << rhsdelt.delta << endl;


	Date & maximum = max(lhs, rhs);
	
	cout << & maximum << endl;


	Date & minimum = min(lhs, rhs);
	
	cout <<  & minimum<< endl;



	Date dates[4] = { { 2003 , Month::May , 5 } ,{ 2005 , Month::April , 8 } ,{ 2019 , Month::Novemver , 9 }, { 2002 , Month::Novemver , 29 } };

	Date & minofarray = getMinDate(dates, 4);

	cout << & minofarray << endl;

}