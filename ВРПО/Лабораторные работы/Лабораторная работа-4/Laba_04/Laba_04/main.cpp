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
        cout << "Выберите вариант использования:" << endl;
        cout << "Разницa значений кодов в Windows-1251 заданной буквы латинского алфавита в прописном и строчном написании (1) " << endl;
        cout << "Разница значений кодов в Windows-1251 заданной буквы русского алфавита в прописном и строчном написании (2) " << endl;
        cout << "Перевод заданной десятичной цифры в код соответствующего ей символа в Windows-1251 (3) " << endl;
        cout << "Выход из программы (4) " << endl;
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
            cout << "Ошибка" << endl << endl;
        }
    }
    return 0;
}