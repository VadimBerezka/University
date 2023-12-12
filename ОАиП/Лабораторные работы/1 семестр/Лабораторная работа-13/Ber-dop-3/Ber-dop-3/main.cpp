#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    string str1, str2, FIND;
    int count_s = 0, pos;
    cout << "Введите строку S1:"; getline(cin, str1);//при помощи функции getline мы можем считать строку вместе с пробелами
    str1.insert(str1.size(), " ");
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == ' ') {//проверяем есть ли текущее слово в другой строке
            FIND = str1.substr(i - count_s, count_s);//с помощью subtract извлекаем текущее слово
            pos = str1.find(FIND);//смотрим есть ли оно в строке 2
            if (pos < i - count_s) {//если выводится что-то больше -1,то значит слово есть
                str1.erase(i - count_s, count_s + 1);//удаляем его
                i -= count_s;//возвращаемся на то место в строке, где находились до обработки нечетного слова
                count_s = 1;
            }
            else {
                count_s = 0; 
            }
        }
        else { 
            count_s++; 
        }

    }
    cout << str1;
    return 0;
}
