#include <iostream>
#include <string>
using namespace std;

#define sizeS 30 
#define numSubjects 3

enum Subjects {
    Mathematics = 0,
    History,
    Geography,
    Biology,
    Chemistry,
    Literature,
};

union UPuples
{
    char name[100];
    char numcl[50];
    Subjects lessons[numSubjects];
    int marks;
    char sr_ball;
} pu;

struct Puples
{
    string name;
    string numcl;
    Subjects lessons[numSubjects];
    string marks;
    string sr_ball;
};

struct Class {
    unsigned int classNumber : 4;
    unsigned int classLetter : 5;
};
Puples list_of_puple[sizeS], free_puple;
int current_size_pu = 0;

void new_write();
void del_write();
void out_write();

int main()
{
    setlocale(LC_CTYPE, "Rus");
    int choice = 1;

    while (choice != 0)
    {
        cout << " \n1. ����� ������\n2. ������� ������\n3. ������� ������ � �������\n0. ���������\n(������� �����) ";
        cin >> choice;
        switch (choice)
        {
        case(1):
            new_write();
            break;

        case(2):
            del_write();
            break;

        case(3):
            out_write();
            break;

        default:
            break;
        }
    }
    return 0;
}

void new_write()
{
    if (current_size_pu < sizeS)
    {
        cout << "\n ������ �" << current_size_pu + 1 << ": ";
        cout << "\n ������� �.�.�.: ";
        cin >> pu.name;
        list_of_puple[current_size_pu].name = pu.name;

        Class classInfo;
        int tempNumber;
        cout << "\n ������� ����� ������: ";
        cin >> tempNumber;
        classInfo.classNumber = tempNumber;

        cout << "\n ������� ����� ������: ";
        char letter;
        cin >> letter;
        classInfo.classLetter = letter;
        cout << "\n � ����������: ";
        list_of_puple[current_size_pu].numcl = to_string(classInfo.classNumber) + static_cast<char>(classInfo.classLetter);



        cin >> pu.numcl;
        list_of_puple[current_size_pu].numcl = pu.numcl;
        for (int j = 0; j < numSubjects; j++) {
            cout << "\n ������� ��������(0 - ����������, 1 - �������, 2 - ���������, 3 - ��������, 4 - �����, 5 - ����������) ";
            int subject;
            cin >> subject;
            list_of_puple[current_size_pu].lessons[j] = static_cast<Subjects>(subject);
        }
        cout << "\n ������� ������ �� ���� ���������: ";
        cin >> pu.marks;
        list_of_puple[current_size_pu].marks = pu.marks;
        cout << "\n ������� ������� ����: ";
        cin >> pu.sr_ball;
        list_of_puple[current_size_pu].sr_ball = pu.sr_ball;
        current_size_pu++;
    }
    else
    {
        cout << " ������� ������������ ���-�� �����" << endl;
    }
}

void del_write()
{
    int d;
    cout << " ����� ������, ������� ���� �������(��� �������� ���� ����� ������� -1): ";
    cin >> d;
    if (d == -2)
    {
        for (int i = 0; i < sizeS; i++)
        {
            list_of_puple[i] = free_puple;
        }
        current_size_pu = 0;
    }
    else
    {
        for (int i = d - 1; i < current_size_pu; i++)
        {
            list_of_puple[i] = list_of_puple[i + 1];
        }
        current_size_pu--;
    }
}

void out_write()
{
    string name;
    cout << " ������� �.�.�. ��� ������ ������(��� ������ ���� ������� ������� -1): ";
    cin >> name;
    if (name == "-1")
    {

        for (int i = 0; i < current_size_pu; i++)
        {
            cout << "������ �";
            cout << i + 1;
            cout << ": �.�.�. - ";
            cout << list_of_puple[i].name;
            cout << " | ����� - ";
            cout << list_of_puple[i].numcl;
            cout << " | �������� - ";
            for (int j = 0; j < numSubjects; j++) {
                switch (list_of_puple[i].lessons[j]) {
                case Mathematics:
                    cout << "����������,";
                    break;
                case History:
                    cout << "�������,";
                    break;
                case Geography:
                    cout << "���������,";
                    break;
                case Biology:
                    cout << "��������,";
                    break;
                case Chemistry:
                    cout << "�����,";
                    break;
                case Literature:
                    cout << "����������,";
                    break;

                }
            }
            cout << " | ������ - ";
            cout << list_of_puple[i].marks;
            cout << " | ������� ���� - ";
            cout << list_of_puple[i].sr_ball;
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < current_size_pu; i++)
        {
            if (list_of_puple[i].name == name)
            {
                cout << "������ �";
                cout << i + 1;
                cout << ": �.�.�. - ";
                cout << list_of_puple[i].name;
                cout << " | ����� - ";
                cout << list_of_puple[i].numcl;
                cout << " | �������� - ";
                for (int j = 0; j < numSubjects; j++) {
                    switch (list_of_puple[i].lessons[j]) {
                    case Mathematics:
                        cout << "����������";
                        break;
                    case History:
                        cout << "�������";
                        break;
                    case Geography:
                        cout << "���������";
                        break;
                    case Biology:
                        cout << "��������";
                        break;
                    case Chemistry:
                        cout << "�����";
                        break;
                    case Literature:
                        cout << "����������";
                        break;
                    }
                }
                cout << " | ������ - ";
                cout << list_of_puple[i].marks;
                cout << " | ������� ���� - ";
                cout << list_of_puple[i].sr_ball;
                cout << endl;
            }
        }
    }
}
#include <iostream>
#include <string>
using namespace std;

