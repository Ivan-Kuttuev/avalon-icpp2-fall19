#pragma once
#pragma once
#include <iostream>
#include <string>
namespace ext
{
	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		Novemver,
		December
	};

	enum DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum Season
	{
		Winter,
		Spring,
		Summer,
		Autumn
	};

	struct Date
	{
		int year;
		Month month;
		int day;
	};

	struct TimeDelta
	{
		int delta;
	};

	/*
		Возвращает Юлианскую дату
		https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
		раздел "Вычисление номера юлианского дня (JDN) по дате григорианского календаря"
		Тестовые данные					Ожидаемый результат
		1.12.2018					2458454
		1.1.2018					2458120
		1.6.2000					2451697
		21.12.2012					2456283
	*/
	TimeDelta countJND(Date date)
	{




		int a = (14 - date.day) / 12;
		int y = date.year + 4800 - a;
		int m = static_cast<int>(date.month) + 12 * a - 3;
		int result = date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

		return TimeDelta{ result };
	}

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to)
	{
		int a1 = (14 - from.day) / 12;
		int y1 = from.year + 4800 - a1;
		int m1 = static_cast<int>(from.month) + 12 * a1 - 3;
		int result1 = from.day + (153 * m1 + 2) / 5 + 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 - 32045;

		int a2 = (14 - to.day) / 12;
		int y2 = to.year + 4800 - a2;
		int m2 = static_cast<int>(to.month) + 12 * a2 - 3;
		int result2 = to.day + (153 * m2 + 2) / 5 + 365 * y2 + y2 / 4 - y2 / 100 + y2 / 400 - 32045;

		int dist = result2 - result1;

		return TimeDelta{ dist };
	}

	std::string monthToString(Month month)
	{
		switch (month)
		{
		case Month::January:
			return "january ";			
		case Month::February:
			return "february ";
		case Month::March:
			return "march ";
		case Month::April:
			return "april ";			
		case Month::May:
			return "may ";
		case Month::June:
			return "june ";
		case Month::July:
			return "july ";
		case Month::August:
			return"august ";			
		case Month::September:
			return "september ";			
		case Month::October:
			return "october ";
		case Month::Novemver:
			return "november ";
		case Month::December:
			return  "december ";			
		default:
			return "";
		}
	}

	/*
		Выводит в консоль
	*/

	void print(Month month, DateFormat format = DateFormat::MonthAsInt)
	{
		if (format == DateFormat::MonthAsInt)
		{
			std::cout << static_cast<int>(month) << " ";
		}

		else if (format == DateFormat::MonthAsString)
		{
			std::cout << monthToString(month) << " ";
		}
	}

	void print(Date data, DateFormat format = DateFormat::MonthAsInt)
	{
		std::cout << data.year << " ";

		print(data.month, format);

		std::cout << data.day;
	}	

	void print(TimeDelta delta);




	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/
	Season getSeason(Date date)
	{
		
		if (static_cast<int>(date.month) < 3 || static_cast<int>(date.month) == 12)
		{
			return Season::Winter;
		}
		else if (static_cast<int>(date.month) > 2 && static_cast<int>(date.month) < 6)
		{
			return Season::Spring;
		}
		else if (static_cast<int>(date.month) > 5 && static_cast<int>(date.month) < 9)
		{
			return Season::Summer;
		}
		else 
		{
			return Season::Autumn;
		}
		
	}
	Season getSeason(Month month)
	{
		getSeason(month);		
	}

	/*
		Написать перегрузку для следующих логических операторов
	*/
	bool operator == (const Date lhs, const Date rhs)
	{
		return lhs.year == rhs.year
			&& lhs.month == rhs.month
			&& lhs.day == rhs.day;
	}
	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);

	}
	bool operator < (const Date lhs, const Date rhs);
	bool operator <= (const Date lhs, const Date rhs);
	bool operator > (const Date lhs, const Date rhs);
	bool operator >= (const Date lhs, const Date rhs);

	/*
		Написать перегрузку для следующих арифметических операторомв
	*/
	Date operator + (const Date date, const TimeDelta delta);
	Date operator + (const TimeDelta delta, const Date date);
	Date operator + (const TimeDelta delta, const TimeDelta date);
	Date operator - (const Date date, const TimeDelta delta);
	Date operator - (const TimeDelta delta, const Date date);
	Date operator - (const TimeDelta delta, const TimeDelta date);

	TimeDelta operator * (const TimeDelta delta, int multiplier);
	TimeDelta operator * (int multiplier, const TimeDelta delta);
	TimeDelta operator / (const TimeDelta delta, int multiplier);
	TimeDelta operator / (int multiplier, const TimeDelta delta);
}