#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    for (int i = 1001; i <= 9999; i++) {
        if (i % 2 == 0 && i % 7 == 0 && i % 11 == 0) {
            int num1 = i / 1000;
            int num2 = (i / 100) % 10;
            int num3 = (i / 10) % 10;
            int num4 = i % 10;
            if (num1 + num2 + num3 + num4 == 30) {
                cout << "Номер автомашины" << i << endl;
                break;
            }
        }
    }
    return 0;
}