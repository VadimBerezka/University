#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	double x[5] = { 5.1, 6.4, 3, 2, 6 }, c = 0, a = x[0];
	for (int i = 0; i < 5; i++) {
		if (x[i] < a) {
			a = x[i];
			c += (x[i] / (1 + x[i]));
		}
	}
	c += a;
	cout << "Результат: " << c;
	return 0;
}