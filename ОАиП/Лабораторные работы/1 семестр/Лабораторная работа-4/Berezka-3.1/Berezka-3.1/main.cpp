/*
#include <stdio.h>
#include <iostream>

void main() {
    setlocale(LC_CTYPE, "Russian");
    float a, b, c;

    printf("Введите число a: ");
    scanf_s("%f", &a);
    printf("Введите число b: ");
    scanf_s("%f", &b);

    c = a;
    a = b;
    b = c;

    printf("Первое число: %.2f\n", a);
    printf("Второе число: %.2f\n", b);
}
*/
#include <stdio.h>
#include <iostream>

void main() {
    setlocale(LC_CTYPE, "Russian");
    float a, b;

    printf("Введите число a: ");
    scanf_s("%f", &a);
    printf("Введите число b: ");
    scanf_s("%f", &b);

    b = a + b;
    a = b - a;
    printf("Первое число: %.2f\n", a);

    b = b - a;
    printf("Второе число: %.2f\n", b);
}