#include <iostream>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int A, B, res1, res2, res3, res ;
	char tmp[33];

	cout << "������� ����� A: ";
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "����� � � �������� ����: " << tmp << endl;

	cout << "������� ����� B: ";
	cin >> B;
	_itoa_s(B, tmp, 2);
	cout << "����� � � �������� ����: " << tmp << endl;

		
	res1 = (B >> 2) << 7;
	res2 = B & 3;
	res3 = A << 1;
	res = res1 | res2 | res3;


	cout << "���������� �����" << res << endl;
	_itoa_s(res, tmp, 2);
	cout << "������������� ����������� ����� � �������� ����: " << tmp << endl;
	return 0;
}



//#include <iostream>
	//using namespace std;

	//void main()
	//{
	//setlocale(LC_CTYPE, "Russian");

	//char tmp[33];
	//int A, B, maskA = 14;
	//int maskB = ~maskA >> 1;


	//cout << "������� ����� A:"; 
	//cin >> A;
	//cout << "������� ����� B:"; 
	//cin >> B;
	//
	//_itoa_s(A, tmp, 2);
	//cout << "����� �: " << tmp << endl;

	//_itoa_s(B, tmp, 2);
	//cout << "����� �: " << tmp << endl;


	//_itoa_s(maskA, tmp, 2);
	//cout << "����� ��� �: " << tmp << endl;

	//_itoa_s((A & maskA) >> 1, tmp, 2);
	//cout << "���������� ���� �: " << tmp << endl;


	//_itoa_s(maskB, tmp, 2);
	//cout << "����� ��� �: " << tmp << endl;


	//_itoa_s(B & maskB, tmp, 2);
	//cout << " ������� ���� � B: " << tmp << endl;

	//_itoa_s(((B & maskB) | ((A & maskA) >> 1)), tmp, 2);
	//cout << " ��������� B=" << tmp << endl;
	//
	//}