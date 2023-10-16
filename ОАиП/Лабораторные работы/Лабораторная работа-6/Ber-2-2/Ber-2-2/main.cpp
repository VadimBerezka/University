#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    double y, z, a, b = 8.5, n = 2, i = 1;
    int g = 10;
    int p = -3;
    a = 2 * pow(g, p);
    // Создание цикла while
    while (i <= 3) {
        y = sqrt(i * b - b * b * a);
        z = y * tan(n / 4) - exp(1 + b);
        cout << y << endl;
        cout << z << endl;
        i += 0.5;
    }

    return 0;
}