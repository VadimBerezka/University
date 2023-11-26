#include <iostream> 
using namespace std;

int main() {
    double a = 2, b = 3, e = 0.0001, x;
    x = (a + b) / 2;
    if ((exp(x) - 3 - 1 / x) * (exp(a) - 3 - 1 / a) <= 0) {
        b = x;
    }
    else {
        a = x;
    }
    while (true) {
        if (abs(a - b) > 2 * e) {
            x = (a + b) / 2;
            cout << x << endl;
            if ((exp(x) - 3 - 1 / x) * (exp(x) - 3 - 1 / x) <= 0) {
                b = x;
            }
            else {
                a = x;
            }
        }
        else {
            break;
        }
    }
    cout << "x=" << x;
}