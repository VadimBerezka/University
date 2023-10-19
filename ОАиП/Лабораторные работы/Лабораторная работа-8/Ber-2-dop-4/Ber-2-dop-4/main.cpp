#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int size, num = 0;
	bool sign = true;
	cout << "Введите размер массива: ";
	cin >> size;
	// Создание динамического массива
	int* n{ new int[size] };
	cout << "Введите элементы массива: ";
	for (int i = 0; i < size; i++) {
		cin >> n[i];
		// Создание условия if, которое проверяет отрицателен ли прошлый элемент и положителен ли текущий и наоборот
		if (!sign && n[i] > 0)
		{
			sign;
			num++;
		}
		else if (sign && n[i] < 0)
		{
			!sign;
			num++;
		}
	}
	cout << "Количество чередований: " << num;
	return 0;
}
