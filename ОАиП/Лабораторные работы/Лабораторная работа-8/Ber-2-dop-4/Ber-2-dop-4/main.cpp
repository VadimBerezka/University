#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int size, num = 0;
	bool sign = true;
	cout << "������� ������ �������: ";
	cin >> size;
	// �������� ������������� �������
	int* n{ new int[size] };
	cout << "������� �������� �������: ";
	for (int i = 0; i < size; i++) {
		cin >> n[i];
		// �������� ������� if, ������� ��������� ����������� �� ������� ������� � ����������� �� ������� � ��������
		if (!sign && n[i] > 0)
		{
			sign;
			num++;
		}
		else if (sign && n[i] < 0)
		{
			!sign;
			num++;
		}
	}
	cout << "���������� �����������: " << num;
	return 0;
}
