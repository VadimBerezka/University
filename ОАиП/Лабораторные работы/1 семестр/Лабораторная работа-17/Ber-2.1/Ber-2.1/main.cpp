#include <iostream>
using namespace std;

void countnum(int* arr, int size, int k, float&  percent) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == k) {
            count++;
        }
    }
   percent = static_cast<float>(count) / static_cast<float>(size) * 100;
   // percent = (float)count / size * 100;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "������� ������ �������: ";
    cin >> size;

    int* arr = new int[size];

    cout << "������� �������� �������: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];


    int k;
    cout << "������� �����: ";
    cin >> k;

    float percent;
    countnum(arr, size, k, percent);

    cout << "�����: " << k << " \n���������� ���������� ����� � �������:" << percent << "%\n";

        delete[] arr;

    return 0;
}