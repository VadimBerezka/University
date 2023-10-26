// Подключение библиотек
#include <iostream>
using namespace std;
int main()
{
    // Добавление возможности вывода на русском языке
    setlocale(LC_CTYPE, "Russian");
    // Создание переменных
    const int maxSize = 100;
    int k, arr[maxSize], min = 0, max = 99, n;
    cout << "Введите количество элементов массива: "; // Вывод
    cin >> k; // Ввод
    srand(time(NULL));
    // Создание цикла for для заполнения массива случайными числами
    for (int i = 0; i < k; i++) {
        arr[i] = (int)((double)rand() / (double)RAND_MAX * (max - min) + min);
        cout << arr[i] << " ";
    }
    cout << "Введите количество позиций для сдвига: "; // Вывод
    cin >> n; // Ввод
    // Создание цикла for, в котором происходит смещение на n элементов влево
    for (int i = 0; i < n; i++) {
        int initial = arr[0];
        for (int j = 0; j < k - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[k - 1] = initial;
    }
    // Вывод результата
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
