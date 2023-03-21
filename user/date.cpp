#include "date.h"

date::date()
{
	 day = 1;
	 month = 1;
	 year = 1900;
}

date::date(const int day, const int month, const int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void date::show() const
{
	cout << "\t----Date----" << endl;
	cout << day << " " << month << " " << year << endl;
}

int date::getday() const
{
	return day;
}

int date::getmonth() const
{
	return month;
}

int date::getyear() const
{
	return year;
}

void date::setday(const int day)
{
	if (day > 0 && day <=31)
	{
		this->day = day;
	}
}

void date::setmonth(const int month)
{
	if (month > 0 && month <= 31)
	{
		this->month = month;
	}
}

void date::setyear(const int year)
{
	
		this->year = year;
	
}
