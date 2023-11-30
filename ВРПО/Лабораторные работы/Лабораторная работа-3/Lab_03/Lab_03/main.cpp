#include <iostream> 
#include <string> 
#include <windows.h> 
using namespace std;

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_CTYPE, "russian");
    int choice;
    unsigned char input;
    char num;
    int to_up, to_low, razn;
    while (true) {
        cout << "�������� ������� �������������:" << endl;
        cout << "������a �������� ����� � Windows-1251 �������� ����� ���������� �������� � ��������� � �������� ��������� (1) " << endl;
        cout << "������� �������� ����� � Windows-1251 �������� ����� �������� �������� � ��������� � �������� ��������� (2) " << endl;
        cout << "������� �������� ���������� ����� � ��� ���������������� �� ������� � Windows-1251 (3) " << endl;
        cout << "����� �� ��������� (4) " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ������: ";
            cin >> input;
            if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
                to_up = (int)toupper(input);
                to_low = (int)tolower(input);
                razn = to_low - to_up;
                cout << "������a �������� ����� � Windows-1251 �������� ����� ���������� �������� � ��������� � �������� ���������: " << razn << endl << endl;
            }

            else {
                cout << "������" << endl << endl;
            }
            break;
        case 2:
            cout << "������� ������: ";

            cin >> input;
            if ((input) >= 0xC0 && (input) <= 0xFF) {

               to_up = (int)toupper(input);
               to_low = (int)tolower(input);
               razn = to_low - to_up;

                cout << "������� �������� ����� � Windows-1251 �������� ����� �������� �������� � ��������� � �������� ���������: " << razn << endl << endl;
            
            }
            else {
                cout << "������" << endl << endl;
            }
            break;
        case 3:
            cout << "������� �����: ";
            cin >> num;
            if (num >= 0x30 && num <= 0x39) {
                cout << "��� �������, ���������������� ��������� �����: " << (int)num << endl << endl;
            }
            else
                cout << "������ " << endl << endl;

            break;

        case 4:
            return 0;

        default:
            cout << "������" << endl << endl;
        }
    }
    return 0;
}