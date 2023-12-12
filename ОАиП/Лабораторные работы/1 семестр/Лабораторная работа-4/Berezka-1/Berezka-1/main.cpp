#include <iostream>
#include <iomanip>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;

	char b, space; space = ' ';

	cout << "Введите символ для заполнения полукруга=";
	cin >> b;

	
	cout << setw(25) << setfill(space) << ' ' << setw(42) << setfill(b) << b << endl;
	cout << setw(26) << setfill(space) << ' ' << setw(40) << setfill(b) << b << endl;
	cout << setw(27) << setfill(space) << ' ' << setw(38) << setfill(b) << b << endl;
	cout << setw(27) << setfill(space) << ' ' << setw(38) << setfill(b) << b << endl;
	cout << setw(27) << setfill(space) << ' ' << setw(38) << setfill(b) << b << endl;
	cout << setw(29) << setfill(space) << ' ' << setw(34) << setfill(b) << b << endl;
	cout << setw(29) << setfill(space) << ' ' << setw(34) << setfill(b) << b << endl;
	cout << setw(31) << setfill(space) << ' ' << setw(30) << setfill(b) << b << endl;
	cout << setw(33) << setfill(space) << ' ' << setw(26) << setfill(b) << b << endl;
	cout << setw(37) << setfill(space) << ' ' << setw(18) << setfill(b) << b << endl;
	cout << setw(41) << setfill(space) << ' ' << setw(10) << setfill(b) << b << endl;
	cout << setw(45) << setfill(space) << ' ' << setw(4) << setfill(b) << b << endl;
}