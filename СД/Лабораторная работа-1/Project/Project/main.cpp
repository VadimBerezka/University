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
        cout << "Не удалось открыть файл\n";
        return;
    }
    file << line << "\n";
    file.close();
}

void deleteLine(string filename, int lineNumber) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл\n";
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
        cout << "Не удалось открыть файл\n";
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
    cout << "Введите имя файла: ";
    getline(cin, filename);

    if (!fileExists(filename)) {
        cout << "Ошибка: файл не найден\n";
        return 0;
    }

    while (true) {
        cout << "1. Добавить строку\n";
        cout << "2. Удалить строку\n";
        cout << "3. Редактировать строку\n";
        cout << "4. Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Введите предложение: ";
            getline(cin, line);
            addLine(filename, line);
            break;
        case 2:
            cout << "Введите номер строки для удаления: ";
            cin >> lineNumber;
            cin.ignore();
            deleteLine(filename, lineNumber);
            break;
        case 3:
            cout << "Введите номер строки для редактирования: ";
            cin >> lineNumber;
            cin.ignore();
            cout << "Введите новую строку: ";
            getline(cin, line);
            editLine(filename, lineNumber, line);
            break;
        case 4:
            cout << "Выход из программы.\n";
            return 0;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    }
    return 0;
}