#include <iostream>
using namespace std;
int main() 
{
    setlocale(LC_CTYPE, "Russian");
    int n, m, k;
    cout << "������� ��� ����� �����: ";
    cin >> n >> m >> k;

    if (n % 2 != 0 || m % 2 != 0 || k % 2 != 0) {
       cout << "����� �������� ����� ���� �������� �����." << endl;
    }
    else {
        cout << "����� �������� ����� ��� �������� �����." << endl;
    }

    return 0;
}
