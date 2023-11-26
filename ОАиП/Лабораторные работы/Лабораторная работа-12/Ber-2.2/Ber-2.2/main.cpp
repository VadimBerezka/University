#include <iostream> 
using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");
	int n;
	int a[100];
	bool t = false;
	cout << "¬ведите n ";
	cin >> n;
	cout << "¬ведите элементы массива n ";
	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}

	for (int j = 1; j < INT_MAX; j++) {

		for (int i = 0; i < n; i++) {

			if (*(a + i) == j) {
				t = true;
				break;
			}

		}

		if (t == false) {
			cout << j;
			break;
		}

		else {
			t = false;
		}

	}

}