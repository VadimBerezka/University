#include <iostream> 
#include <iomanip>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, m, z, s = 0, s2 = 0;
	cin >> n >> m; // размеры массивов
	cin >> z; // считываем число-ограничитель
	int a[500];
	int b[500];
	for (int i = 0; i < n; i++) { // заполняем массив a числами с клавиатуры
		cin >> *(a + i);
	}
	for (int i = 0; i < m; i++) { // заполняем массив b числами с клавиатуры
		cin >> *(b + i);
	}
	for (int i = 0; i < n; i++) { // проходим по массиву a и считаем кол-во символов меньших z
		if (*(a + i) < z) {
			s += 1;
		}
	}
