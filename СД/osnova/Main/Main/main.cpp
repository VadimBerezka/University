#include <iostream>
#include <string>
#include <queue>
#include <locale>
#include <fstream>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int id;
    string firstName;
    string lastName;
    string patronymic;
    int course;
    string group;
    int subgroup;
    string subject;
    string teacherFirstName;
    string teacherLastName;
    bool attended;
};

queue<Student> studentsQueue;
Student studentsArray[MAX_STUDENTS];
int numStudents = 0;

void AddStudent() {
    if (numStudents >= MAX_STUDENTS) {
        cout << "Достигнуто максимальное количество студентов." << endl;
        return;
    }

    Student student;

    cout << "Введите ID студента: ";
    cin >> student.id;

    cout << "Введите имя студента: ";
    cin >> student.firstName;

    cout << "Введите фамилию студента: ";
    cin >> student.lastName;

    cout << "Введите отчество студента: ";
    cin >> student.patronymic;

    cout << "Введите курс студента: ";
    cin >> student.course;

    cout << "Введите группу студента: ";
    cin >> student.group;

    cout << "Введите подгруппу студента: ";
    cin >> student.subgroup;

    cout << "Введите название предмета: ";
    cin >> student.subject;

    cout << "Введите имя преподавателя: ";
    cin >> student.teacherFirstName;

    cout << "Введите фамилию преподавателя: ";
    cin >> student.teacherLastName;

    cout << "Посещал ли студент это занятие? (1 - да, 0 - нет): ";
    cin >> student.attended;

    studentsQueue.push(student);
    studentsArray[numStudents++] = student;

    cout << "Студент успешно добавлен!" << endl;
}

void DeleteStudent() {
    int studentId;
    cout << "Введите ID студента для удаления: ";
    cin >> studentId;

    // Поиск и удаление студента из очереди и массива
    bool found = false;

    queue<Student> tempQueue;
    int tempNumStudents = 0;

    for (int i = 0; i < numStudents; i++) {
        Student student = studentsQueue.front();
        studentsQueue.pop();

        if (student.id != studentId) {
            tempQueue.push(student);
            studentsArray[tempNumStudents++] = student;
        }
        else {
            found = true;
            cout << "Студент с ID " << studentId << " успешно удален!" << endl;
        }
    }

    studentsQueue = tempQueue;
    numStudents = tempNumStudents;

    if (!found) {
        cout << "Студент с ID " << studentId << " не найден!" << endl;
    }
}

void PrintStudent(const Student& student) {
    cout << "ID: " << student.id << endl;
    cout << "Имя: " << student.firstName << " " << student.lastName << " " << student.patronymic << endl;
    cout << "Курс: " << student.course << endl;
    cout << "Группа: " << student.group << endl;
    cout << "Подгруппа: " << student.subgroup << endl;
    cout << "Предмет: " << student.subject << endl;
    cout << "Преподаватель: " << student.teacherFirstName << " " << student.teacherLastName << endl;
    cout << "Посещал: " << (student.attended ? "Да" : "Нет") << endl;
}

void PrintStudentById() {
    int studentId;
    cout << "Введите ID студента для вывода информации: ";
    cin >> studentId;

    // Поиск студента по ID и вывод информации
    bool found = false;

    queue<Student> tempQueue;
    int tempNumStudents = 0;

    for (int i = 0; i < numStudents; i++) {
        Student student = studentsQueue.front();
        studentsQueue.pop();

        if (student.id == studentId) {
            found = true;
            PrintStudent(student);
        }

        tempQueue.push(student);
        studentsArray[tempNumStudents++] = student;
    }

    studentsQueue = tempQueue;
    numStudents = tempNumStudents;

    if (!found) {
        cout << "Студент с ID " << studentId << " не найден!" << endl;
    }
}

void SaveDataToFile() {
    string filename;
    cout << "Введите имя файла для сохранения данных: ";
    cin >> filename;

    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (int i = 0; i < numStudents; i++) {
            const Student& student = studentsArray[i];
            outputFile << "ID: " << student.id << endl;
            outputFile << "Имя: " << student.firstName << " " << student.lastName << " " << student.patronymic << endl;
            outputFile << "Курс: " << student.course << endl;
            outputFile << "Группа: " << student.group << endl;
            outputFile << "Подгруппа: " << student.subgroup << endl;
            outputFile << "Предмет: " << student.subject << endl;
            outputFile << "Преподаватель: " << student.teacherFirstName << " " << student.teacherLastName << endl;
            outputFile << "Посещал: " << (student.attended ? "Да" : "Нет") << endl;
            outputFile << endl;
        }

        outputFile.close();
        cout << "Данные успешно сохранены в файле " << filename << endl;
    }
    else {
        cout << "Ошибка открытия файла " << filename << " для записи." << endl;
    }
}

void ReadDataFromFile() {
    string filename;
    cout << "Введите имя файла для чтения данных: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            Student student;
            string line;

            // Считывание ID студента
            getline(inputFile, line);
            student.id = stoi(line.substr(line.find(":") + 2));

            // Считывание имени студента
            getline(inputFile, line);
            size_t spacePos = line.find(" ");
            student.firstName = line.substr(line.find(":") + 2, spacePos - line.find(":") - 2);
            size_t lastNamePos = spacePos + 1;
            spacePos = line.find(" ", lastNamePos);
            student.lastName = line.substr(lastNamePos, spacePos - lastNamePos);
            student.patronymic = line.substr(spacePos + 1);

            // Считывание курса, группы и подгруппы
            getline(inputFile, line);
            student.course = stoi(line.substr(line.find(":") + 2));
            getline(inputFile, line);
            student.group = line.substr(line.find(":") + 2);
            getline(inputFile, line);
            student.subgroup = stoi(line.substr(line.find(":") + 2));

            // Считывание названия предмета
            getline(inputFile, line);
            student.subject = line.substr(line.find(":") + 2);

            // Считывание имени и фамилии преподавателя
            getline(inputFile, line);
            spacePos = line.find(" ");
            student.teacherFirstName = line.substr(line.find(":") + 2, spacePos - line.find(":") - 2);
            student.teacherLastName = line.substr(spacePos + 1);

            // Считывание информации о посещении
            getline(inputFile, line);
            student.attended = (line.substr(line.find(":") + 2) == "Да");

            studentsQueue.push(student);
            studentsArray[numStudents++] = student;
        }

        inputFile.close();
        cout << "Данные успешно считаны из файла " << filename << endl;
    }
    else {
        cout << "Ошибка открытия файла " << filename << " для чтения." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Удалить студента" << endl;
        cout << "3. Вывести информацию о студенте по ID" << endl;
        cout << "4. Сохранить данные в файл" << endl;
        cout << "5. Загрузить данные из файла" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddStudent();
            break;
        case 2:
            DeleteStudent();
            break;
        case 3:
            PrintStudentById();
            break;
        case 4:
            SaveDataToFile();
            break;
        case 5:
            ReadDataFromFile();
            break;
        case 0:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}