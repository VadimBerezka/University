#include <stdio.h>
#include <iostream>

void main() {
    setlocale(LC_CTYPE, "Russian");
    float a, b, s;

    printf("������� ����� b: ");
    scanf_s("%f", &b);

    a = b /sqrt(2);
    s = a * a;

    printf("������� ��������= %.4f\n", a);
    printf("�������: %.4f\n", s);
}
/*
���� ��������� �������� 
����� ��� �������
a=b/sqrt(2)
S=a*a

*/