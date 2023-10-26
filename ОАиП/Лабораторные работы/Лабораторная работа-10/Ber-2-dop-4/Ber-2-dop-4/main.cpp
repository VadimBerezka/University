// Подключение библиотек
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    // Добавление возможности вывода на русском языке
    setlocale(LC_CTYPE, "Russian");
    // Создание переменных
    const int maxSize = 100;
    int k, count = 0;
    int M[maxSize] = { 1, 1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 8 };
    cout << "Введите количество элементов массива: "; // Вывод
    cin >> k; // Ввод
    // Создание цикла for, который считает количество элементов различных элементов
    for (int i = 1; i < k; ++i) {
        if (M[i] != M[i - 1]) {
            count++;
        }
    }
    // Вывод результата
    cout << count;
    return 0;
}
