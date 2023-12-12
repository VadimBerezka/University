#include <iostream> 
#include <iomanip>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, k;
	cin >> n;
	bool t = false;
	int a[500];
	for (int i = 0; i < n; i++) { // заполняем массив a числами с клавиатуры
		cin >> *(a + i);
	}
	for (int i = 0; i < n - 1; i++) { // проходим по элементам массива
		if (*(a + i) < 0) { // если элемент меньше 0
			for (int j = i + 1; j < n; j++) { // проходим по элементам массива, начиная со следующего, и ищем положительный элемент
				if (*(a + j) > 0) { // если находим, то меняем их местами
					k = *(a + j);
					*(a + j) = *(a + i);
					*(a + i) = k;
					t = true;
					break;
				}
			}
			if (t == true) {
				t = false;
			}
			else { // если не нашли ни одного, значит все остальные отрицательны и заканчиваем цикл
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) { // выводим массив через пробел
		cout << *(a + i) << " ";
	}
}
