#include <iostream>
using namespace std;
int main() {
    setlocale(LC_CTYPE, "Russian");
    double e = 0.0001, a = 1, b = 3, x = (a + b) / 2;
    while (abs(a - b) > 2 * e) {
        x = (a + b) / 2;
        cout << x << endl;
        if (((pow(x, 3) + x - 3) * (pow(a, 3) + a - 3)) <= 0) {
            b = x;
        }
        else {
            a = x;
        }
    }
    cout << "Результат: " << x;
    return 0;
}
