#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    string str1, str2, FIND;
    int count_s = 0, pos, ind = 0, min_word;
    cout << "������� ������ S1:"; getline(cin, str1);//��� ������ ������� getline �� ����� ������� ������ ������ � ���������
    cout << "������� ������ S2:"; getline(cin, str2);
    min_word = str1.size();
    str1.insert(str1.size(), " ");//��������� � ����� ������ ��� ����������� ��������� ���������� 
    str2.insert(str2.size(), " ");//��������� � ����� ������ ��� ����������� ��������� ���������� �����
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == ' ') {//��������� ���� �� ������� ����� � ������ ������
            FIND = str1.substr(i - count_s, count_s);//� ������� subtract ��������� ������� �����
            pos = str2.find(FIND);//������� ���� �� ��� � ������ 2
            if (pos == 0) {//���� ����� ������ �� ������ ������,�� ���� ������ ������ ����� ������ �����
                if (str2[pos + count_s] == ' ') { count_s = 0; }//��������� ������� �� ������� ����� ��������� ������,� �� ������ �������
                else {
                    if (min_word > count_s) {//������� �������� �� ��� ����� ���������� � ���� ���,�� ���������� ��� ������ � ������
                        min_word = count_s;
                        ind = i - count_s;
                    };
                    count_s = 0;
                }
            }

            if (pos > 0) {//���� ������� �� � ����� �����
                if (str2[pos - 1] == ' ' and str2[pos + count_s] == ' ') { count_s = 0; }
                else {
                    if (min_word > count_s) {//������� �������� �� ��� ����� ���������� � ���� ���,�� ���������� ��� ������ � ������
                        min_word = count_s;
                        ind = i - count_s;
                    };
                    count_s = 0;
                }
            }
            if (pos < 0) {
                if (min_word > count_s) {//������� �������� �� ��� ����� ���������� � ���� ���,�� ���������� ��� ������ � ������
                    min_word = count_s;
                    ind = i - count_s;
                };
                count_s = 0;
            }

        }
        else { count_s++; }

    }
    cout << str1.substr(ind, min_word);
    return 0;
}
