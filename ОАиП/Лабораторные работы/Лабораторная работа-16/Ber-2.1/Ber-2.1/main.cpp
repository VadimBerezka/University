//#include <iostream>
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    int rows, cols;
//    cout << "Введите кол-во строк: ";
//    cin >> rows;
//    cout << "Введите кол-во столбцов: ";
//    cin >> cols;
//
//    int** A = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        A[i] = new int[cols];
//    }
//
//    cout << "Введите элементы матрицы: " << endl;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cin >> A[i][j];
//        }
//    }
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << A[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    if (A[0][0] != 0) {
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                A[i][j] += 1;
//            }
//        }
//    }
//
//
//    cout << "Новая матрица:" << endl;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << A[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//
//
//
//    for (int i = 0; i < rows; i++) {
//    delete[] A[i];
//    }
//
//    delete[] A;
//
//    return 0;
//}
#include <iostream>
using namespace std;

void addOneToRow(float* A, int n) {
    if (A[0] != 0) {
        for (int i = 0; i < n; i++) {
                A[i] += 1;

            }
        }
    }

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Введите количество строк n: ";
    cin >> n;
    cout << "Введите количество столбцов m: ";
    cin >> m;


    float** A = new float* [n];
    for (int i = 0; i < n; i++)
        A[i] = new float[m];


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


    for (int i = 0; i < n; i++) {
            addOneToRow(A[i], m);
    }


    cout << "Измененный массив A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
   

    for (int i = 0; i < n; i++)
        delete[] A[i];

    delete[] A;

    return 0;
}