/*
#include <stdio.h>
#include <iostream>

void main() {
    setlocale(LC_CTYPE, "Russian");
    float a, b, c;

    printf("������� ����� a: ");
    scanf_s("%f", &a);
    printf("������� ����� b: ");
    scanf_s("%f", &b);

    c = a;
    a = b;
    b = c;

    printf("������ �����: %.2f\n", a);
    printf("������ �����: %.2f\n", b);
}
*/
#include <stdio.h>
#include <iostream>

void main() {
    setlocale(LC_CTYPE, "Russian");
    float a, b;

    printf("������� ����� a: ");
    scanf_s("%f", &a);
    printf("������� ����� b: ");
    scanf_s("%f", &b);

    b = a + b;
    a = b - a;
    printf("������ �����: %.2f\n", a);

    b = b - a;
    printf("������ �����: %.2f\n", b);
}