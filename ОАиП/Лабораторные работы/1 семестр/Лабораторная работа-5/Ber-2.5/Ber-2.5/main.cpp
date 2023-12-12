
#include <iostream>
using namespace std;
int main()
{

	setlocale(LC_CTYPE, "Russian");

	int a, b, c, r, s, t;
	cout << "Введите размеры коробки a: ";
	cin >> a;
	cout << "Введите размеры коробки b: ";
	cin >> b;
	cout << "Введите размеры коробки c: ";
	cin >> c;
	cout << "Введите размеры коробки r: ";
	cin >> r;
	cout << "Введите размеры коробки s: ";
	cin >> s;
	cout << "Введите размеры коробки t: ";
	cin >> t;
	// Оператор условия, проверяющий а меньше либо равно r и b меньше либо равно s и c меньше либо равно t
	if (a <= r && b <= s && c <= t)
		cout << "Можно";
	else
		cout << "Нельзя";

	return 0;
}
