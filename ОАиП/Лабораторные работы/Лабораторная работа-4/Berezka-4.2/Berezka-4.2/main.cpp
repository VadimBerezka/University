#include <stdio.h>
#include <iostream>

void main() {
    setlocale(LC_CTYPE, "Russian");
    float x, y, z, a, b;

    printf("������� ����� x: ");
    scanf_s("%f", &x);
    printf("������� ����� y: ");
    scanf_s("%f", &y);
    printf("������� ����� z: ");
    scanf_s("%f", &z);

    a = (abs(x) + abs(y) + abs(z)) / 3;
    b = pow(abs(x) * abs(y) * abs(z), 1.0 / 3.0);

     printf("������� �������������� �������: %.3f\n", a);
     printf("������� �������������� �������: %.3f\n", b);
}