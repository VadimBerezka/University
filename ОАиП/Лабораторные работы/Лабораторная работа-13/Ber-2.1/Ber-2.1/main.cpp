#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    char str[100], s1[100];
    int n, k;

    cout << "Введите строку символов: "; // Dosomethingwithpassionornotatall
    cin >> str;
    cout << "Введите позицию n: "; // 2
    cin >> n;
    cout << "Введите длину подстроки k: "; // 9
    cin >> k;

    for (int i = n, j = 0; i < n + k; i++, j++) {
        s1[j] = str[i];
        if (i == n + k - 1) s1[++j] = '\0';
    }

    
    cout << "Полученная подстрока S1: " << s1 << endl;
    return 0;
}