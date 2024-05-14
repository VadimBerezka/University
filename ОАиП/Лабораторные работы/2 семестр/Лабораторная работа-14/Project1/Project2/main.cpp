// 1 var
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string productName;
    int year;
    Node* next;
};

struct HashTable {
    Node** table;
    int size;

    HashTable(int size) {
        this->size = size;
        table = new Node * [size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    void insertItem(string product, int year) {
        int index = hashFunction(year);
        Node* newNode = new Node{ product, year, nullptr };
        newNode->next = table[index];
        table[index] = newNode;
    }

    void deleteItem(int year) {
        int index = hashFunction(year);
        Node* temp = table[index];
        Node* prev = nullptr;

        if (temp != nullptr && temp->year == year) {
            table[index] = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->year != year) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void searchItem(int year) {
        int index = hashFunction(year);
        Node* entry = table[index];
        while (entry != nullptr) {
            if (entry->year == year) {
                cout << "�������� ������: " << entry->productName << ", ��� �������: " << entry->year << endl;
                return;
            }
            entry = entry->next;
        }
        cout << "�����, ���������� � " << year << " ����, �� ������." << endl;
    }

    void displayHash() {
        for (int i = 0; i < size; i++) {
            Node* entry = table[i];
            cout << i;
            while (entry != nullptr) {
                cout << " --> " << entry->productName << ":" << entry->year;
                entry = entry->next;
            }
            cout << endl;
        }
    }

    int hashFunction(int x) {
        return (x % size);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    cout << "������� ������ ���-�������: ";
    cin >> size;

    HashTable h(size);

    int choice, year;
    string product;

    while (true) {
        cout << "1 - ����� ���-�������" << endl;
        cout << "2 - ���������� ��������" << endl;
        cout << "3 - �������� ��������" << endl;
        cout << "4 - ����� ��������" << endl;
        cout << "0 - �����" << endl;
        cout << "�������� �����" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            h.displayHash();
            break;
        case 2:
            cout << "������� �������� ������ � ��� �������: ";
            cin >> product >> year;
            h.insertItem(product, year);
            break;
        case 3:
            cout << "������� ��� ������� ������ ��� ��������: ";
            cin >> year;
            h.deleteItem(year);
            break;
        case 4:
            cout << "������� ��� ������� ������ ��� ������: ";
            cin >> year;
            h.searchItem(year);
            break;
        case 0:
            return 0;
        default:
            cout << "�������� �����" << endl;
            break;
        }
    }

    return 0;
}
