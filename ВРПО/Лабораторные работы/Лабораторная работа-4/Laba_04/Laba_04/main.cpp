#include <iostream> 
#include <string> 
#include <windows.h> 
#include "one.h"
#include "two.h"
#include "three.h"
using namespace std;

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_CTYPE, "russian");
    int choice;
    while (true) {
        cout << "�������� ������� �������������:" << endl;
        cout << "������a �������� ����� � Windows-1251 �������� ����� ���������� �������� � ��������� � �������� ��������� (1) " << endl;
        cout << "������� �������� ����� � Windows-1251 �������� ����� �������� �������� � ��������� � �������� ��������� (2) " << endl;
        cout << "������� �������� ���������� ����� � ��� ���������������� �� ������� � Windows-1251 (3) " << endl;
        cout << "����� �� ��������� (4) " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            function1();
                break;
        case 2:
            function2();
                break;
        case 3:
            function3();
                break;
        case 4:
            return 0;

        default:
            cout << "������" << endl << endl;
        }
    }
    return 0;
}