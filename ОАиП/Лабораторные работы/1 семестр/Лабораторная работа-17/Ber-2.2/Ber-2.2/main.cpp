#include <iostream>
using namespace std;

int countRows(int** A, int n, int m, int count) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 0) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Введите количество строк n: ";
    cin >> n;
    cout << "Введите количество столбцов m: ";
    cin >> m;

    int** A = new int* [n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];

    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    int kol = 0;
    kol = countRows(A, n, m, kol);
    cout << "Кол-во строк содержащих 0: " << kol << endl;

    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
