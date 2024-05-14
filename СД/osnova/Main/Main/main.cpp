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
        cout << "���������� ������������ ���������� ���������." << endl;
        return;
    }

    Student student;

    cout << "������� ID ��������: ";
    cin >> student.id;

    cout << "������� ��� ��������: ";
    cin >> student.firstName;

    cout << "������� ������� ��������: ";
    cin >> student.lastName;

    cout << "������� �������� ��������: ";
    cin >> student.patronymic;

    cout << "������� ���� ��������: ";
    cin >> student.course;

    cout << "������� ������ ��������: ";
    cin >> student.group;

    cout << "������� ��������� ��������: ";
    cin >> student.subgroup;

    cout << "������� �������� ��������: ";
    cin >> student.subject;

    cout << "������� ��� �������������: ";
    cin >> student.teacherFirstName;

    cout << "������� ������� �������������: ";
    cin >> student.teacherLastName;

    cout << "������� �� ������� ��� �������? (1 - ��, 0 - ���): ";
    cin >> student.attended;

    studentsQueue.push(student);
    studentsArray[numStudents++] = student;

    cout << "������� ������� ��������!" << endl;
}

void DeleteStudent() {
    int studentId;
    cout << "������� ID �������� ��� ��������: ";
    cin >> studentId;

    // ����� � �������� �������� �� ������� � �������
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
            cout << "������� � ID " << studentId << " ������� ������!" << endl;
        }
    }

    studentsQueue = tempQueue;
    numStudents = tempNumStudents;

    if (!found) {
        cout << "������� � ID " << studentId << " �� ������!" << endl;
    }
}

void PrintStudent(const Student& student) {
    cout << "ID: " << student.id << endl;
    cout << "���: " << student.firstName << " " << student.lastName << " " << student.patronymic << endl;
    cout << "����: " << student.course << endl;
    cout << "������: " << student.group << endl;
    cout << "���������: " << student.subgroup << endl;
    cout << "�������: " << student.subject << endl;
    cout << "�������������: " << student.teacherFirstName << " " << student.teacherLastName << endl;
    cout << "�������: " << (student.attended ? "��" : "���") << endl;
}

void PrintStudentById() {
    int studentId;
    cout << "������� ID �������� ��� ������ ����������: ";
    cin >> studentId;

    // ����� �������� �� ID � ����� ����������
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
        cout << "������� � ID " << studentId << " �� ������!" << endl;
    }
}

void SaveDataToFile() {
    string filename;
    cout << "������� ��� ����� ��� ���������� ������: ";
    cin >> filename;

    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (int i = 0; i < numStudents; i++) {
            const Student& student = studentsArray[i];
            outputFile << "ID: " << student.id << endl;
            outputFile << "���: " << student.firstName << " " << student.lastName << " " << student.patronymic << endl;
            outputFile << "����: " << student.course << endl;
            outputFile << "������: " << student.group << endl;
            outputFile << "���������: " << student.subgroup << endl;
            outputFile << "�������: " << student.subject << endl;
            outputFile << "�������������: " << student.teacherFirstName << " " << student.teacherLastName << endl;
            outputFile << "�������: " << (student.attended ? "��" : "���") << endl;
            outputFile << endl;
        }

        outputFile.close();
        cout << "������ ������� ��������� � ����� " << filename << endl;
    }
    else {
        cout << "������ �������� ����� " << filename << " ��� ������." << endl;
    }
}

void ReadDataFromFile() {
    string filename;
    cout << "������� ��� ����� ��� ������ ������: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            Student student;
            string line;

            // ���������� ID ��������
            getline(inputFile, line);
            student.id = stoi(line.substr(line.find(":") + 2));

            // ���������� ����� ��������
            getline(inputFile, line);
            size_t spacePos = line.find(" ");
            student.firstName = line.substr(line.find(":") + 2, spacePos - line.find(":") - 2);
            size_t lastNamePos = spacePos + 1;
            spacePos = line.find(" ", lastNamePos);
            student.lastName = line.substr(lastNamePos, spacePos - lastNamePos);
            student.patronymic = line.substr(spacePos + 1);

            // ���������� �����, ������ � ���������
            getline(inputFile, line);
            student.course = stoi(line.substr(line.find(":") + 2));
            getline(inputFile, line);
            student.group = line.substr(line.find(":") + 2);
            getline(inputFile, line);
            student.subgroup = stoi(line.substr(line.find(":") + 2));

            // ���������� �������� ��������
            getline(inputFile, line);
            student.subject = line.substr(line.find(":") + 2);

            // ���������� ����� � ������� �������������
            getline(inputFile, line);
            spacePos = line.find(" ");
            student.teacherFirstName = line.substr(line.find(":") + 2, spacePos - line.find(":") - 2);
            student.teacherLastName = line.substr(spacePos + 1);

            // ���������� ���������� � ���������
            getline(inputFile, line);
            student.attended = (line.substr(line.find(":") + 2) == "��");

            studentsQueue.push(student);
            studentsArray[numStudents++] = student;
        }

        inputFile.close();
        cout << "������ ������� ������� �� ����� " << filename << endl;
    }
    else {
        cout << "������ �������� ����� " << filename << " ��� ������." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        cout << "����:" << endl;
        cout << "1. �������� ��������" << endl;
        cout << "2. ������� ��������" << endl;
        cout << "3. ������� ���������� � �������� �� ID" << endl;
        cout << "4. ��������� ������ � ����" << endl;
        cout << "5. ��������� ������ �� �����" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
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
            cout << "�� ��������!" << endl;
            break;
        default:
            cout << "������������ �����. ���������� �����." << endl;
            break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}