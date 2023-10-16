#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_CTYPE, "Russian");

    double y, z, a, b = 8.5, n = 2, i[3];
    int g = 10;
    int p = -3;
    a = 2 * pow(g, p);
    // Создание цикла for
    for (int j = 0; j < 3; j++) {
        cout << "Введите значение i: ";
        cin >> i[j];
        y = sqrt(i[j] * b - b * b * a);
        z = y * tan(n / 4) - exp(1 + b);

        cout << y << endl;
        cout << z << endl;
    }

    return 0;
}
