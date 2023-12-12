#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");

    const int maxSize = 100;
    int size, arr[maxSize], min = 0, max = 99, count = 0;
    cout << "¬ведите количество элементов массива: "; 
    cin >> size;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = (int)((double)rand() / (double)RAND_MAX * (max - min) + min);
    }
    for (int i = 1; i < size; ++i) {
        if (arr[i - 1] == arr[i]) {
            count++;
        }
    }
    cout << count;
    return 0;
}
