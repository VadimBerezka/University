#include <iostream>
#include <cmath>
using namespace std;
double recursiveRootSum(int n) {
    if (n == 0) {
        return 0;
    }
    else {

        return sqrt(1 + (n + 1) * recursiveRootSum(n - 1));
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n = 2;
    cout << "Результат: " << recursiveRootSum(n) << endl;
    return 0;
}
