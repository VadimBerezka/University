#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
 
int main() {
    setlocale(0,"");
    cout << "����� ���������� � ����: ������ �����, ���� 5 ������� " << endl;
    srand(static_cast<unsigned int>(time(0)));
    int tries = 1;
    string a; int secr1; int secr2;
    int secr = rand()%100+1;
    secr1 = rand()%secr + 1;
    secr2 = rand()%secr + secr1;
    cout << "���� ��� ����� �� �����, �� ��������: ������; ������. ���� ������, �� ������ ��." << endl;
    cout << "������� �����: " << tries << " ��� �����: "<< secr << endl;
    getline(cin, a);
    do {
 
        if (a == "������"){
++tries;
cout << "������� �����: " << tries << endl;
cout << secr2 << endl;
getline(cin,a);
}
else if (a == "������") {
    ++tries;
    cout << "������� �����: " << tries << endl;
    cout << secr1 << endl;
    getline(cin,a);
}
else if (a == "��") {
cout << "�������!!!, ���� ���������� �������: " << tries; break;
} else
    {cout << "�� �� ���!!!, ����� ��������� " << endl;
        getline(cin,a); }
    }  while(tries != 5); if (tries == 5)
        cout << "I ��������!!!, ���������� ������� �����: " << tries << endl;
 return 0;
}