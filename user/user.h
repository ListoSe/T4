#pragma once
#include"date.h"
class user
{
	char* login;
	char* password;
	char* email;
	date birth;

public:
	user(const char* login, const char* password, const char* email, date birth);
	~user();
	void show()const;

	const char* getlogin()const;
	const char* getpassword()const;
	const char* getemail()const;
	const date getbirth() const; 
	void setlogin(const char* login);
	void setmonth(const char* password);
	void setyear(const char* email);
	void setbirth(date b);

	void tobinfile();
	void frombinfile();

	bool isloginavaivlbale()const;
	int calccomplesity()const;
	bool isvailemail()const;
	void signup();
	bool signin();
	void userisbirth()const;

};

