#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

Queue* createQueue() {
    Queue* q = new Queue;
    q->front = q->rear = NULL;
    return q;
}

void addQueue(Queue* q, int data) {
    Node* node = newNode(data);

    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }   

    q->rear->next = node;
    q->rear = node;
}

void deleteQueue(Queue* q) {
    if (q->front == NULL)
        return;

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    delete temp;
}  

int sizeQueue(Queue* q) {
    int size = 0;
    Node* temp = q->front;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

void displayQueue(Queue* q) {
    if (q->front == NULL) {
        cout << "������� �����.\n";
        return;
    }

    cout << "�������� �������: ";
    Node* temp = q->front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void getMax(Queue* q) {
    if (q->front == NULL) {
        cout << "������� �����. ������������ ������� �� ������.\n";
        return;
    }

    int max = INT_MIN;
    Node* temp = q->front;
    while (temp != NULL) {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    cout << "������������ ������� � �������: " << max << endl;
}

void writeToFile(Queue* q) {
    ofstream file("queue.txt");
    Node* temp = q->front;
    while (temp != NULL) {
        file << temp->data << " ";
        temp = temp->next;
    }
    file.close();
    cout << "������� �������� � ����.\n";
}

void readFromFile(Queue* q) {
    ifstream file("queue.txt");
    int num;
    while (file >> num) {
        addQueue(q, num);
    }
    file.close();
    cout << "������� ������� �� �����.\n";
}

void deleteNQueue(Queue* q) {
    int size = sizeQueue(q);
    int n = min(size, 3);
    for (int i = 0; i < n; i++) {
        deleteQueue(q);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    Queue* q = createQueue();
    int choice = 0;

    while (choice != 8) {
        cout << "1. ������ �������� � �������\n";
        cout << "2. ������� ������� �� �������\n";
        cout << "3. ������� ������ �������\n";
        cout << "4. ������� �������� �������\n";
        cout << "5. ����� ������������ �������\n";
        cout << "6. �������� ������� � ����\n";
        cout << "7. ������� ������� �� �����\n";
        cout << "8. �����\n";
        cout << "9. �������� ������ n-�� ���������\n";
        cout << "������� ��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int num;
            cout << "������� �����: ";
            cin >> num;
            addQueue(q, num);
            break;
        }
        case 2: {
            deleteQueue(q);
            cout << "������ ������� ��� ������.\n";
            break;
        }
        case 3: {
            cout << "������ �������: " << sizeQueue(q) << endl;
            break;
        }
        case 4: {
            displayQueue(q);
            break;
        }
        case 5: {
            getMax(q);
            break;
        }
        case 6: {
            writeToFile(q);
            break;
        }
        case 7: {
            readFromFile(q);
            break;
        }
        case 8: {
            exit(0);
        }
        case 9: {
            deleteNQueue(q);
            break;
        }
        default: {
            cout << "�������� �����. ����������, ���������� �����.\n";
        }
        }
    }

    return 0;
}