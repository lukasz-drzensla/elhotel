#include "../header/dateTime.h"

dateTime::dateTime() {}
dateTime::dateTime(int _day, int _month, int _year)
{
	if (_day > dayMonths[_month])
	{
		error = 1;
	}
	if (_month > 12)
	{
		error = 2;
	}
    if (_day > 28 && _month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year%400==0))
	{
		error = 3;
	}
    if ((_year % 4 == 0 && _year % 100 != 0) || _year%400==0)
	{
		leap = 1;
	}
	day = _day;
	month = _month;
	year = _year;
}

int dateTime::getError()
{
	return error;
}

int dateTime::getDay()
{
	return day;
}

int dateTime::getMonth()
{
	return month;
}

int dateTime::getYear()
{
	return year;
}

int dateTime::isLeap()
{
	return leap;
}

int dateTime::countLeap(dateTime dt)
{
	int years = dt.getYear();
	if (dt.getMonth() == 2)
	{
		--years;
	}
    return years / 4 + years / 400 - years / 100;
}

int dateTime::getDifference(dateTime dt1, dateTime dt2)
{
    int days_1 = dt1.getYear() * 365 + dt1.getDay();
	for (int i = 1; i < dt1.getMonth(); i++)
	{
        days_1 += dayMonths[i];
	}
    days_1 += countLeap(dt1);
    int days_2 = dt2.getYear() * 365 + dt2.getDay();
	for (int i = 1; i < dt2.getMonth(); i++)
	{
        days_2 += dayMonths[i];
	}
    days_2 += countLeap(dt2);
    return (days_2-days_1);
}

void dateTime::set(dateTime dt)
{
	day = dt.getDay();
	month = dt.getMonth();
	year = dt.getYear();
	leap = dt.isLeap();
	error = dt.getError();
}

std::string dateTime::sayHello()
{
	std::string d = "";
	if (day < 10)
	{
		d += "0";
	}
	std::string m = "";
	if (month < 10)
	{
		m += "0";
	}
    return d+std::to_string(day) + ", " + m+std::to_string(month) + ", " + std::to_string(year);
}


int dateTime::guessMonth (int index)
{
    int c_days{};
    for (int i = 1; i < 13; i++)
    {
        c_days+=dayMonths[i];
        if (index < c_days)
        {
            return i;
        }
    }
    return 1;
}

int dateTime::guessDay(int index)
{
    int c_days{};
    for (int i = 1; i < 13; i++)
    {
        c_days+=dayMonths[i];
        if (index < c_days)
        {
            c_days-=dayMonths[i];
            break;
        }
    }
    return index-c_days+1;
}
