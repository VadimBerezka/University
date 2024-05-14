// 4 var
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string bookName;
    int bookNumber;
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

    void insertItem(string book, int number) {
        int index = hashFunction(number);
        Node* newNode = new Node{ book, number, nullptr };
        newNode->next = table[index];
        table[index] = newNode;
    }

    void deleteItem(int number) {
        int index = hashFunction(number);
        Node* temp = table[index];
        Node* prev = nullptr;

        if (temp != nullptr && temp->bookNumber == number) {
            table[index] = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->bookNumber != number) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void searchItem(int number) {
        int index = hashFunction(number);
        Node* entry = table[index];
        while (entry != nullptr) {
            if (entry->bookNumber == number) {
                cout << "�������� �����: " << entry->bookName << ", ����� �����: " << entry->bookNumber << endl;
                return;
            }
            entry = entry->next;
        }
        cout << "����� � ������� " << number << " �� �������." << endl;
    }

    void displayHash() {
        for (int i = 0; i < size; i++) {
            Node* entry = table[i];
            cout << i;
            while (entry != nullptr) {
                cout << " --> " << entry->bookName << ":" << entry->bookNumber;
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

    int choice, number;
    string book;

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
            cout << "������� �������� ����� � ����� �����: ";
            cin >> book >> number;
            h.insertItem(book, number);
            break;
        case 3:
            cout << "������� ����� ����� ��� ��������: ";
            cin >> number;
            h.deleteItem(number);
            break;
        case 4:
            cout << "������� ����� ����� ��� ������: ";
            cin >> number;
            h.searchItem(number);
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
