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

	swap(lhs, rhs);

	cout << lhs.year << " " << static_cast<int>(lhs.month) << " " << lhs.day << "   "
		<< rhs.year << " " << static_cast<int>(rhs.month) << " " << rhs.day << endl;
}