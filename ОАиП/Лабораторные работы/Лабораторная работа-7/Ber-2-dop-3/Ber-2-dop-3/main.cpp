#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int i = 1;
	double C1 = 0, C2 = 0;
	cout << "¬ведите количество литров воды в первом сосуде: ";
	cin >> C1;
	cout << "¬ведите количество литров воды во втором сосуде: ";
	cin >> C2;
	while (i <= 12) {
		C1 /= 2;
		C2 += C1;
		C2 /= 2;
		C1 += C2;
		i++;
	}
	cout << " оличество литров воды в первом сосуде: " << C1 << endl;
	cout << " оличество литров воды во втором сосуде: " << C2 << endl;
	return 0;
}