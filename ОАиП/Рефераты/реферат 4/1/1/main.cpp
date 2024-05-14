#include <set>
#include <iostream>
#include <locale.h>
#include <chrono>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // ��������� ��������� ����� ����� � ��������� ��������
    set<int> mySet;
    for (int i = 0; i < 1000000; ++i) {
        mySet.insert(i);
    }

    // �������� ����� ������ ��������
    auto start = chrono::high_resolution_clock::now();

    // ���� ������� � ���������
    mySet.find(500000);

    // �������� ����� ��������� ��������
    auto end = chrono::high_resolution_clock::now();

    // ��������� � ������� ����������� �����
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "����� ���������� �������� ������: " << duration.count() << " ��" << endl;

    return 0;
}
