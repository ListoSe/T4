#pragma once
#include<iostream>
#include<ctime>
using namespace std;
class date
{
	int day;
	int month;
	int year;

public:
	date();
	date(const int day, const int month, const int year);
	void show()const;
	int getday()const;
	int getmonth()const;
	int getyear()const;
	void setday(const int day);
	void setmonth(const int month);
	void setyear(const int year);

};

