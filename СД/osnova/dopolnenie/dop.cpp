#include <iostream>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

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
	string department;
	int course;
	int group;
	int subgroup;
	string student_name;
	string student_surname;
	string student_patronymic;
	string subject_name;
	string teacher_name;
	string teacher_surname;
	bool attended;
};

struct Students list_of_students[sizeS], free_student;
int current_size_st = 0;

void new_write();
void del_write();
void out_write();
void write_to_file();
void read_from_file();
void filter_by_course();
void bubbleCourseUp();
void bubbleGroupUp();
void bubbleSubgroupUp();
void bubbleCourseDown();
void bubbleGroupDown();
void bubbleSubgroupDown();
void bubbleSort();
void bubbleSortReverse();
void Sort();
void printStudents();

int main()
{
	setlocale(LC_CTYPE, "Rus");
	int choice = 1;

	while (choice != 0) {
		cout << "\n1. ����� ������";
		cout << "\n2. ������� ������";
		cout << "\n3. ������� ������ � �������";
		cout << "\n4. �������� ������ � ����";
		cout << "\n5. ��������� ������ �� �����";
		cout << "\n6. ���������� �� �����";
		cout << "\n7. ����������";

		cout << "\n0.���������";
		cout << "\n(������� �����):";
		cin >> choice;
		switch (choice) {
		case(1):
			new_write();
			break;

		case(2):
			del_write();
			break;

		case(3):
			out_write();
			break;

		case(4):
			write_to_file();
			break;

		case(5):
			read_from_file();
			break;
		case(6):
			filter_by_course();
			break;
		case(7):
			Sort();
			break;
		case(0):
			return 0;
		default:
			break;
		}
	}
	return 0;
}

void bubbleCourseUp() {
	for (int i = 0; i < current_size_st - 1; i++) {
		for (int j = 0; j < current_size_st - i - 1; j++) {
			if (list_of_students[j].course > list_of_students[j + 1].course) {
				Students temp = list_of_students[j];
				list_of_students[j] = list_of_students[j + 1];
				list_of_students[j + 1] = temp;
			}
		}
	}
}

void bubbleGroupUp() {
	for (int i = 0; i < current_size_st - 1; i++) {
		for (int j = 0; j < current_size_st - i - 1; j++) {
			if (list_of_students[j].group > list_of_students[j + 1].group) {
				Students temp = list_of_students[j];
				list_of_students[j] = list_of_students[j + 1];
				list_of_students[j + 1] = temp;
			}
		}
	}
}

void bubbleCourseDown() {
	for (int i = 0; i < current_size_st - 1; i++) {
		for (int j = 0; j < current_size_st - i - 1; j++) {
			if (list_of_students[j].course < list_of_students[j + 1].course) {
				Students temp = list_of_students[j];
				list_of_students[j] = list_of_students[j + 1];
				list_of_students[j + 1] = temp;
			}
		}
	}
}

void bubbleGroupDown() {
	for (int i = 0; i < current_size_st - 1; i++) {
		for (int j = 0; j < current_size_st - i - 1; j++) {
			if (list_of_students[j].group < list_of_students[j + 1].group) {
				Students temp = list_of_students[j];
				list_of_students[j] = list_of_students[j + 1];
				list_of_students[j + 1] = temp;
			}
		}
	}
}

void bubbleSubgroupDown() {
	for (int i = 0; i < current_size_st - 1; i++) {
		for (int j = 0; j < current_size_st - i - 1; j++) {
			if (list_of_students[j].subgroup > list_of_students[j + 1].subgroup) {
				Students temp = list_of_students[j];
				list_of_students[j] = list_of_students[j + 1];
				list_of_students[j + 1] = temp;
			}
		}
	}
}

void bubbleSubgroupUp() {
	for (int i = 0; i < current_size_st - 1; i++) {
		for (int j = 0; j < current_size_st - i - 1; j++) {
			if (list_of_students[j].subgroup < list_of_students[j + 1].subgroup) {
				Students temp = list_of_students[j];
				list_of_students[j] = list_of_students[j + 1];
				list_of_students[j + 1] = temp;
			}
		}
	}
}

