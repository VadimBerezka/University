#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int a = 0, b = 0;
	const int n = 15;
	int K[n] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }, L[n], M[n];
	for (int i = 0; i < n; i++) {
		if (K[i] % 2 == 0) {
			L[a] = K[i];
			a++;
		}
		else {
			M[b] = K[i];
			b++;
		}
	}
	cout << "��� ������ ����� �������:";
	for (int i = 0; i < a; i++) {
		cout << L[i] << " ";
	
	}
	cout << "\n���-�� ������:" << a << endl;

	cout << "��� �������� ����� �������:";
	for (int i = 0; i < b; i++) {
		cout << M[i] << " ";
	}
	cout << "\n���-�� ��������:" << b << endl;
	return 0;
}