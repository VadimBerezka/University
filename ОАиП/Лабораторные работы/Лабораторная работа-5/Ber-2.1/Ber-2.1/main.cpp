#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int num1, num2, num3, sum;
	cout << "������� ������ �����: ";
	cin >> num1;
	cout << "������� ������ �����: ";
	cin >> num2;
	cout << "������� ������ �����: ";
	cin >> num3;
	// ��������� �������� ������� � ��������� ������� ����� (������� �� ������ ����� �� 5 ��� �������)
	sum = ((num1 % 5 == 0) ? num1 : 0) + ((num2 % 5 == 0) ? num2 : 0) + ((num3 % 5 == 0) ? num3 : 0);
	cout << "�����: ";
	// ��������� �������� ������� � ��������� ����� �� ����� ����
	(sum != 0) ? cout << sum : cout << "Error";
	return 0;
}
