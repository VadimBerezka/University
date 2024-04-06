#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool fileExists(const string& filename) {
    ifstream file(filename.c_str());
    return file.good();
}

void addLine(string filename, string line) {
    ofstream file(filename, ios_base::app);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����\n";
        return;
    }
    file << line << "\n";
    file.close();
}

void deleteLine(string filename, int lineNumber) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����\n";
        return;
    }
    ofstream temp("temp.txt");
    string line;
    int count = 0;

    while (getline(file, line)) {
        if (count != lineNumber)
            temp << line << "\n";
        count++;
    }

    file.close();
    temp.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

void editLine(string filename, int lineNumber, string newLine) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����\n";
        return;
    }
    ofstream temp("temp.txt");
    string line;
    int count = 0;

    while (getline(file, line)) {
        if (count == lineNumber)
            temp << newLine << "\n";
        else
            temp << line << "\n";
        count++;
    }

    file.close();
    temp.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

int main() {
    setlocale(LC_ALL, "rus");
    string filename;
    string line;
    int choice, lineNumber;
    cout << "������� ��� �����: ";
    getline(cin, filename);

    if (!fileExists(filename)) {
        cout << "������: ���� �� ������\n";
        return 0;
    }

    while (true) {
        cout << "1. �������� ������\n";
        cout << "2. ������� ������\n";
        cout << "3. ������������� ������\n";
        cout << "4. �����\n";
        cout << "������� ��� �����: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "������� �����������: ";
            getline(cin, line);
            addLine(filename, line);
            break;
        case 2:
            cout << "������� ����� ������ ��� ��������: ";
            cin >> lineNumber;
            cin.ignore();
            deleteLine(filename, lineNumber);
            break;
        case 3:
            cout << "������� ����� ������ ��� ��������������: ";
            cin >> lineNumber;
            cin.ignore();
            cout << "������� ����� ������: ";
            getline(cin, line);
            editLine(filename, lineNumber, line);
            break;
        case 4:
            cout << "����� �� ���������.\n";
            return 0;
        default:
            cout << "�������� �����. ����������, ���������� �����.\n";
        }
    }
    return 0;
}