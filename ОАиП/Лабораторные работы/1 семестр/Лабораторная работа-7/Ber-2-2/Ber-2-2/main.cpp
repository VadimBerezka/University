#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int sum = 0;

    for (int i = 1; i < 200; i++) {
        if (i % 3 == 0) {
            sum += i;
            cout << "i:" << i << endl;
        }
    }

    cout << "Сумма чисел: " << sum << endl;

    return 0;
}