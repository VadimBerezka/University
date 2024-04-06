#include <iostream>
#include <locale.h>
#include "stack.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int choice, value;
    const char* filename = "stack.txt";
    while (true) {
        cout << "1. �������� ������� � ����" << endl;
        cout << "2. ������� ������� �� �����" << endl;
        cout << "3. �������� ����" << endl;
        cout << "4. ������� ������ ������������� �������" << endl;
        cout << "5. ���������� ����" << endl;
        cout << "6. ��������� ���� � ����" << endl;
        cout << "7. ��������� ���� �� �����" << endl;
        cout << "8. �����" << endl;
        cout << "������� ��� �����: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "������� ��������: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            clear();
            break;
        case 4:
            remove3();
            break;
        case 5:
            display();
            break;
        case 6:
            saveToFile(filename);
            break;
        case 7:
            loadFromFile(filename);
            break;
        case 8:
            return 0;
        default:
            cout << "�������� �����" << endl;
        }
    }
    return 0;
}