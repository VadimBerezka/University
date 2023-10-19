#include <iostream>
using namespace std;
int main() {

    double a = 4, b = 7, n = 200, h = (b - a) / n, x = a, s = 0;
    while (true) {
        if (x > (b - h)) {
            break;
        }
        else {
            s = s + h * ((pow(cos(x), 3)) + ((pow(cos(x + h), 3)))) / 2;
            x = x + h;
        }
    }
    cout << "x=" << s;
}