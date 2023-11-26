#include <iostream>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите порядок латинского квадрата : ";
    cin >> n;

    int** latinSquare = new int* [n];
    for (int i = 0; i < n; i++) {
        latinSquare[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            latinSquare[i][j] = (i + j) % n + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << latinSquare[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}
