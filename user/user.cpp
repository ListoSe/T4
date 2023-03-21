#include "user.h"

user::user(const char* login, const char* password, const char* email, date birth)
{
	this->login = new char[strlen(login) + 1];
	strcpy_s(this->login, strlen(login) + 1, login);
	this->password = new char[strlen(password) + 1];
	strcpy_s(this->password, strlen(password) + 1, password);
	this->email = new char[strlen(email) + 1];
	strcpy_s(this->email, strlen(email) + 1, email);

	this->birth = birth;
}

user::~user()
{
	delete[]login;
	delete[]password;
	delete[]email;

}

void user::show() const
{
	cout << "\t---- user ----" << endl;
	cout << "Login - " << login<<endl;
	cout << "Password - " << password << endl;
	cout << "Email - " << email << endl;
	cout << "Birth - " << birth.getday() << " " << birth.getmonth() << " " <<  birth.getyear() << endl;

}

const char* user::getlogin()const
{
	return login;
}

const char* user::getpassword()const
{
	return password;
}

const char* user::getemail()const
{
	return email;
}

const date user::getbirth()const
{
	return date();
}



void user::setlogin(const char* login)
{
	delete[]this->login;
	this->login = new char[strlen(login) + 1];
	strcpy_s(this->login, strlen(login) + 1, login);
}

void user::setmonth(const char* password)
{
	delete[]this->password;
	this->password = new char[strlen(password) + 1];
	strcpy_s(this->password, strlen(password) + 1, password);
}

void user::setyear(const char* email)
{
	delete[]this->email;
	this->email = new char[strlen(email) + 1];
	strcpy_s(this->email, strlen(email) + 1, email);
}

void user::setbirth(date b)
{
	this->birth = b;

}

void user::tobinfile()
{
	FILE* fp;
	fopen_s(&fp, login, "wb");
	if (fp == 0)
	{
		cout << "ERROR!!!" << endl;
	}
	else
	{
		int size_login = strlen(login) + 1;
		fwrite(&size_login, sizeof(int), 1, fp);
		fwrite(login, sizeof(char), size_login, fp);

		int size_password = strlen(password) + 1;
		fwrite(&size_password, sizeof(int), 1, fp);
		fwrite(password, sizeof(char), size_password, fp);

		int size_email = strlen(email) + 1;
		fwrite(&size_email, sizeof(int), 1, fp);
		fwrite(email, sizeof(char), size_email, fp);

		fwrite(&birth, sizeof(date), 1, fp);
		fclose(fp);
		cout << "user saved" << endl;



	}
}

void user::frombinfile()
{
	FILE* fp;
	fopen_s(&fp, login, "rb");
	if (fp == 0)
	{
		cout << "ERROR!!!" << endl;
	}
	else
	{
		int size_login = 0;
		fread(&size_login, sizeof(int), 1, fp);
		login = new char[size_login];
		fread(login, sizeof(char), size_login, fp);

		int size_password = 0;
		fread(&size_password, sizeof(int), 1, fp);
		password = new char[size_password];
		fread(password, sizeof(char), size_password, fp);

		int size_email = 0;
		fread(&size_email, sizeof(int), 1, fp);
		email = new char[size_email];
		fread(email, sizeof(char), size_email, fp);

		fread(&birth, sizeof(date), 1, fp);
		fclose(fp);
		cout << "user saved" << endl;



	}
}

bool user::isloginavaivlbale() const
{
	FILE* fp;
	fopen_s(&fp, login, "rb");
	if (fp == NULL)
	{
		cout << "User not found"<<endl;
		return true;
	}
	else
	{
		fclose(fp);	
		return false;
	}
	
}

int user::calccomplesity() const
{
	bool upper = false;
	bool lower = false;
	bool num = false;
	bool symvol = false;
	for (int i = 0; i < strlen(password); i++)
	{
		if (isupper(password[i]))
		{
			upper = true;
		}
		else if (islower(password[i]))
		{
			lower = true;
		}
		else if (isdigit(password[i]))
		{
			num = true;
		}
		else 
		{
			symvol = true;
		}
	}
	return upper + lower + num + symvol;
}

bool user::isvailemail() const
{
	int index = -1;
	int amount = 0;
	for (int i = 0; i < strlen(email); i++)
	{
		if (email[i] == '@')
		{
			index = i;
			amount++;
		}

	}
	if (index <= 0 || index > strlen(email) - 3 || amount != 1) 
	{
		return false;
	}
	return true;
}

void user::signup()
{
	if (!isloginavaivlbale())
	{
		cout << "ERROR: login is exist" << endl;
	}
	else if (calccomplesity() < 3)
	{
		cout << "ERROR: password is too easy" << endl;
		cout << "(upercase, lowercase,diget,symbol)" << endl;
	}
	else if (!isvailemail())
	{
		cout << "ERROR: email isn't correct" << endl;
	}
	else
	{
		tobinfile();
		cout << "user is register" << endl;
	}
}

bool user::signin()
{
	return false;
}

void user::userisbirth() const
{
	struct tm* timm = new tm;
	time_t t = time(NULL);
	localtime_s(timm, &t);

	date a(timm->tm_mday, 1 + timm->tm_mon, 0);
	if (a.getday() == getbirth().getday() && a.getmonth() == getbirth().getmonth())
	{
		system("start 1.jpg");
	}
	else
	{
		cout << "ERROR" << endl;
	}
	

}
