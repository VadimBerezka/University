#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double P, Q;
	int per = 3, days = 0;
	cout << "������� �� ������� ���.��� �������� ����������� ������� : ";
	cin >> P;
	cout << "����� �������� ������� ������ ��������� : ";
	cin >> Q;
	while (P <= Q) {
		P += P * per / 100;
		days++;
	};
	cout << P << endl;
	cout << "���������� ����, ������� ����������� ����� ��������� ��� ��������: " << days;
	return 0;
}
