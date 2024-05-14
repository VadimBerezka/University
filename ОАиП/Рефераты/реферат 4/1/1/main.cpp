#include <set>
#include <iostream>
#include <locale.h>
#include <chrono>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Объявляем множество целых чисел и добавляем элементы
    set<int> mySet;
    for (int i = 0; i < 1000000; ++i) {
        mySet.insert(i);
    }

    // Засекаем время начала операции
    auto start = chrono::high_resolution_clock::now();

    // Ищем элемент в множестве
    mySet.find(500000);

    // Засекаем время окончания операции
    auto end = chrono::high_resolution_clock::now();

    // Вычисляем и выводим затраченное время
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Время выполнения операции поиска: " << duration.count() << " нс" << endl;

    return 0;
}
