#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    string str1, str2, FIND;
    int count_s = 0, pos;
    cout << "������� ������ S1:"; getline(cin, str1);//��� ������ ������� getline �� ����� ������� ������ ������ � ���������
    str1.insert(str1.size(), " ");
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == ' ') {//��������� ���� �� ������� ����� � ������ ������
            FIND = str1.substr(i - count_s, count_s);//� ������� subtract ��������� ������� �����
            pos = str1.find(FIND);//������� ���� �� ��� � ������ 2
            if (pos < i - count_s) {//���� ��������� ���-�� ������ -1,�� ������ ����� ����
                str1.erase(i - count_s, count_s + 1);//������� ���
                i -= count_s;//������������ �� �� ����� � ������, ��� ���������� �� ��������� ��������� �����
                count_s = 1;
            }
            else {
                count_s = 0; 
            }
        }
        else { 
            count_s++; 
        }

    }
    cout << str1;
    return 0;
}
