#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int n, m, A, B; char tmp[33];
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
	_itoa_s(B | ((A & (maskA)) >> n), tmp, 2);
	cout << "���������: " << tmp << endl;
}
