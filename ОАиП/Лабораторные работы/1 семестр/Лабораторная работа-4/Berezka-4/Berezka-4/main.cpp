#include <iostream>
#include <iomanip>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char b, space; space = ' ';

	cout << "Введите символ для заполнения круга=";
	cin >> b;

	cout << setw(48) << setfill(space) << ' ' << setw(4) << setfill(b) << b << endl;
	cout << setw(45) << setfill(space) << ' ' << setw(10) << setfill(b) << b << endl;
	cout << setw(44) << setfill(space) << ' ' << setw(12) << setfill(b) << b << endl;
	cout << setw(44) << setfill(space) << ' ' << setw(12) << setfill(b) << b << endl;
	cout << setw(45) << setfill(space) << ' ' << setw(10) << setfill(b) << b << endl;
	cout << setw(48) << setfill(space) << ' ' << setw(4) << setfill(b) << b << endl;
}