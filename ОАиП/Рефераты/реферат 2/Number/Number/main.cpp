#include <iostream>  // ����������� ���������� 
using namespace std; // ������������� ������������ ���� std


int main() {
    setlocale(LC_CTYPE, "Russian"); // ��������� ������ ��� ������ ��������� �� ������� �����
    srand(time(0)); // ������������� ���������� ��������� �����

    int randomNum = rand() % 401 + 100; // ��������� ���������� ����� � ��������� �� 100 �� 500
    int x; // ���������� � ������������� ���������� x

    cout << "���������� ������� �����, ������� ������� ���������! (�� 100 �� 500)" << endl; // ����� ��������� "��������� �������� �����, ������� ������� ���������! (�� 100 �� 500)"

    while (true) { // ����������� ���� ��������� ��������� ���� � �� �� ������������������ ��������, ���� ����������� ������� �������
        cout << "������� �����: "; // ����� ��������� "������� �����: "
        cin >> x; // ���������� �������� ��������� � ���������� 
        if (x == randomNum) { // ���� ��������� ����� ����� ����������� �����
            cout << "� �������! x = " << x << endl; // ����� �������� ���������� x c ���������� "� �������! x =  "
            break; // ����� �� �����
        }
        else if (x < randomNum) { // ���� ��������� ����� ������ ����������� �����
            cout << "x > " << x << endl; // ����� �������� ���������� x c ���������� "x > "
        }
        else if (x > randomNum) { // ���� ��������� ����� ������ ����������� �����
            cout << "x < " << x << endl; // ����� �������� ���������� x c ���������� "x < "
        }
    }
    return 0; // ������� �������� 0, ������������� �������� ���������� ���������
} 