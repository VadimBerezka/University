#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k, n;
	cout << "������� ����� k: ";
	cin >> k;
	for (int i = 0; i < 1000; i++)
	{
		n = pow(2, i);
		// �������� ��������� �� �������� i + 1 k, �c�� ��, �� ���� �����������
		if (i + 1 == k) break;
	}
	cout << n << endl;
	return 0;
}