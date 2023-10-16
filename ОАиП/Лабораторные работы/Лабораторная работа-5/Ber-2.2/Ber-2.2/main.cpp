#include <iostream>
using namespace std;
int main() 
{
    setlocale(LC_CTYPE, "Russian");
    int n, m, k;
    cout << "¬ведите три целых числа: ";
    cin >> n >> m >> k;

    if (n % 2 != 0 || m % 2 != 0 || k % 2 != 0) {
       cout << "—реди заданных чисел есть нечЄтные числа." << endl;
    }
    else {
        cout << "—реди заданных чисел нет нечЄтных чисел." << endl;
    }

    return 0;
}
