#include <iostream>
using namespace std;

void addOne(float* A, int n) {
    if (A[0] != 0)
        for (int i = 0; i < n; i++)
            A[i] += 1;
}

void convertString(char* str, int n) {
    for (int i = 0; i < n; i++) {
        if ((str[i] >= '�' && str[i] <= '�') || (str[i] >= '�' && str[i] <= '�'))
            str[i] = toupper(str[i]);

        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            str[i] = '?';
    }
}



int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    cout << "������� ����� �������: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int n, m;
        cout << "������� ���������� ����� n: ";
        cin >> n;
        cout << "������� ���������� �������� m: ";
        cin >> m;

        float** A = new float* [n];
        for (int i = 0; i < n; i++) {
            A[i] = new float[m];
        }
        cout << "������� �������� �������: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }


        for (int i = 0; i < n; i++) {
            addOne(A[i], m);
        }

        cout << "���������� ������ A:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++) {
            delete[] A[i];
        }
        delete[] A;

        break;
    }


    case 2: {
        char str[] = "����� Berezka";
        int length = sizeof(str);

        convertString(str, length);
        cout << str << endl;
        break;
    }


    default:
        cout << "������������ ����";
        break;
}
    return 0;
}