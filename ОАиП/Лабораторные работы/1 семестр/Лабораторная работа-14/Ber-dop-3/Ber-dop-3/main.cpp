#include <iostream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 4;
    double A[n][n];

    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = static_cast<double>(rand()) / 1000;
        }
    }
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }


    for (int i = 0; i < n; i++) {
        double maxElem = A[i][i];
        int maxRow = i;
        int maxCol = i;

        for (int j = i; j < n; j++) {
            for (int k = (j == i ? i + 1 : 0); k < n; k++) {
                if (A[j][k] > maxElem) {
                    maxElem = A[j][k];
                    maxRow = j;
                    maxCol = k;
                }
            }
        }       
        if (maxRow != i || maxCol != i) {
            swap(A[i][i], A[maxRow][maxCol]);
        }
    }

    cout << "Результирующая матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}