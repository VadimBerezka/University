#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int A, maskA = 85; char tmp[33];
	cout << "������� ����� A" << endl; cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "����� �: " << tmp << endl;
	_itoa_s(maskA, tmp, 2);
	cout << "����� ����� �: " << tmp << endl;
	_itoa_s(A | maskA, tmp, 2);
	cout << "���������: " << tmp << endl;
}
