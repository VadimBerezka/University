#include <iostream>
using namespace std;

void convertString(char* str, int n) {
    for (int i = 0; i < n; i++) {
        if ((str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я')) {
            str[i] = toupper(str[i]);
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] = '?';
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    char str[] = "Вадим Berezka";
    int length = sizeof(str);

    convertString(str, length);

    cout << str << endl;

    return 0;
}