#pragma once
#include <iostream> 
#include <string> 
#include <windows.h>

using namespace std;
void function3() {
    char num;
    for (int i = 1; i < 3; i++) {
        cout << "������� �����: ";
        cin >> num;
        if (num >= 0x30 && num <= 0x39) {
            cout << "��� �������, ���������������� ��������� �����: " << (int)num << endl << endl;
        }
        else {
            cout << "������ " << endl << endl;
        }
    }
}