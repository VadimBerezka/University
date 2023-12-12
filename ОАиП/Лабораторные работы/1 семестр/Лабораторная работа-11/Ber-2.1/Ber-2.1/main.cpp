#include <iostream>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int A, B, res1, res2, res3, res ;
	char tmp[33];

	cout << "Введите число A: ";
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "Число А в двоичном коде: " << tmp << endl;

	cout << "Введите число B: ";
	cin >> B;
	_itoa_s(B, tmp, 2);
	cout << "Число В в двоичном коде: " << tmp << endl;

		
	res1 = (B >> 2) << 7;
	res2 = B & 3;
	res3 = A << 1;
	res = res1 | res2 | res3;


	cout << "Полученное число" << res << endl;
	_itoa_s(res, tmp, 2);
	cout << "Представление полученного числа в двоичном коде: " << tmp << endl;
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


	//cout << "Введите число A:"; 
	//cin >> A;
	//cout << "Введите число B:"; 
	//cin >> B;
	//
	//_itoa_s(A, tmp, 2);
	//cout << "Число А: " << tmp << endl;

	//_itoa_s(B, tmp, 2);
	//cout << "Число В: " << tmp << endl;


	//_itoa_s(maskA, tmp, 2);
	//cout << "Маска для А: " << tmp << endl;

	//_itoa_s((A & maskA) >> 1, tmp, 2);
	//cout << "Выделенные биты А: " << tmp << endl;


	//_itoa_s(maskB, tmp, 2);
	//cout << "Маска для В: " << tmp << endl;


	//_itoa_s(B & maskB, tmp, 2);
	//cout << " Очищены биты в B: " << tmp << endl;

	//_itoa_s(((B & maskB) | ((A & maskA) >> 1)), tmp, 2);
	//cout << " Результат B=" << tmp << endl;
	//
	//}