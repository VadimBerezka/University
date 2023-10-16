
#include <iostream>
using namespace std;
int main() {

	setlocale(LC_CTYPE, "Russian");

	int j = 1;
	double b[5], m = 4, c = -0.045, umnozh = 1;
	for (int n = 0; n < 5; n++) {

		umnozh *= b[n];

	}

	cout << "Произведение: " << umnozh << endl;
	return 0;
}
