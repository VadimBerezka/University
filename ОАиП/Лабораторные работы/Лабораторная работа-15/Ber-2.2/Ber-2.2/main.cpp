#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int rows, cols;
    cout << "Введите кол-во строк ";
    cin >> rows;
    cout << "Введите кол-во столбцов ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int maxRow = 0, maxCol = 0, maxElement = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    for (int j = 0; j < cols; j++) {
        swap(matrix[0][j], matrix[maxRow][j]);
    }

    for (int i = 0; i < rows; i++) {
        swap(matrix[i][0], matrix[i][maxCol]);
    }

    cout << "Новая матрица:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}