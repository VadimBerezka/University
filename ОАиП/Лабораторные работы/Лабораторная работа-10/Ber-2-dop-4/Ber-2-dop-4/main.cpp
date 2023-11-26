#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    const int maxSize = 100;
    int k, count = 0;
    int M[maxSize] = { 1, 1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 8 };
    cout << "¬ведите количество элементов массива: ";
    cin >> k;
    for (int i = 1; i < k; ++i) {
        if (M[i] != M[i - 1]) {
            count++;
        }
    }
    cout << count;
    return 0;
}
