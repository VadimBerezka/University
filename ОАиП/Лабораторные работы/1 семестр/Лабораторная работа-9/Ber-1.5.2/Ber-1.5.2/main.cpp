#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	double n = 200, a = 1, b = 3, h = (b - a) / (2 * n), x = a + 2 * h, s1 = 0, s2 = 0, i = 1, s;
	while (i < n) {
		s2 += pow(x, 3) - 3;
		x += h;
		s1 += pow(x, 3) - 3;
		x += h;
		i++;
	}
	s = h / 3 * (pow(x, 3) - 3) + (4 * (pow(x, 3) - 3)) + 4 * s1 + 4 * s2 + (pow(b, 3) - 3);
	cout << "s= " << s;
	return 0;
}
