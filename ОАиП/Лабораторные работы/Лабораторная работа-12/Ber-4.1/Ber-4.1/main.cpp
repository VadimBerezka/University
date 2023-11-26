#include <iostream> 
#include <iomanip>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, m, max;
	cin >> n >> m;
	bool t = false;
	int a[500];
	int b[500];
	for (int i = 0; i < n; i++) { // заполн€ем массив a числами с клавиатуры
		cin >> *(a + i);
	}
	for (int i = 0; i < m; i++) { // заполн€ем массив b числами с клавиатуры
		cin >> *(b + i);
	}
	max = *a; // присваиваем переменной max значение первого элемента массива a
	for (int i = 1; i < n; i++) { // находим максимальный элемент в массиве a
		if (*(a + i) > max) {
			max = *(a + i);
		}
	}
	for (int i = 0; i < m; i++) { // ищем максимальный элемент из массива a в массиве b
		if (*(b + i) == max) {
			cout << "Ќаибольший элемент массива a содержитс€ в массиве b" << endl;
			t = true;
			break;
		}
	}
	if (t == false) {
		cout << "Ќаибольший элемент массива a не содержитс€ в массиве b" << endl;
	}
}
