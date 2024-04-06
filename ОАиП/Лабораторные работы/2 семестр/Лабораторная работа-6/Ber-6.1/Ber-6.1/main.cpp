#include <iostream>
#include <fstream>
#include <list>
using namespace std;

void print_menu() {
    setlocale(LC_ALL, "rus");
    cout << "1. �������� �������\n";
    cout << "2. ������� �������\n";
    cout << "3. ����� �������\n";
    cout << "4. ������� ������\n";
    cout << "5. �������� ������ � ����\n";
    cout << "6. ������� ������ �� �����\n";
    cout << "7. ����� ����� ������������� ���������, ������� 5\n";
    cout << "8. �����\n";
}

void add_element(list<int>* l) {
    int value;
    cout << "������� ��������: ";
    cin >> value;
    l->push_back(value);
}

void remove_element(list<int>* l) {
    int value;
    cout << "������� ��������: ";
    cin >> value;
    l->remove(value);
}

void find_element(list<int>* l) {
    int value;
    cout << "������� ��������: ";
    cin >> value;
    auto it = find(l->begin(), l->end(), value);
    if (it != l->end()) {
        cout << "������� ������\n";
    }
    else {
        cout << "������� �� ������\n";
    }
}

void print_list(list<int>* l) {
    for (int i : *l) {
        cout << i << ' ';
    }
    cout << '\n';
}

void write_to_file(list<int>* l) {
    ofstream file("list.txt");
    for (int i : *l) {
        file << i << ' ';
    }
    file.close();
}

void read_from_file(list<int>* l) {
    ifstream file("list.txt");
    int i;
    while (file >> i) {
        l->push_back(i);
    }
    file.close();
}

void sum_positive_multiples_of_five(list<int>* l) {
    int sum = 0;
    for (int i : *l) {
        if (i < -9) {
            sum += i;
        }
    }
    if (sum == 0) {
        cout << "��� ������������� ����������� ���������\n";
    }
    else {
        cout << "����� ������������� ����������� ���������: " << sum << '\n';
    }
}

int main() {
    list<int> l;
    int choice;
    do {
        print_menu();
        cin >> choice;
        switch (choice) {
        case 1:
            add_element(&l);
            break;
        case 2:
            remove_element(&l);
            break;
        case 3:
            find_element(&l);
            break;
        case 4:
            print_list(&l);
            break;
        case 5:
            write_to_file(&l);
            break;
        case 6:
            read_from_file(&l);
            break;
        case 7:
            sum_positive_multiples_of_five(&l);
            break;
        case 8:
            break;
        default:
            cout << "�������� �����\n";
        }
    } while (choice != 8);
    return 0;
}