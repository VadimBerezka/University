#include <iostream>
using namespace std;
int main() {

    double a = 2, b = 3, n = 200, h = (b - a) / n, x = a, s = 0;
    while (true) {
        if (x > (b - h)) {
            break;
        }
        else {
            s = s + h * ((exp(x) - 1 / x) + (exp(x + h) - 1 / (x + h))) / 2;
            x = x + h;
        }
    }
    cout << "s=" << s;
}