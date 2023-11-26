#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    const int maxSize = 100;
    int size, diff = 1, maxDiff = 1;
    int arr[maxSize] = { 1, 1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 8 };
    cout << "Введите количество элементов массива: ";
    cin >> size;
    // Создание цикла for с условием if, который выполняет поиск наибольшего числа подряд идущих одинаковых элементов
    for (int i = 1; i < size; ++i) {
        if (arr[i] == arr[i - 1]) {
            diff++;
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
        else {
            diff = 1;
        }
    }
    cout << "Наибольшее число подряд идущих одинаковых элементов: " << maxDiff;
    return 0;
}
