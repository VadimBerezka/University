#include <iostream>
#include <stdarg.h>
using namespace std;

int fsum(int num_args, ...) {
    int result = 0;
    int a, b;
    
    va_list args;

    va_start(args, num_args);
    a = va_arg(args, int);
    for (int i = 0; i < num_args / 2; i++) {

            
        b = va_arg(args, int);
            
                
        result += a * b;
        a = b;
    }

    va_end(args);
    
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Первая сумма: " << fsum(1, 11) << endl; //121
    cout << "Вторая сумма: " << fsum(7, 2, 3, 4, 5, 6, 7, 8) << endl; //100
    cout << "Третья сумма: " << fsum(3, 10, 11, 12) << endl; //222
    //fsum(7, 2, 3, 4, 5, 6, 7, 8);
    return 0;
}