#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int A, pos, n, difference;
    char tmp[33];
    cout << "������� A ";
    cin >> A;
    _itoa_s(A, tmp, 2);
    cout << "������������� ����� � �������� ����: " << tmp << endl;
    cout << "������� ��������� ������� ";
    cin >> pos;
    cout << "������� ����� ����� ";
    cin >> n;
    difference = pos - n;
    while (pos >= difference)
    {
        A |= 1 << pos;
        _itoa_s(A, tmp, 2);
        pos--;
    }
    cout << tmp << endl;
}