void bubbleSort() {
	for (int i = 0; i < current_size_st - 1; i++) {
		for (int j = 0; j < current_size_st - i - 1; j++) {
			if (list_of_students[j].course > list_of_students[j + 1].course ||
				(list_of_students[j].course == list_of_students[j + 1].course && list_of_students[j].group > list_of_students[j + 1].group) ||
				(list_of_students[j].course == list_of_students[j + 1].course && list_of_students[j].group == list_of_students[j + 1].group && list_of_students[j].subgroup > list_of_students[j + 1].subgroup)) {
				Students temp = list_of_students[j];
				list_of_students[j] = list_of_students[j + 1];
				list_of_students[j + 1] = temp;
			}
		}
	}
}

void bubbleSortReverse() {
	for (int i = 0; i < current_size_st - 1; i++) {
		for (int j = 0; j < current_size_st - i - 1; j++) {
			if (list_of_students[j].course < list_of_students[j + 1].course ||
				(list_of_students[j].course == list_of_students[j + 1].course && list_of_students[j].group < list_of_students[j + 1].group) ||
				(list_of_students[j].course == list_of_students[j + 1].course && list_of_students[j].group == list_of_students[j + 1].group && list_of_students[j].subgroup < list_of_students[j + 1].subgroup)) {
				Students temp = list_of_students[j];
				list_of_students[j] = list_of_students[j + 1];
				list_of_students[j + 1] = temp;
			}
		}
	}
}

void Sort() {
	cout << "\n������� ����� ������, �� �������� ������ ������������� ����������:\n";
	int ch = 1;
	int IDstudent;
	string department;
	int course;
	int group;
	int subgroup;
	string student_name;
	string student_surname;
	string student_patronymic;
	string subject_name;
	string teacher_name;
	string teacher_surname;
	bool attended;
	while (ch != 8) {
		cout << "0.����\n";
		cout << "1.������\n";
		cout << "2.���������\n";
		cout << "3.����(� �������� �������)\n";
		cout << "4.������(� �������� �������)\n";
		cout << "5.���������(� �������� �������)\n";
		cout << "6.������ ����������\n";
		cout << "7.������ ����������(� �������� �������)\n";
		cout << "8.����� �� ����������\n";
		cin >> ch;
		switch (ch) {
		case(0):
			bubbleCourseUp();
			printStudents();
			break;
		case(1):
			bubbleGroupUp();
			printStudents();
			break;
		case(2):
			bubbleSubgroupDown();
			printStudents();
			break;
		case(3):
			bubbleCourseDown();
			printStudents();
			break;
		case(4):
			bubbleGroupDown();
			printStudents();
			break;
		case(5):
			bubbleSubgroupUp();
			printStudents();
			break;
		case(6):
			bubbleSort();
			printStudents();
			break;
		case(7):
			bubbleSortReverse();
			printStudents();
			break;
		case(8):
			main();
			break;

		}
	}
}

void printStudents() {
	for (int i = 0; i < current_size_st; i++) {
		cout << "������ �";
		cout << i + 1;
		cout << ": ������� - ";
		cout << list_of_students[i].department;
		cout << ": ���� - ";
		cout << list_of_students[i].course;
		cout << ": ������ - ";
		cout << list_of_students[i].group;
		cout << ": ��������� - ";
		cout << list_of_students[i].subgroup;
		cout << " | ������� - ";
		cout << list_of_students[i].student_surname;
		cout << ": ��� - ";
		cout << list_of_students[i].student_name;
		cout << ": �������� - ";
		cout << list_of_students[i].student_patronymic;
		cout << " | ������� - ";
		cout << list_of_students[i].subject_name;
		cout << " | ������� ������������� - ";
		cout << list_of_students[i].teacher_surname;
		cout << " | ��� ������������� - ";
		cout << list_of_students[i].teacher_name;
		cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
		cout << list_of_students[i].attended;
		cout << endl;
	}
}

