
#include <stdio.h>
#include <iostream>

void main() {
    setlocale(LC_CTYPE, "Russian");
    float m, part1, part2;

    printf("������� ����� m: ");
    scanf_s("%f", &m);

    part1 = m / 2 + 2.5;
    part2 = m / 2 - 2.5;

    printf("������ ����� �����: %.3f\n", part1);
    printf("������ ����� �����: %.3f\n", part2);
}