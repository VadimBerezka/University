#include <iostream>
using namespace std;
int main() {

	setlocale(LC_CTYPE, "Russian");
	double  y[5] = { 6, 2, 0.9, 0.1, 5 }, t = y[0], multiply = 1;
	for (int i = 1; i < 5; i++) {
		if (y[i] < t) {
			t = y[i];
			
		}
	}
	for (int i = 0; i < 5; i++)
	{
		multiply *= y[i] + t;
	}
	cout << "минимальное t: " << t << endl;
	cout << "Произведение: " << multiply << endl;
	return 0;
}
