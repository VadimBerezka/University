#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	setlocale(LC_CTYPE, "Russian");

	int n, k;
	cout << "¬ведите размер массива n = ";
	cin >> n;

	double* A = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		A[i] = -10 + (double)rand() / RAND_MAX * 20;
		cout << A[i] << " ";

		if (A[i] < 0) {
			k = i;
		}
	}
	cout << "\n»ндекс последнего минимального элемента массива:" << k << endl;
	free(A);
}
