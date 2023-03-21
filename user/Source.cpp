#include"date.h"
#include"user.h"
int main() {
	date a(1, 10, 2022);

	

	/*user b("Timur", "12345678", "bula2007tim@gmail.com", date(16, 5, 2007));
	b.tobinfile();
	b.show();*/

	user myuser("", "", "", date());
	/*c.setlogin("Timur");
	c.frombinfile();
	c.show();*/

	/*a.show();
	a.setmonth(a.getmonth() + 1);
	a.show();*/
	int menu = 0;
	char s[50];
	int d = 0;
	int m = 0;
	int y = 0;
	do
	{
		cout << "1 - set login" << endl;
		cout << "2 - set password" << endl;
		cout << "3 - set email " << endl;
		cout << "4 - set date of birth" << endl;
		cout << "5 - show info" << endl;
		cout << "6 - signup " << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Input login " << endl;
			cin >> s; myuser.setlogin(s); break;
		case 2:
			cout << "Input password " << endl;
			cin >> s; myuser.setmonth(s); break;
		case 3:
			cout << "Input email " << endl;
			cin >> s; myuser.setyear(s); break;
		default:
		case 4:
			cout << "Input day of birth" << endl;
			cin >> d >> m >> y;
			myuser.setbirth(date(d, m, y));
			break;
		case 5:
			myuser.show(); break;
		case 6:
			myuser.signup(); break;
		}

	} while (menu!=0);

}