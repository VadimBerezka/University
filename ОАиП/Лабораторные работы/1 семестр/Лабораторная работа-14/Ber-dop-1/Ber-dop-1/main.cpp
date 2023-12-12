#include <iostream>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 2;
    const int size = 2 * n;
    int A[size][size];

    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % 21 - 10;
        }
    }

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }

    int res[size][size];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    res[i * n + k][j * n + l] = A[k][l];
                }
            }
        }
    }

    cout << "Полученная матрица:" << endl;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
