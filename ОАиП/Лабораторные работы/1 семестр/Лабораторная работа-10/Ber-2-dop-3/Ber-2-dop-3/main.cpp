#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    const int maxSize = 100;
    int size, diff = 1, maxDiff = 1;
    int arr[maxSize] = { 1, 1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 8 };
    cout << "������� ���������� ��������� �������: ";
    cin >> size;
    // �������� ����� for � �������� if, ������� ��������� ����� ����������� ����� ������ ������ ���������� ���������
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
    cout << "���������� ����� ������ ������ ���������� ���������: " << maxDiff;
    return 0;
}