void new_write() {
	if (current_size_st < sizeS) {
		cout << "\n ������ �" << current_size_st + 1 << ": ";

		cout << "\n ������� �������� �������: ";
		cin >> list_of_students[current_size_st].department;
		ofstream file_department("department.txt", ios::app);
		file_department << list_of_students[current_size_st].department << endl;
		file_department.close();

		cout << "\n ������� ����� �����: ";
		cin >> list_of_students[current_size_st].course;
		ofstream file_course("course.txt", ios::app);
		file_course << list_of_students[current_size_st].course << " ";

		cout << "\n ������� ����� ������: ";
		cin >> list_of_students[current_size_st].group;
		file_course << list_of_students[current_size_st].group << " ";
		
		cout << "\n ������� ����� ���������: ";
		cin >> list_of_students[current_size_st].subgroup;
		file_course << list_of_students[current_size_st].subgroup << endl;
		file_course.close();

		cout << "\n ������� �������: ";
		cin >> list_of_students[current_size_st].student_surname;
		ofstream file_student("student.txt", ios::app);
		file_student << list_of_students[current_size_st].student_surname << " ";

		cout << "\n ������� ���: ";
		cin >> list_of_students[current_size_st].student_name;
		file_student << list_of_students[current_size_st].student_name << " ";

		cout << "\n ������� ��������: ";
		cin >> list_of_students[current_size_st].student_patronymic;
		file_student << list_of_students[current_size_st].student_patronymic << endl;
		file_student.close();

		cout << "\n ������� �������� ��������: ";
		cin >> list_of_students[current_size_st].subject_name;
		ofstream file_subject_name("subject_name.txt", ios::app);
		file_subject_name << list_of_students[current_size_st].subject_name << endl;
		file_subject_name.close();

		cout << "\n ������� ������� �������������: ";
		cin >> list_of_students[current_size_st].teacher_surname;
		ofstream file_teacher("teacher.txt", ios::app);
		file_teacher << list_of_students[current_size_st].teacher_surname << " ";

		cout << "\n ������� ��� �������������: ";
		cin >> list_of_students[current_size_st].teacher_name;
		file_teacher << list_of_students[current_size_st].teacher_name << endl;
		file_teacher.close();

		int attended;
		do {
			cout << "\n ������� �� ������� ������� (1 - ��, 0 - ���): ";
			cin >> attended;
			if (attended != 1 && attended != 0) {
				cout << "������������ ��������. ����������, ������� 1 (��) ��� 0 (���).\n";
			}
		} while (attended != 1 && attended != 0);
		list_of_students[current_size_st].attended = attended;
		ofstream file_attended("attended.txt", ios::app);
		file_attended << list_of_students[current_size_st].attended << endl;
		file_attended.close();

		current_size_st++;
	}
	else {
		cout << " ������� ������������ ���-�� �����" << endl;
	}
}

void del_write()
{
	string filename;
	cout << "������� �������� �����, � ������� ����� ������� ��� �������� ����������: ";
	cin >> filename;

	ifstream file(filename.c_str());
	if (!file.good()) {
		cout << "���� " << filename << " �� ����������. �������� ��� ������ ����������.\n";
		return;
	}
	file.close();

	int d;
	cout << " ����� ������, ������� ���� ������� ��� ��������(��� �������� ���� ����� ������� -1): ";
	cin >> d;

	string new_line;
	if (d != -1) {
		cout << "������� ����� ������ ��� ������: ";
		cin.ignore();
		getline(cin, new_line);
	}

	if (d == -1) {
		ofstream file(filename.c_str(), ios::trunc);
		file.close();
		cout << "��� ������ ������� �� ����� " << filename << endl;
	}
	else {
		string temp_filename = "temp.txt";
		ofstream temp_file(temp_filename.c_str());
		ifstream file(filename.c_str());

		string line;
		int line_number = 1;
		while (getline(file, line)) {
			if (line_number != d) {
				temp_file << line << endl;
			}
			else {
				temp_file << new_line << endl;
			}
			line_number++;
		}

		file.close();
		temp_file.close();

		remove(filename.c_str());
		rename(temp_filename.c_str(), filename.c_str());

		cout << "������ " << d << " �������� � ����� " << filename << endl;
	}
}

