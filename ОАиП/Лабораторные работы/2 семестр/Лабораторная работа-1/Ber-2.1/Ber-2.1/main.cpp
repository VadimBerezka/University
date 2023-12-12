#include <iostream>
using namespace std;

double function1(double);


double function2(double x) {
    return pow(cos(x), 3);
}

double method(double (*function)(double), double a, double b, double e) {
    while ((b - a) > e) {
            double c = (a + b) / 2;
            if (function(c) == 0) {
                return c;
            }
            else if (function(a) * function(c) < 0) {
                b = c;
            }
            else {
                a = c;
            }
    }
    return (a + b) / 2;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, e = 0.001;
    cout << "Введите a: ";
    cin >> a;
    cout << "\nВведите b: ";
    cin >> b;

    double root1 = method(function1, a, b, e);
    double root2 = method(function2, a, b, e);

    cout << "\nКорень первой функции: " << root1;
    cout << "\nКорень второй функции: " << root2;

    return 0;
}

double function1(double x) {
    return pow(x, 3) + x - 3;
}