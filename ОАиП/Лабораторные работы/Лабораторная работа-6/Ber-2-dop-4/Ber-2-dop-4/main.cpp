#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k, n;
	cout << "Введите число k: ";
	cin >> k;
	for (int i = 0; i < 1000; i++)
	{
		n = pow(2, i);
		// Проверка равняется ли значение i + 1 k, еcли да, то цикл прерывается
		if (i + 1 == k) break;
	}
	cout << n << endl;
	return 0;
}