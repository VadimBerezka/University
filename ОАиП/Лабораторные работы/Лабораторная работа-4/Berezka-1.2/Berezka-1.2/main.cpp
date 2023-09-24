#include <stdio.h>
#include <iostream>

void main() {
    setlocale(LC_CTYPE, "Russian");
    float a, b, s;

    printf("Введите число b: ");
    scanf_s("%f", &b);

    a = b /sqrt(2);
    s = a * a;

    printf("Сторона квадрата= %.4f\n", a);
    printf("Площадь: %.4f\n", s);
}
/*
есть диагональ квадрата 
найти его площадь
a=b/sqrt(2)
S=a*a

*/