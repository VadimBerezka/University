#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int i = 1;
	double x[5] = { 2.7, -5, 4, 3.5, -7 }, sum = 0, multiply = 1;
	for (int n = 0; n < 5; n++) {
		if (x[n] > 0) {
			sum += x[n];
		}
		else if (x[n] <= 0) {
			multiply *= x[n];
		}
	}
	cout << "Сумма: " << sum << endl << "Произведение: " << multiply;
	return 0;
}