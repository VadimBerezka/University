#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int A, n, p; char tmp[33];
	cout << "Введите число А: " << endl; cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "Число А: " << tmp << endl;
	cout << "Введите количество битов:  " << endl; cin >> n;
	cout << "Введите позицию p:  " << endl; cin >> p;
	int maskA = (1 << (n)) - 1;
	_itoa_s(A ^ ~(maskA << p - 1), tmp, 2);
	cout << "Результат: " << tmp << endl;
}
