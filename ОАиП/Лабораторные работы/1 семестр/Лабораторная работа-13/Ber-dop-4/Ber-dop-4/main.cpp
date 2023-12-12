#include <iostream>
#include <string>//данная директива нужна для использовния типа данных string


using namespace std;

string reverse(string str) {//данная функция возвращает введенную строку в перевернутом виде
    int len = str.length();
    int n = len - 1;//т.к. в конце строки всегда есть '\0',то его  не учитываем в смене
    int i = 0;
    while (i <= n) {
        swap(str[i], str[n]);//используем функцию swap для смены значений каждого индекса
        n = n - 1;
        i = i + 1;
    }
    return str;
}


int main() {
    system("color 70");
    setlocale(LC_CTYPE, "Russian");

    string str, rev;//используем массив символов для хранения информации и возможности обращаться к нему через указатели 
    int max_g = 0, count_s = 0, count_p = 1, size;//начинаем счёт с 1,чтобы учитывать первый элемент,стоящий в группе
    cout << "Введите строку S:";
    getline(cin, str);
    str.insert(str.size(), " ");//добовляем в конце пробел для возможности обработки последнего слова
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' and count_p % 2 != 0) {//если слово нечетное,то мы его удаляем
            str.erase(i - count_s, count_s);
            count_p == 1 ? str.erase(0, 1) : str.erase(0, 0);//после удаления первого слова удаляем еще и пробел между ним и вторым словом
            i -= count_s;//возрващаемся на то место в строке,где находились до обработки нечетного слова
            count_s = 0;
            count_p++;
        }
        else if (str[i] == ' ' and count_p % 2 == 0) {//если слово четное,то переворачиваем его
            count_p++;
            count_p > 3 ? count_s -= 1 : count_s -= 0;//после второго четного слова нужно не учитывать стоящий перед ним пробел
            rev = str.substr(i - count_s, count_s);//извлекаем необходимое слово из строки
            rev = reverse(rev);//переворачиваем его с помощью функции reverse 
            str.erase(i - count_s, count_s);//удаляем старое слово
            str.insert(i - count_s, rev);//и вставляем новое
            count_s = 0;
        }
        count_s++;
    }
    cout << str;
    return 0;
}
