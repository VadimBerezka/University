#include <iostream>
using namespace std;

int main()
{
	
	setlocale(LC_CTYPE, "Russian");

    int a, b, c;
    cout << "������� ��� �����: ";
    cin >> a;
    cin >> b;
    cin >> c;

    if (a == b || a == c || b == c) 
    {
      cout << "���� ���� �� ���� ���� ������ �����." << endl;
    }
    else {
      cout << "��� ���� ������ �����." << endl;
    }
	return 0;
}