void out_write() {
	cout << "\n������� ����� ������, �� �������� ������ ����� ����������:\n";
	int ch = 1;
	int IDstudent;
	string department;
	int course;
	int group;
	int subgroup;
	string student_name;
	string student_surname;
	string student_patronymic;
	string subject_name;
	string teacher_name;
	string teacher_surname;
	bool attended;
	while (ch != 10) {
		cout << "0.ID\n";
		cout << "1.�������\n";
		cout << "2.����\n";
		cout << "3.������\n";
		cout << "4.��� ��������\n";
		cout << "5.������� ��������\n";
		cout << "6.�������� ��������\n";
		cout << "7.��� �������������\n";
		cout << "8.������� �������������\n";
		cout << "9.������� ��� ������\n";
		cout << "10.����� �� ������\n";
		cin >> ch;
		switch (ch) {
		case(0):
			cout << "������� ID ��������: ";
			cin >> IDstudent;
			if (IDstudent > current_size_st || IDstudent < 1) {
				cout << "�������� � ����� ID �� ����������.\n";
			}
			else {
				int i = IDstudent - 1;
				cout << "������ �";
				cout << IDstudent;
				cout << ": ������� - ";
				cout << list_of_students[i].department;
				cout << ": ������ - ";
				cout << list_of_students[i].group;
				cout << ": ��������� - ";
				cout << list_of_students[i].subgroup;
				cout << ": ��� - ";
				cout << list_of_students[i].student_name;
				cout << " | ������� - ";
				cout << list_of_students[i].student_surname;
				cout << " | ������� - ";
				cout << list_of_students[i].subject_name;
				cout << " | ��� ������������� - ";
				cout << list_of_students[i].teacher_name;
				cout << " | ������� ������������� - ";
				cout << list_of_students[i].teacher_surname;
				cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
				cout << list_of_students[i].attended;
				cout << endl;
			}
			break;
		case(1):
			cout << "������� �������:";
			cin >> department;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].department == department) {
					cout << "������ �";
					cout << i + 1;
					cout << ": ������� - ";
					cout << list_of_students[i].department;
					cout << ": ���� - ";
					cout << list_of_students[i].course;
					cout << ": ������ - ";
					cout << list_of_students[i].group;
					cout << ": ��������� - ";
					cout << list_of_students[i].subgroup;
					cout << " | ������� - ";
					cout << list_of_students[i].student_surname;
					cout << ": ��� - ";
					cout << list_of_students[i].student_name;
					cout << ": �������� - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | ������� - ";
					cout << list_of_students[i].subject_name;
					cout << " | ������� ������������� - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | ��� ������������� - ";
					cout << list_of_students[i].teacher_name;
					cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(2):
			cout << "������� ����:";
			cin >> course;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].course = course) {
					cout << "������ �";
					cout << i + 1;
					cout << ": ������� - ";
					cout << list_of_students[i].department;
					cout << ": ���� - ";
					cout << list_of_students[i].course;
					cout << ": ������ - ";
					cout << list_of_students[i].group;
					cout << ": ��������� - ";
					cout << list_of_students[i].subgroup;
					cout << " | ������� - ";
					cout << list_of_students[i].student_surname;
					cout << ": ��� - ";
					cout << list_of_students[i].student_name;
					cout << ": �������� - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | ������� - ";
					cout << list_of_students[i].subject_name;
					cout << " | ������� ������������� - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | ��� ������������� - ";
					cout << list_of_students[i].teacher_name;
					cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(3):
			cout << "������� ������:";
			cin >> group;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].group = group) {
					cout << "������ �";
					cout << i + 1;
					cout << ": ������� - ";
					cout << list_of_students[i].department;
					cout << ": ���� - ";
					cout << list_of_students[i].course;
					cout << ": ������ - ";
					cout << list_of_students[i].group;
					cout << ": ��������� - ";
					cout << list_of_students[i].subgroup;
					cout << " | ������� - ";
					cout << list_of_students[i].student_surname;
					cout << ": ��� - ";
					cout << list_of_students[i].student_name;
					cout << ": �������� - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | ������� - ";
					cout << list_of_students[i].subject_name;
					cout << " | ������� ������������� - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | ��� ������������� - ";
					cout << list_of_students[i].teacher_name;
					cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			cout << "������ �� �� ����� ������ �� ���������? (1 - ��, 0 - ���): ";
			int search_subgroup;
			cin >> search_subgroup;
			if (search_subgroup == 1) {
				cout << "������� ���������:";
				cin >> subgroup;
				for (int i = 0; i < current_size_st; i++) {
					if (list_of_students[i].group == group && list_of_students[i].subgroup == subgroup) {
						cout << "������ �";
						cout << i + 1;
						cout << ": ������� - ";
						cout << list_of_students[i].department;
						cout << ": ���� - ";
						cout << list_of_students[i].course;
						cout << ": ������ - ";
						cout << list_of_students[i].group;
						cout << ": ��������� - ";
						cout << list_of_students[i].subgroup;
						cout << " | ������� - ";
						cout << list_of_students[i].student_surname;
						cout << ": ��� - ";
						cout << list_of_students[i].student_name;
						cout << ": �������� - ";
						cout << list_of_students[i].student_patronymic;
						cout << " | ������� - ";
						cout << list_of_students[i].subject_name;
						cout << " | ������� ������������� - ";
						cout << list_of_students[i].teacher_surname;
						cout << " | ��� ������������� - ";
						cout << list_of_students[i].teacher_name;
						cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
						cout << list_of_students[i].attended;
						cout << endl;
					}
				}
			}
			break;

		case(4):
			cout << "������� ��� ��������:";
			cin >> student_name;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].student_name == student_name) {
					cout << "������ �";
					cout << i + 1;
					cout << ": ������� - ";
					cout << list_of_students[i].department;
					cout << ": ���� - ";
					cout << list_of_students[i].course;
					cout << ": ������ - ";
					cout << list_of_students[i].group;
					cout << ": ��������� - ";
					cout << list_of_students[i].subgroup;
					cout << " | ������� - ";
					cout << list_of_students[i].student_surname;
					cout << ": ��� - ";
					cout << list_of_students[i].student_name;
					cout << ": �������� - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | ������� - ";
					cout << list_of_students[i].subject_name;
					cout << " | ������� ������������� - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | ��� ������������� - ";
					cout << list_of_students[i].teacher_name;
					cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(5):
			cout << "������� ������� ��������:";
			cin >> student_surname;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].student_surname == student_surname) {
					cout << "������ �";
					cout << i + 1;
					cout << ": ������� - ";
					cout << list_of_students[i].department;
					cout << ": ���� - ";
					cout << list_of_students[i].course;
					cout << ": ������ - ";
					cout << list_of_students[i].group;
					cout << ": ��������� - ";
					cout << list_of_students[i].subgroup;
					cout << " | ������� - ";
					cout << list_of_students[i].student_surname;
					cout << ": ��� - ";
					cout << list_of_students[i].student_name;
					cout << ": �������� - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | ������� - ";
					cout << list_of_students[i].subject_name;
					cout << " | ������� ������������� - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | ��� ������������� - ";
					cout << list_of_students[i].teacher_name;
					cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(6):
			cout << "������� �������� ��������:";
			cin >> subject_name;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].subject_name == subject_name) {
					cout << "������ �";
					cout << i + 1;
					cout << ": ������� - ";
					cout << list_of_students[i].department;
					cout << ": ���� - ";
					cout << list_of_students[i].course;
					cout << ": ������ - ";
					cout << list_of_students[i].group;
					cout << ": ��������� - ";
					cout << list_of_students[i].subgroup;
					cout << " | ������� - ";
					cout << list_of_students[i].student_surname;
					cout << ": ��� - ";
					cout << list_of_students[i].student_name;
					cout << ": �������� - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | ������� - ";
					cout << list_of_students[i].subject_name;
					cout << " | ������� ������������� - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | ��� ������������� - ";
					cout << list_of_students[i].teacher_name;
					cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(7):
			cout << "������� ��� �������������:";
			cin >> teacher_name;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].teacher_name == teacher_name) {
					cout << "������ �";
					cout << i + 1;
					cout << ": ������� - ";
					cout << list_of_students[i].department;
					cout << ": ���� - ";
					cout << list_of_students[i].course;
					cout << ": ������ - ";
					cout << list_of_students[i].group;
					cout << ": ��������� - ";
					cout << list_of_students[i].subgroup;
					cout << " | ������� - ";
					cout << list_of_students[i].student_surname;
					cout << ": ��� - ";
					cout << list_of_students[i].student_name;
					cout << ": �������� - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | ������� - ";
					cout << list_of_students[i].subject_name;
					cout << " | ������� ������������� - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | ��� ������������� - ";
					cout << list_of_students[i].teacher_name;
					cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(8):
			cout << "������� ������� �������������:";
			cin >> teacher_surname;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].teacher_surname == teacher_surname) {
					cout << "������ �";
					cout << i + 1;
					cout << ": ������� - ";
					cout << list_of_students[i].department;
					cout << ": ���� - ";
					cout << list_of_students[i].course;
					cout << ": ������ - ";
					cout << list_of_students[i].group;
					cout << ": ��������� - ";
					cout << list_of_students[i].subgroup;
					cout << " | ������� - ";
					cout << list_of_students[i].student_surname;
					cout << ": ��� - ";
					cout << list_of_students[i].student_name;
					cout << ": �������� - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | ������� - ";
					cout << list_of_students[i].subject_name;
					cout << " | ������� ������������� - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | ��� ������������� - ";
					cout << list_of_students[i].teacher_name;
					cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(9):
			for (int i = 0; i < current_size_st; i++) {
				cout << "������ �";
				cout << i + 1;
				cout << ": ������� - ";
				cout << list_of_students[i].department;
				cout << ": ���� - ";
				cout << list_of_students[i].course;
				cout << ": ������ - ";
				cout << list_of_students[i].group;
				cout << ": ��������� - ";
				cout << list_of_students[i].subgroup;
				cout << " | ������� - ";
				cout << list_of_students[i].student_surname;
				cout << ": ��� - ";
				cout << list_of_students[i].student_name;
				cout << ": �������� - ";
				cout << list_of_students[i].student_patronymic;
				cout << " | ������� - ";
				cout << list_of_students[i].subject_name;
				cout << " | ������� ������������� - ";
				cout << list_of_students[i].teacher_surname;
				cout << " | ��� ������������� - ";
				cout << list_of_students[i].teacher_name;
				cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
				cout << list_of_students[i].attended;
				cout << endl;
			}
			break;

		case(10):
			main();
			break;

		default:
			break;
		}
	}
}

