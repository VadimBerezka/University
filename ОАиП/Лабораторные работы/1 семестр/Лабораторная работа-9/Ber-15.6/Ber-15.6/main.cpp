#include <iostream> 
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    double e = 0.0001, a = 2, b = 7, x = (a + b) / 2;

    while (abs(a - b) > 2 * e) {
        x = (a + b) / 2;
        cout << x << endl;
        if ((sin(x) + 2 + x) * (sin(a) + 2 + a) <= 0) {
            b = x;
        }
        else {
            a = x;
        }
    }
    cout << "x=" << x;
    return 0;
}