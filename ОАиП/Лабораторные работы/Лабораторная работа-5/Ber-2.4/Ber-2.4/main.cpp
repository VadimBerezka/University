#include <iostream>
using namespace std;
int main()
{
  
    setlocale(LC_CTYPE, "Russian");
    int r, p, q, md;
    cout << "������� ������ ����: ";
    cin >> r;
    cout << "������� ������ ��������� ����� : ";
    cin >> p;
    cout << "������� ������ ��������� ����� : ";
    cin >> q;
    md = min(p, q);
    if (2 * r <= md)
        cout << "�������";
    else
        cout << "�� �������";
    return 0;
}
