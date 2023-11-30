#include <iostream>
using namespace std;

void addOne(float* A, int n) {
    if (A[0] != 0)
        for (int i = 0; i < n; i++)
            A[i] += 1;
}

void convertString(char* str, int n) {
    for (int i = 0; i < n; i++) {
        if ((str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я'))
            str[i] = toupper(str[i]);

        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            str[i] = '?';
    }
}



int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    cout << "Введите номер задания: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int n, m;
        cout << "Введите количество строк n: ";
        cin >> n;
        cout << "Введите количество столбцов m: ";
        cin >> m;

        float** A = new float* [n];
        for (int i = 0; i < n; i++) {
            A[i] = new float[m];
        }
        cout << "Введите элементы матрицы: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }


        for (int i = 0; i < n; i++) {
            addOne(A[i], m);
        }

        cout << "Измененный массив A:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++) {
            delete[] A[i];
        }
        delete[] A;

        break;
    }


    case 2: {
        char str[] = "Вадим Berezka";
        int length = sizeof(str);

        convertString(str, length);
        cout << str << endl;
        break;
    }


    default:
        cout << "Неправильный ввод";
        break;
}
    return 0;
}