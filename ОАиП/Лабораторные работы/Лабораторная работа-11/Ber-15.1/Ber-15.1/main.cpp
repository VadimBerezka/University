#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int A; char tmp[33];
	cout << "������� ����� �: " << endl; cin >> A;
	(A & 1) == 1 ? cout << "����� ��������." << endl : cout << "����� ������." << endl;
}
