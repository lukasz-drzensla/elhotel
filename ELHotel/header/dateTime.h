#pragma once
#include <string>
class dateTime
{
private:
	const int dayMonths[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day{};
	int month{};
	int year{};
	int leap = 0;
	int error = 0; //error codes: 1 - too many days, 2 - month exceeds 12, 3 - too many days in February
public:
	dateTime();
	dateTime(int _day, int _month, int _year);
	int getError();
	int getDay();
	int getMonth();
	int getYear();
	int isLeap();
	int countLeap(dateTime dt);
	int getDifference(dateTime dt1, dateTime dt2);
	void set(dateTime dt);
	std::string sayHello();
	dateTime operator = (dateTime const& obj)//for some reason this does not work correctly, always sets everything to 0
	{
		return obj;
	}
};

