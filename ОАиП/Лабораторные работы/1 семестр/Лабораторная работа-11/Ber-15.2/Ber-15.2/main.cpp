#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int A, n, p; char tmp[33];
	cout << "������� ����� �: " << endl; cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "����� �: " << tmp << endl;
	cout << "������� ���������� �����:  " << endl; cin >> n;
	cout << "������� ������� p:  " << endl; cin >> p;
	int maskA = (1 << (n)) - 1;
	_itoa_s(A ^ ~(maskA << p - 1), tmp, 2);
	cout << "���������: " << tmp << endl;
}
