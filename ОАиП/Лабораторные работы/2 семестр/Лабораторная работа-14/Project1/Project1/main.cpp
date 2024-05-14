// 3 var
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int number;
    string directorSurname;
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

    void insertItem(int key, string value) {
        int index = hashFunction(key);
        Node* newNode = new Node{ key, value, nullptr };
        newNode->next = table[index];
        table[index] = newNode;
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        if (temp != nullptr && temp->number == key) {
            table[index] = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->number != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void searchItem(int key) {
        int index = hashFunction(key);
        Node* entry = table[index];
        while (entry != nullptr) {
            if (entry->number == key) {
                cout << "Номер школы: " << entry->number << ", Фамилия директора: " << entry->directorSurname << endl;
                return;
            }
            entry = entry->next;
        }
        cout << "Школа с номером " << key << " не найдена." << endl;
    }

    void displayHash() {
        for (int i = 0; i < size; i++) {
            Node* entry = table[i];
            cout << i;
            while (entry != nullptr) {
                cout << " --> " << entry->number << ":" << entry->directorSurname;
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
    cout << "Введите размер хеш-таблицы: ";
    cin >> size;

    HashTable h(size);

    int choice, key;
    string value;

    while (true) {
        cout << "1 - вывод хеш-таблицы" << endl;
        cout << "2 - добавление элемента" << endl;
        cout << "3 - удаление элемента" << endl;
        cout << "4 - поиск элемента" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            h.displayHash();
            break;
        case 2:
            cout << "Введите номер школы и фамилию директора: ";
            cin >> key >> value;
            h.insertItem(key, value);
            break;
        case 3:
            cout << "Введите номер школы для удаления: ";
            cin >> key;
            h.deleteItem(key);
            break;
        case 4:
            cout << "Введите номер школы для поиска: ";
            cin >> key;
            h.searchItem(key);
            break;
        case 0:
            return 0;
        default:
            cout << "Неверный выбор" << endl;
            break;
        }
    }

    return 0;
}
