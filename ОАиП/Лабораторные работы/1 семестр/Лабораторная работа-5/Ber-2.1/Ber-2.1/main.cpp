#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int num1, num2, num3, sum;
	cout << "Введите первое число: ";
	cin >> num1;
	cout << "Введите второе число: ";
	cin >> num2;
	cout << "Введите третье число: ";
	cin >> num3;
	// Тернарный оператор условия с проверкой каждого числа (делится ли каждое число на 5 без остатка)
	sum = ((num1 % 5 == 0) ? num1 : 0) + ((num2 % 5 == 0) ? num2 : 0) + ((num3 % 5 == 0) ? num3 : 0);
	cout << "Сумма: ";
	// Тернарный оператор условия с проверкой равна ли сумма нулю
	(sum != 0) ? cout << sum : cout << "Error";
	return 0;
}
