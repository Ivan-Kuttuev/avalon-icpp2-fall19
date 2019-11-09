#include "Date.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ext;

namespace ext
{


	TimeDelta countJND(Date date)
	{




		int a = (14 - date.day) / 12;
		int y = date.year + 4800 - a;
		int m = static_cast<int>(date.month) + 12 * a - 3;
		int result = date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

		return TimeDelta{ result };
	}
	string monthToString(Month month)
	{
		switch (month)
		{
		case Month::January:
			return "january";
		case Month::February:
			return "february";
		case Month::March:
			return "march";
		default:
			throw exception("invalid month");
		}
	}

	void print(Date data, DateFormat format)
	{
		cout << data.year << " ";
		print(data.month, format);
		cout << data.day;
	}

	void print(Month month, DateFormat format)
	{
		if (format == DateFormat::MonthAsInt)
		{
			cout << static_cast<int>(month) << " ";
		}
		else if (format == DateFormat::MonthAsString)
		{
			cout << monthToString(month) << " ";
		}
		else
		{
			throw exception("invalid format of month");
		}
	}

	bool operator == (const Date lhs, const Date rhs)
	{
		return lhs.day == rhs.day
			&& lhs.month == rhs.month
			&& lhs.year == rhs.year;
	}

	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}

	void swap(Date & lhs, Date & rhs)
	{
		Date swap;
		swap = lhs;
		lhs = rhs;
		rhs = swap;


	}

	void swap(TimeDelta & lhs, TimeDelta & rhs)
	{
		TimeDelta swap;
		swap = lhs;
		lhs = rhs;
		rhs = swap;

	}

	Date& max(Date & lhs, Date & rsh)
	{
		TimeDelta lhsdelt = countJND(lhs);
		TimeDelta rshdelt = countJND(rsh);


		if (lhsdelt.delta > rshdelt.delta)
		{
			return  lhs;
		}
		else if (rshdelt.delta > lhsdelt.delta)
		{
			return  rsh;
		}


	}

	Date& min(Date & lhs, Date & rsh)
	{
		swap(lhs, rsh);

		return max(lhs, rsh);


	}

	Date& getMinDate(Date dates[], int size)

	{
		TimeDelta element_of_array_delt;
		TimeDelta minimumdelt = countJND(dates[0]);
		Date minimum = dates[0];
		for (int i = 1; i < size; i++)
		{
			element_of_array_delt = countJND(dates[i]);
			minimumdelt = countJND(minimum);

			if (element_of_array_delt.delta < minimumdelt.delta)
			{
				minimum = dates[i];
			}
		}

	return minimum;
    }
	Date& getMaxDate(Date dates[], int size)
	{

	}
}
