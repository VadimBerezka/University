#include <iostream>
using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");
	int A, maskA; char tmp[33];
	maskA = ~36; //36 00100100 - ������ ������ �������� ��� ����� 
	cout << "������� ����� A" << endl; cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "����� �: " << tmp << endl;
	_itoa_s(maskA, tmp, 2);
	cout << "����� ����� �: " << tmp << endl;
	_itoa_s(A & maskA, tmp, 2);
	cout << "���������: " << tmp << endl;
}