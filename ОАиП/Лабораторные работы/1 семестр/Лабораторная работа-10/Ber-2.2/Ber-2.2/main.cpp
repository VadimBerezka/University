#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    const int maxSize = 100;
    int k, arr[maxSize], min = 0, max = 99, n;
    cout << "¬ведите количество элементов массива: ";
    cin >> k;
    srand(time(NULL));

    for (int i = 0; i < k; i++) {
        arr[i] = (int)((double)rand() / (double)RAND_MAX * (max - min) + min);
        cout << arr[i] << " ";
    }

    cout << "\n¬ведите количество позиций дл€ сдвига: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int initial = arr[k - 1];
        for (int j = k - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = initial;
    }
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}