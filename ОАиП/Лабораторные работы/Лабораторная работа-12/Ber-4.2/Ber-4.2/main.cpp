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
	int z[500];
	for (int i = 0; i < n; i++) { // заполняем массив a числами с клавиатуры
		cin >> *(z + i);
	}
	for (int i = 0; i < n - 1; i++) { // проходим циклом по элементам массива, начиная с первого
		for (int j = i + 1; j < n; j++) { // проходим циклом по элементам массива, начиная со второго
			if (*(z + i) == *(z + j)) { // сравниваем их
				for (int k = j; k < n; k++) { // если они равны, то удаляем повторяющийся элмент из массива
					*(z + k) = *(z + k + 1);
				}
				n--;
				j--;
			}
		}
	}
	cout << "Количество различных элементов в массиве z = " << n << endl;
}
