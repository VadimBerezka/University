#include <iostream>
#include <string>//������ ��������� ����� ��� ������������ ���� ������ string


using namespace std;

string reverse(string str) {//������ ������� ���������� ��������� ������ � ������������ ����
    int len = str.length();
    int n = len - 1;//�.�. � ����� ������ ������ ���� '\0',�� ���  �� ��������� � �����
    int i = 0;
    while (i <= n) {
        swap(str[i], str[n]);//���������� ������� swap ��� ����� �������� ������� �������
        n = n - 1;
        i = i + 1;
    }
    return str;
}


int main() {
    system("color 70");
    setlocale(LC_CTYPE, "Russian");

    string str, rev;//���������� ������ �������� ��� �������� ���������� � ����������� ���������� � ���� ����� ��������� 
    int max_g = 0, count_s = 0, count_p = 1, size;//�������� ���� � 1,����� ��������� ������ �������,������� � ������
    cout << "������� ������ S:";
    getline(cin, str);
    str.insert(str.size(), " ");//��������� � ����� ������ ��� ����������� ��������� ���������� �����
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' and count_p % 2 != 0) {//���� ����� ��������,�� �� ��� �������
            str.erase(i - count_s, count_s);
            count_p == 1 ? str.erase(0, 1) : str.erase(0, 0);//����� �������� ������� ����� ������� ��� � ������ ����� ��� � ������ ������
            i -= count_s;//������������ �� �� ����� � ������,��� ���������� �� ��������� ��������� �����
            count_s = 0;
            count_p++;
        }
        else if (str[i] == ' ' and count_p % 2 == 0) {//���� ����� ������,�� �������������� ���
            count_p++;
            count_p > 3 ? count_s -= 1 : count_s -= 0;//����� ������� ������� ����� ����� �� ��������� ������� ����� ��� ������
            rev = str.substr(i - count_s, count_s);//��������� ����������� ����� �� ������
            rev = reverse(rev);//�������������� ��� � ������� ������� reverse 
            str.erase(i - count_s, count_s);//������� ������ �����
            str.insert(i - count_s, rev);//� ��������� �����
            count_s = 0;
        }
        count_s++;
    }
    cout << str;
    return 0;
}
