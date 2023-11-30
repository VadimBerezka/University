#include <iostream> 
#include <string> 
#include <windows.h> 
using namespace std;

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_CTYPE, "russian");
    int choice;
    unsigned char input;
    char num;
    int to_up, to_low, razn;
    while (true) {
        cout << "Выберите вариант использования:" << endl;
        cout << "Разницa значений кодов в Windows-1251 заданной буквы латинского алфавита в прописном и строчном написании (1) " << endl;
        cout << "Разница значений кодов в Windows-1251 заданной буквы русского алфавита в прописном и строчном написании (2) " << endl;
        cout << "Перевод заданной десятичной цифры в код соответствующего ей символа в Windows-1251 (3) " << endl;
        cout << "Выход из программы (4) " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
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
            break;
        case 2:
            cout << "Введите символ: ";

            cin >> input;
            if ((input) >= 0xC0 && (input) <= 0xFF) {

               to_up = (int)toupper(input);
               to_low = (int)tolower(input);
               razn = to_low - to_up;

                cout << "Разница значений кодов в Windows-1251 заданной буквы русского алфавита в прописном и строчном написании: " << razn << endl << endl;
            
            }
            else {
                cout << "Ошибка" << endl << endl;
            }
            break;
        case 3:
            cout << "Введите цифру: ";
            cin >> num;
            if (num >= 0x30 && num <= 0x39) {
                cout << "Код символа, соответствующего введенной цифре: " << (int)num << endl << endl;
            }
            else
                cout << "Ошибка " << endl << endl;

            break;

        case 4:
            return 0;

        default:
            cout << "Ошибка" << endl << endl;
        }
    }
    return 0;
}