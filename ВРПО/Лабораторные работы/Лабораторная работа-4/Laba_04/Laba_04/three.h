#pragma once
#include <iostream> 
#include <string> 
#include <windows.h>

using namespace std;
void function3() {
    char num;
    for (int i = 1; i < 3; i++) {
        cout << "Введите цифру: ";
        cin >> num;
        if (num >= 0x30 && num <= 0x39) {
            cout << "Код символа, соответствующего введенной цифре: " << (int)num << endl << endl;
        }
        else {
            cout << "Ошибка " << endl << endl;
        }
    }
}