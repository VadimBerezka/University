#include <iostream>
#include <iomanip>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char b, space; space = ' ';

	cout << "Введите символ для заполнения елочки=";
	cin >> b;

	cout << setw(35) << setfill(space) << ' ' << setw(1) << setfill(b) << b << endl;
	cout << setw(33) << setfill(space) << ' ' << setw(4) << setfill(b) << b << endl;
	cout << setw(31) << setfill(space) << ' ' << setw(8) << setfill(b) << b << endl;
	cout << setw(29) << setfill(space) << ' ' << setw(12) << setfill(b) << b << endl;
	cout << setw(27) << setfill(space) << ' ' << setw(16) << setfill(b) << b << endl;
	cout << setw(25) << setfill(space) << ' ' << setw(20) << setfill(b) << b << endl;
	cout << setw(35) << setfill(space) << ' ' << setw(1) << setfill(b) << b << endl;
	cout << setw(33) << setfill(space) << ' ' << setw(4) << setfill(b) << b << endl;
	cout << setw(31) << setfill(space) << ' ' << setw(8) << setfill(b) << b << endl;
	cout << setw(29) << setfill(space) << ' ' << setw(12) << setfill(b) << b << endl;
	cout << setw(27) << setfill(space) << ' ' << setw(16) << setfill(b) << b << endl;
	cout << setw(25) << setfill(space) << ' ' << setw(20) << setfill(b) << b << endl;
	cout << setw(35) << setfill(space) << ' ' << setw(1) << setfill(b) << b << endl;
	cout << setw(33) << setfill(space) << ' ' << setw(4) << setfill(b) << b << endl;
	cout << setw(31) << setfill(space) << ' ' << setw(8) << setfill(b) << b << endl;
	cout << setw(29) << setfill(space) << ' ' << setw(12) << setfill(b) << b << endl;
	cout << setw(27) << setfill(space) << ' ' << setw(16) << setfill(b) << b << endl;
	cout << setw(25) << setfill(space) << ' ' << setw(20) << setfill(b) << b << endl;
	cout << setw(34) << setfill(space) << ' ' << setw(3) << setfill(b) << b << endl;
	cout << setw(34) << setfill(space) << ' ' << setw(3) << setfill(b) << b << endl;
}