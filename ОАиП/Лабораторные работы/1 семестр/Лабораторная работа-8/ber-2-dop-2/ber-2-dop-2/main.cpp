#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int size;
    int num = 0;

    cout << "Введите размер массива: ";
    cin >> size;
    double* arr = new double[size];

    cout << "Введите числа массива" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            num = i;
        }
    }
    cout << "Номер последнего отрицательного элемента: " << num+1;
    return 0;
}