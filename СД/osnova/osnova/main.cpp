#include <iostream>
#include <string>
#define sizeS 50 
union AllStudents {
    char IDstudent[sizeS];
    char department[sizeS];
    char course[sizeS];
    char group[sizeS];
    char subgroup[sizeS];
    char student_name[sizeS];
    char student_surname[sizeS];
    char student_patronymic[sizeS];
    char subject_name[sizeS];
    char teacher_name[sizeS];
    char teacher_surname[sizeS];
} st;
struct Students {
    int IDstudent;
    std::string department;
    int course;
    int group;
    int subgroup;
    std::string student_name;
    std::string student_surname;
    std::string student_patronymic;
    std::string subject_name;
    std::string teacher_name;
    std::string teacher_surname;
    bool attended;
};

void bubbleSort(Students list_of_students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list_of_students[j].course > list_of_students[j + 1].course) {
                Students temp = list_of_students[j];
                list_of_students[j] = list_of_students[j + 1];
                list_of_students[j + 1] = temp;
            }
        }
    }
}

void printStudents(Students list_of_students[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Student ID: " << list_of_students[i].IDstudent << "\n";
        std::cout << "Department: " << list_of_students[i].department << "\n";
        std::cout << "Course: " << list_of_students[i].course << "\n";
        std::cout << "Group: " << list_of_students[i].group << "\n";
        std::cout << "Subgroup: " << list_of_students[i].subgroup << "\n";
        std::cout << "Name: " << list_of_students[i].student_name << "\n";
        std::cout << "Surname: " << list_of_students[i].student_surname << "\n";
        std::cout << "Patronymic: " << list_of_students[i].student_patronymic << "\n";
        std::cout << "Subject Name: " << list_of_students[i].subject_name << "\n";
        std::cout << "Teacher Name: " << list_of_students[i].teacher_name << "\n";
        std::cout << "Teacher Surname: " << list_of_students[i].teacher_surname << "\n";
        std::cout << "Attendance: " << (list_of_students[i].attended ? "Yes" : "No") << "\n\n";
    }
}
