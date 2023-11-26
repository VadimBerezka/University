#include <iostream> 
#include <iomanip>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cin >> n;
	bool t = false;
	int a[500];
	for (int i = 0; i < n; i++) { // заполняем массив числами с клавиатуры
		cin >> *(a + i);
	}
	for (int j = 1; j < 2000000000; j++) { // создаём цикл перебора натуральных чисел
		for (int i = 0; i < n; i++) { // влаживаем цикл прохода по элементам массива
			if (*(a + i) == j) { // проверяем их на равенство
				t = true; // если находим, то прерываем внутреннний цикл
				break;
			}
		}
		if (t == false) { //если не находим, то выводим это число и прерываем внешний цикл
			cout << j;
			break;
		}
		else { // иначе продолжаем перебор
			t = false;
		}
	}
}