void write_to_file() {
	ofstream file("all_data.txt");
	if (file.is_open()) {
		cout << "������ ������ � ����.\n";
		for (int i = 0; i < current_size_st; i++) {
			file << list_of_students[i].department << " "
				<< list_of_students[i].course << " "
				<< list_of_students[i].group << " "
				<< list_of_students[i].subgroup << " "
				<< list_of_students[i].student_surname << " "
				<< list_of_students[i].student_name << " "
				<< list_of_students[i].student_patronymic << " "
				<< list_of_students[i].subject_name << " "
				<< list_of_students[i].teacher_surname << " "
				<< list_of_students[i].teacher_name << " "
				<< list_of_students[i].attended << "\n";
		}
		file.close();
		cout << "������ ������� �������� � ���� all_data.txt" << endl;
	}
	else {
		cout << "�� ������� ������� ���� all_data.txt" << endl;
	}
}

void read_from_file() {
	ifstream file_department("department.txt");
	ifstream file_course("course.txt");
	ifstream file_student("student.txt");
	ifstream file_subject_name("subject_name.txt");
	ifstream file_teacher("teacher.txt");
	ifstream file_attended("attended.txt");

	if (file_department.is_open() && file_course.is_open() && file_student.is_open() && file_subject_name.is_open() &&
		file_teacher.is_open() && file_attended.is_open()) {
		int i = 0;
		while (file_department >> list_of_students[i].department &&
			file_course >> list_of_students[i].course >> list_of_students[i].group >> list_of_students[i].subgroup &&
			file_student >> list_of_students[i].student_surname >> list_of_students[i].student_name >> list_of_students[i].student_patronymic &&
			file_subject_name >> list_of_students[i].subject_name &&
			file_teacher >> list_of_students[i].teacher_surname >> list_of_students[i].teacher_name &&
			file_attended >> list_of_students[i].attended) {
			i++;
		}
		current_size_st = i;
		file_department.close();
		file_course.close();
		file_student.close();
		file_subject_name.close();
		file_teacher.close();
		file_attended.close();
		cout << "������ ������� ������� �� ������" << endl;
	}
	else {
		cout << "�� ������� ������� ���� ��� ��������� ������" << endl;
	}
}

