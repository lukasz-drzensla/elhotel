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
    int countLeap(dateTime dt); //how many leap years prior to the given date?
public:
	dateTime();
	dateTime(int _day, int _month, int _year);
	int getError();
	int getDay();
	int getMonth();
    int getYear();
    int isLeap(); //is the given date in a leap year?
    int guessMonth(int index); //return the month based on the index of the day during the year (n-th day of the year)
    int guessDay(int index); //return the day in a month based on the index of the day during the year (n-th day of the year)
    int getDifference(dateTime dt1, dateTime dt2); //difference in days between two dates, CAN be nagative - which is important for some features
    void set(dateTime dt); //works exactly the same as = operator but functions with pointers
    std::string sayHello(); //display the date in a human-friendly format
    dateTime operator = (dateTime const& obj)//does not work correctly with pointers due to some ambiguity
	{
		return obj;
	}
};

