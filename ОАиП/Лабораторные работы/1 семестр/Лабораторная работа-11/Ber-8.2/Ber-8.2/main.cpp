#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int n, m, A, B, C ; char tmp[33];
	cout << "������� ����� A" << endl; cin >> A;
	cout << "������� ����� B" << endl; cin >> B;
	cout << "� ����� ������� ��������� ���� � ����� �:" << endl; cin >> n;
	cout << "� ����� ������� �������� ���� � �:" << endl; cin >> m;
	int maskA = 7 << n;
	int maskB = 7 << m;
	_itoa_s(A, tmp, 2);
	cout << "����� �: " << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << "����� �: " << tmp << endl;
	B = B ^ maskB;
	C = B | ((A & (maskA)) >> n);
	_itoa_s(C, tmp, 2);
	cout << "���������: " << tmp << endl;
	cout << "���������: " << C << endl;
}
