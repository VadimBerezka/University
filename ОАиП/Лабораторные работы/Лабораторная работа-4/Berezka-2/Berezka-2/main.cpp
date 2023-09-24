#include <iostream>
#include <iomanip>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;

	char b, space; 
	space = ' ';

	cout << "Введите символ для заполнения шестиугольника=";	
	cin >> b;

	cout << setw(50) << setfill(space) << ' ' << setw(20) << setfill(b) << b << endl;
	cout << setw(49) << setfill(space) << ' ' << setw(22) << setfill(b) << b << endl;
	cout << setw(48) << setfill(space) << ' ' << setw(24) << setfill(b) << b << endl;
	cout << setw(47) << setfill(space) << ' ' << setw(26) << setfill(b) << b << endl;
	cout << setw(46) << setfill(space) << ' ' << setw(28) << setfill(b) << b << endl;
	cout << setw(45) << setfill(space) << ' ' << setw(30) << setfill(b) << b << endl;
	cout << setw(46) << setfill(space) << ' ' << setw(28) << setfill(b) << b << endl;
	cout << setw(47) << setfill(space) << ' ' << setw(26) << setfill(b) << b << endl;
	cout << setw(48) << setfill(space) << ' ' << setw(24) << setfill(b) << b << endl;
	cout << setw(49) << setfill(space) << ' ' << setw(22) << setfill(b) << b << endl;
	cout << setw(50) << setfill(space) << ' ' << setw(20) << setfill(b) << b << endl;

}