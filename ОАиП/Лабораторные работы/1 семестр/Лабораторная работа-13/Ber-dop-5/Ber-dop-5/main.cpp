#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    string str1, str2, FIND;
    int count_s = 0, pos, ind = 0, min_word;
    cout << "Введите строку S1:"; getline(cin, str1);//при помощи функции getline мы можем считать строку вместе с пробелами
    cout << "Введите строку S2:"; getline(cin, str2);
    min_word = str1.size();
    str1.insert(str1.size(), " ");//добавляем в конце пробел для возможности обработки последнего 
    str2.insert(str2.size(), " ");//добавляем в конце пробел для возможности обработки последнего слова
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == ' ') {//проверяем есть ли текущее слово в другой строке
            FIND = str1.substr(i - count_s, count_s);//с помощью subtract извлекаем текущее слово
            pos = str2.find(FIND);//смотрим есть ли оно в строке 2
            if (pos == 0) {//если слово первое во второй строке,то ищем пробел только после самого слова
                if (str2[pos + count_s] == ' ') { count_s = 0; }//проверяем явлется ли текущее слово отдельным словом,а не частью другого
                else {
                    if (min_word > count_s) {//смотрим является ли это слово наименьшим и если так,то записываем его размер и индекс
                        min_word = count_s;
                        ind = i - count_s;
                    };
                    count_s = 0;
                }
            }

            if (pos > 0) {//ищем пробелы до и после слова
                if (str2[pos - 1] == ' ' and str2[pos + count_s] == ' ') { count_s = 0; }
                else {
                    if (min_word > count_s) {//смотрим является ли это слово наименьшим и если так,то записываем его размер и индекс
                        min_word = count_s;
                        ind = i - count_s;
                    };
                    count_s = 0;
                }
            }
            if (pos < 0) {
                if (min_word > count_s) {//смотрим является ли это слово наименьшим и если так,то записываем его размер и индекс
                    min_word = count_s;
                    ind = i - count_s;
                };
                count_s = 0;
            }

        }
        else { count_s++; }

    }
    cout << str1.substr(ind, min_word);
    return 0;
}
