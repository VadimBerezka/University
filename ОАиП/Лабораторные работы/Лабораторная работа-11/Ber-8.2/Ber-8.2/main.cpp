#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int n, m, A, B, C ; char tmp[33];
	cout << "Введите число A" << endl; cin >> A;
	cout << "Введите число B" << endl; cin >> B;
	cout << "С какой позиции извлекать биты в числе А:" << endl; cin >> n;
	cout << "С какой позиции вставить биты в В:" << endl; cin >> m;
	int maskA = 7 << n;
	int maskB = 7 << m;
	_itoa_s(A, tmp, 2);
	cout << "Число А: " << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << "Число В: " << tmp << endl;
	B = B ^ maskB;
	C = B | ((A & (maskA)) >> n);
	_itoa_s(C, tmp, 2);
	cout << "Результат: " << tmp << endl;
	cout << "Результат: " << C << endl;
}
