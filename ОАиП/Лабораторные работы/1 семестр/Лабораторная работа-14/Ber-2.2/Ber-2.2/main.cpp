#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int const  n = 2;
    int const m = 2;
    int A[n][m];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = rand() % 10;
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
  
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        for (int j = 0; j < m; j++)
            cout << "A[" << i << "," << j << "] =" << A[i][j] << "\t";
    }

    int kol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //if (A[i][j] != A[i][j + 1]) {
            if (*(*(A + i) + j) != *(*(A + i) + j + 1)) {
                kol++;
            }
        }
            
    }
    cout << "Количество уникальных элементов: " << kol << endl;


    return 0;
}