//void read_from_file() {
//	ifstream file_all_data("all_data.txt");
//
//	if (file_all_data.is_open()) {
//		int i = 0;
//		while (file_all_data >> list_of_students[i].department &&
//			file_all_data >> list_of_students[i].course >> list_of_students[i].group >> list_of_students[i].subgroup &&
//			file_all_data >> list_of_students[i].student_surname >> list_of_students[i].student_name >> list_of_students[i].student_patronymic &&
//			file_all_data >> list_of_students[i].subject_name &&
//			file_all_data >> list_of_students[i].teacher_surname >> list_of_students[i].teacher_name &&
//			file_all_data >> list_of_students[i].attended) {
//			i++;
//		}
//		current_size_st = i;
//		file_all_data.close();
//		cout << "������ ������� ������� �� ������" << endl;
//	}
//	else {
//		cout << "�� ������� ������� ���� ��� ��������� ������" << endl;
//	}
//}

void filter_by_course() {

	int lower_bound, upper_bound;
	int choice;
	cout << "�������� ��� ����������:\n";
	cout << "1. �������� ������\n";
	cout << "2. ��� ����� >=\n";
	cout << "3. ��� ����� <=\n";
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "������� ������ ������� ���������: ";
		cin >> lower_bound;
		cout << "������� ������� ������� ���������: ";
		cin >> upper_bound;
		break;
	case 2:
		cout << "������� �����: ";
		cin >> lower_bound;
		upper_bound = 5;
		break;
	case 3:
		cout << "������� �����: ";
		cin >> upper_bound;
		lower_bound = 1;
		break;
	default:
		cout << "�������� �����.\n";
		return;
	}

	for (int i = 0; i < current_size_st; i++) {
		if (list_of_students[i].course >= lower_bound && list_of_students[i].course <= upper_bound) {
			cout << "������ �";
			cout << i + 1;
			cout << ": ������� - ";
			cout << list_of_students[i].department;
			cout << ": ���� - ";
			cout << list_of_students[i].course;
			cout << ": ������ - ";
			cout << list_of_students[i].group;
			cout << ": ��������� - ";
			cout << list_of_students[i].subgroup;
			cout << " | ������� - ";
			cout << list_of_students[i].student_surname;
			cout << ": ��� - ";
			cout << list_of_students[i].student_name;
			cout << ": �������� - ";
			cout << list_of_students[i].student_patronymic;
			cout << " | ������� - ";
			cout << list_of_students[i].subject_name;
			cout << " | ������� ������������� - ";
			cout << list_of_students[i].teacher_surname;
			cout << " | ��� ������������� - ";
			cout << list_of_students[i].teacher_name;
			cout << " | ������� �� ������� ������� (1 - ��, 0 - ���): ";
			cout << list_of_students[i].attended;
			cout << endl;
		}

	}
}	









