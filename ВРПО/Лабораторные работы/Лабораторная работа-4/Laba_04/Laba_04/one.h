#pragma once
#include <iostream> 
#include <string> 
#include <windows.h>
using namespace std;

void function1() {
    unsigned char input;
    int razn, to_up, to_low;
    for (int i = 1; i < 3; i++) {
        cout << "Введите символ: ";
        cin >> input;
        if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
            to_up = (int)toupper(input);
            to_low = (int)tolower(input);
            razn = to_low - to_up;
            cout << "Разницa значений кодов в Windows-1251 заданной буквы латинского алфавита в прописном и строчном написании: " << razn << endl << endl;
        }

        else {
            cout << "Ошибка" << endl << endl;
        }
    }
}