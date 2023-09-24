#include <stdio.h>
#include <iostream>

void main() {
    setlocale(LC_CTYPE, "Russian");
    float x, y, z, a, b;

    printf("¬ведите число x: ");
    scanf_s("%f", &x);
    printf("¬ведите число y: ");
    scanf_s("%f", &y);
    printf("¬ведите число z: ");
    scanf_s("%f", &z);

    a = (abs(x) + abs(y) + abs(z)) / 3;
    b = pow(abs(x) * abs(y) * abs(z), 1.0 / 3.0);

     printf("—реднее арифметическое модулей: %.3f\n", a);
     printf("—реднее геометрическое модулей: %.3f\n", b);
}