#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    double a, i = 2.0, b = 8.5, n;
    double y, z;

    int g = 10;
    int p = -3;
    a = 2e-3;

    while (i <= 3) {
        for (int t = 1; t < 5; t++) {
            cout << "¬ведите n" << endl;
            cin >> n;
            y = sqrt(t * b - b * b * a);
            z = y * tan(n / 4) - exp(1 + b);
            cout << "y = " << y << endl;
            cout << "z = " << z << endl;
            cout << endl;
        }
        i = i + 0.5;
    }
    return 0;
}