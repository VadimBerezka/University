#include <iostream>
using namespace std;
int main() {

	setlocale(LC_CTYPE, "Russian");
	double b[4], m = 4, c = -0.045, multiply = 1, g;
	for (int j = 0; j < m; j++) {
		cout << "¬ведите b = ";
		cin >> b[j];

		multiply *= pow(b[j] + 1, 2);
	

	}
	g = c * multiply;
	cout << "g= " << g << endl;
	return 0;
}