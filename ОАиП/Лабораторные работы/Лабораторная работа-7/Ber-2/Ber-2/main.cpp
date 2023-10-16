#include <stdio.h>
#include <iostream>
void main()
{
	double a, b, i, d, z;
	b = -0.05;
	a = 1.72;
	i = -5;

	while (i <= 5)
	{
		if (i > 3 * b) {
			d = a + b * i;
		}
		else {
			if (i <= 3 * b) {
				d = tan(b) - a * i;
			}
		}
		z = (d * a / 4) / (3 * a * b - exp(1 + d) / 100);
		printf("d=%0.2f\t", d);
		printf("z=%5.2f\n", z);
		i = i + 2;
	}
}