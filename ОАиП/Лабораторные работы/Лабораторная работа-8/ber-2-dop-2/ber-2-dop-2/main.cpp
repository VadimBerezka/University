#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int size;
    int num = 0;

    cout << "������� ������ �������: ";
    cin >> size;
    double* arr = new double[size];

    cout << "������� ����� �������" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            num = i;
        }
    }
    cout << "����� ���������� �������������� ��������: " << num+1;
    return 0;
}