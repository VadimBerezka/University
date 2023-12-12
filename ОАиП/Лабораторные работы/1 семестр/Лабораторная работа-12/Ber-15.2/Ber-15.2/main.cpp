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
	int f[500];
	int d[500];
	for (int i = 0; i < n; i++) { // заполн€ем массив f числами с клавиатуры
		cin >> *(f + i);
	}
	for (int i = 0; i < m; i++) { // заполн€ем массив d числами с клавиатуры
		cin >> *(d + i);
	}
	max = *f; // присваиваем переменной max значение первого элемента массива f
	for (int i = 1; i < n; i++) { // находим максимальный элемент в массиве f
		if (*(f + i) > max) {
			max = *(f + i);
		}
	}
	for (int i = 0; i < m; i++) { // ищем максимальный элемент из массива f в массиве d
		if (*(d + i) == max) {
			cout << "Ќаибольший элемент массива f содержитс€ в массиве d" << endl;
			t = true;
			break;
		}
	}
	if (t == false) {
		cout << "Ќаибольший элемент массива f не содержитс€ в массиве d" << endl;
	}
}