#define sizeS 30 
#define numSubjects 3

enum Subjects {
    Mathematics = 0,
    History,
    Geography,
    Biology,
    Chemistry,
    Literature,
};

union UPuples
{
    char name[100];
    char numcl[50];
    Subjects lessons[numSubjects];
    int marks;
    char sr_ball;
} pu;

struct Puples
{
    string name;
    string numcl;
    Subjects lessons[numSubjects];
    string marks;
    string sr_ball;
};

struct Class {
    unsigned int classNumber : 4;
    unsigned int classLetter : 5;
};
Puples list_of_puple[sizeS], free_puple;
int current_size_pu = 0;

void new_write();
void del_write();
void out_write();

int main()
{
    setlocale(LC_CTYPE, "Rus");
    int choice = 1;

    while (choice != 0)
    {
        cout << " \n1. ����� ������\n2. ������� ������\n3. ������� ������ � �������\n0. ���������\n(������� �����) ";
        cin >> choice;
        switch (choice)
        {
        case(1):
            new_write();
            break;

        case(2):
            del_write();
            break;

        case(3):
            out_write();
            break;

        default:
            break;
        }
    }
    return 0;
}

void new_write()
{
    if (current_size_pu < sizeS)
    {
        cout << "\n ������ �" << current_size_pu + 1 << ": ";
        cout << "\n ������� �.�.�.: ";
        cin >> pu.name;
        list_of_puple[current_size_pu].name = pu.name;

        Class classInfo;
        int tempNumber;
        cout << "\n ������� ����� ������: ";
        cin >> tempNumber;
        classInfo.classNumber = tempNumber;

        cout << "\n ������� ����� ������: ";
        char letter;
        cin >> letter;
        classInfo.classLetter = letter;
        cout << "\n � ����������: ";
        list_of_puple[current_size_pu].numcl = to_string(classInfo.classNumber) + static_cast<char>(classInfo.classLetter);



        cin >> pu.numcl;
        list_of_puple[current_size_pu].numcl = pu.numcl;
        for (int j = 0; j < numSubjects; j++) {
            cout << "\n ������� ��������(0 - ����������, 1 - �������, 2 - ���������, 3 - ��������, 4 - �����, 5 - ����������) ";
            int subject;
            cin >> subject;
            list_of_puple[current_size_pu].lessons[j] = static_cast<Subjects>(subject);
        }
        cout << "\n ������� ������ �� ���� ���������: ";
        cin >> pu.marks;
        list_of_puple[current_size_pu].marks = pu.marks;
        cout << "\n ������� ������� ����: ";
        cin >> pu.sr_ball;
        list_of_puple[current_size_pu].sr_ball = pu.sr_ball;
        current_size_pu++;
    }
    else
    {
        cout << " ������� ������������ ���-�� �����" << endl;
    }
}

void del_write()
{
    int d;
    cout << " ����� ������, ������� ���� �������(��� �������� ���� ����� ������� -1): ";
    cin >> d;
    if (d == -2)
    {
        for (int i = 0; i < sizeS; i++)
        {
            list_of_puple[i] = free_puple;
        }
        current_size_pu = 0;
    }
    else
    {
        for (int i = d - 1; i < current_size_pu; i++)
        {
            list_of_puple[i] = list_of_puple[i + 1];
        }
        current_size_pu--;
    }
}

void out_write()
{
    string name;
    cout << " ������� �.�.�. ��� ������ ������(��� ������ ���� ������� ������� -1): ";
    cin >> name;
    if (name == "-1")
    {

        for (int i = 0; i < current_size_pu; i++)
        {
            cout << "������ �";
            cout << i + 1;
            cout << ": �.�.�. - ";
            cout << list_of_puple[i].name;
            cout << " | ����� - ";
            cout << list_of_puple[i].numcl;
            cout << " | �������� - ";
            for (int j = 0; j < numSubjects; j++) {
                switch (list_of_puple[i].lessons[j]) {
                case Mathematics:
                    cout << "����������,";
                    break;
                case History:
                    cout << "�������,";
                    break;
                case Geography:
                    cout << "���������,";
                    break;
                case Biology:
                    cout << "��������,";
                    break;
                case Chemistry:
                    cout << "�����,";
                    break;
                case Literature:
                    cout << "����������,";
                    break;

                }
            }
            cout << " | ������ - ";
            cout << list_of_puple[i].marks;
            cout << " | ������� ���� - ";
            cout << list_of_puple[i].sr_ball;
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < current_size_pu; i++)
        {
            if (list_of_puple[i].name == name)
            {
                cout << "������ �";
                cout << i + 1;
                cout << ": �.�.�. - ";
                cout << list_of_puple[i].name;
                cout << " | ����� - ";
                cout << list_of_puple[i].numcl;
                cout << " | �������� - ";
                for (int j = 0; j < numSubjects; j++) {
                    switch (list_of_puple[i].lessons[j]) {
                    case Mathematics:
                        cout << "����������";
                        break;
                    case History:
                        cout << "�������";
                        break;
                    case Geography:
                        cout << "���������";
                        break;
                    case Biology:
                        cout << "��������";
                        break;
                    case Chemistry:
                        cout << "�����";
                        break;
                    case Literature:
                        cout << "����������";
                        break;
                    }
                }
                cout << " | ������ - ";
                cout << list_of_puple[i].marks;
                cout << " | ������� ���� - ";
                cout << list_of_puple[i].sr_ball;
                cout << endl;
            }
        }
    }
}
