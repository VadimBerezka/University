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
		cout << "\n1. Новая запись";
		cout << "\n2. Удалить запись";
		cout << "\n3. Вывести запись в консоль";
		cout << "\n4. Записать данные в файл";
		cout << "\n5. Прочитать данные из файла";
		cout << "\n6. Фильтрация по курсу";
		cout << "\n7. Сортировка";

		cout << "\n0.Завершить";
		cout << "\n(Введите выбор):";
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
	cout << "\nВведите номер пункта, по которому хотите отсортировать информацию:\n";
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
		cout << "0.Курс\n";
		cout << "1.Группа\n";
		cout << "2.Подгруппа\n";
		cout << "3.Курс(в обратном порядке)\n";
		cout << "4.Группа(в обратном порядке)\n";
		cout << "5.Подгруппа(в обратном порядке)\n";
		cout << "6.Полная сортировка\n";
		cout << "7.полная сортировка(в обратном порядке)\n";
		cout << "8.Выход из сортировки\n";
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
		cout << "Запись №";
		cout << i + 1;
		cout << ": Кафедра - ";
		cout << list_of_students[i].department;
		cout << ": Курс - ";
		cout << list_of_students[i].course;
		cout << ": Группа - ";
		cout << list_of_students[i].group;
		cout << ": Подгруппа - ";
		cout << list_of_students[i].subgroup;
		cout << " | Фамилия - ";
		cout << list_of_students[i].student_surname;
		cout << ": Имя - ";
		cout << list_of_students[i].student_name;
		cout << ": Отчество - ";
		cout << list_of_students[i].student_patronymic;
		cout << " | Предмет - ";
		cout << list_of_students[i].subject_name;
		cout << " | Фамилия преподавателя - ";
		cout << list_of_students[i].teacher_surname;
		cout << " | Имя преподавателя - ";
		cout << list_of_students[i].teacher_name;
		cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
		cout << list_of_students[i].attended;
		cout << endl;
	}
}

void new_write() {
	if (current_size_st < sizeS) {
		cout << "\n Запись №" << current_size_st + 1 << ": ";

		cout << "\n Введите название кафедры: ";
		cin >> list_of_students[current_size_st].department;
		ofstream file_department("department.txt", ios::app);
		file_department << list_of_students[current_size_st].department << endl;
		file_department.close();

		cout << "\n Введите номер курса: ";
		cin >> list_of_students[current_size_st].course;
		ofstream file_course("course.txt", ios::app);
		file_course << list_of_students[current_size_st].course << " ";

		cout << "\n Введите номер группы: ";
		cin >> list_of_students[current_size_st].group;
		file_course << list_of_students[current_size_st].group << " ";
		
		cout << "\n Введите номер подгруппы: ";
		cin >> list_of_students[current_size_st].subgroup;
		file_course << list_of_students[current_size_st].subgroup << endl;
		file_course.close();

		cout << "\n Введите фамилию: ";
		cin >> list_of_students[current_size_st].student_surname;
		ofstream file_student("student.txt", ios::app);
		file_student << list_of_students[current_size_st].student_surname << " ";

		cout << "\n Введите имя: ";
		cin >> list_of_students[current_size_st].student_name;
		file_student << list_of_students[current_size_st].student_name << " ";

		cout << "\n Введите отчество: ";
		cin >> list_of_students[current_size_st].student_patronymic;
		file_student << list_of_students[current_size_st].student_patronymic << endl;
		file_student.close();

		cout << "\n Введите название предмета: ";
		cin >> list_of_students[current_size_st].subject_name;
		ofstream file_subject_name("subject_name.txt", ios::app);
		file_subject_name << list_of_students[current_size_st].subject_name << endl;
		file_subject_name.close();

		cout << "\n Введите фамилию преподавателя: ";
		cin >> list_of_students[current_size_st].teacher_surname;
		ofstream file_teacher("teacher.txt", ios::app);
		file_teacher << list_of_students[current_size_st].teacher_surname << " ";

		cout << "\n Введите имя преподавателя: ";
		cin >> list_of_students[current_size_st].teacher_name;
		file_teacher << list_of_students[current_size_st].teacher_name << endl;
		file_teacher.close();

		int attended;
		do {
			cout << "\n Посещал ли студент занятие (1 - да, 0 - нет): ";
			cin >> attended;
			if (attended != 1 && attended != 0) {
				cout << "Некорректное значение. Пожалуйста, введите 1 (да) или 0 (нет).\n";
			}
		} while (attended != 1 && attended != 0);
		list_of_students[current_size_st].attended = attended;
		ofstream file_attended("attended.txt", ios::app);
		file_attended << list_of_students[current_size_st].attended << endl;
		file_attended.close();

		current_size_st++;
	}
	else {
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_write()
{
	string filename;
	cout << "Введите название файла, в котором нужно удалить или заменить информацию: ";
	cin >> filename;

	ifstream file(filename.c_str());
	if (!file.good()) {
		cout << "Файл " << filename << " не существует. Удаление или замена невозможна.\n";
		return;
	}
	file.close();

	int d;
	cout << " Номер строки, которую надо удалить или заменить(для удаления всех строк введите -1): ";
	cin >> d;

	string new_line;
	if (d != -1) {
		cout << "Введите новую строку для замены: ";
		cin.ignore();
		getline(cin, new_line);
	}

	if (d == -1) {
		ofstream file(filename.c_str(), ios::trunc);
		file.close();
		cout << "Все строки удалены из файла " << filename << endl;
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

		cout << "Строка " << d << " заменена в файле " << filename << endl;
	}
}

void out_write() {
	cout << "\nВведите номер пункта, по которому хотите найти информацию:\n";
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
		cout << "1.Кафедра\n";
		cout << "2.Курс\n";
		cout << "3.Группа\n";
		cout << "4.Имя студента\n";
		cout << "5.Фамилия студента\n";
		cout << "6.Название предмета\n";
		cout << "7.Имя преподавателя\n";
		cout << "8.Фамилия преподавателя\n";
		cout << "9.Вывести все записи\n";
		cout << "10.Выйти из поиска\n";
		cin >> ch;
		switch (ch) {
		case(0):
			cout << "Введите ID студента: ";
			cin >> IDstudent;
			if (IDstudent > current_size_st || IDstudent < 1) {
				cout << "Студента с таким ID не существует.\n";
			}
			else {
				int i = IDstudent - 1;
				cout << "Запись №";
				cout << IDstudent;
				cout << ": Кафедра - ";
				cout << list_of_students[i].department;
				cout << ": Группа - ";
				cout << list_of_students[i].group;
				cout << ": Подгруппа - ";
				cout << list_of_students[i].subgroup;
				cout << ": Имя - ";
				cout << list_of_students[i].student_name;
				cout << " | Фамилия - ";
				cout << list_of_students[i].student_surname;
				cout << " | Предмет - ";
				cout << list_of_students[i].subject_name;
				cout << " | Имя преподавателя - ";
				cout << list_of_students[i].teacher_name;
				cout << " | Фамилия преподавателя - ";
				cout << list_of_students[i].teacher_surname;
				cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
				cout << list_of_students[i].attended;
				cout << endl;
			}
			break;
		case(1):
			cout << "Введите кафедру:";
			cin >> department;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].department == department) {
					cout << "Запись №";
					cout << i + 1;
					cout << ": Кафедра - ";
					cout << list_of_students[i].department;
					cout << ": Курс - ";
					cout << list_of_students[i].course;
					cout << ": Группа - ";
					cout << list_of_students[i].group;
					cout << ": Подгруппа - ";
					cout << list_of_students[i].subgroup;
					cout << " | Фамилия - ";
					cout << list_of_students[i].student_surname;
					cout << ": Имя - ";
					cout << list_of_students[i].student_name;
					cout << ": Отчество - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | Предмет - ";
					cout << list_of_students[i].subject_name;
					cout << " | Фамилия преподавателя - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | Имя преподавателя - ";
					cout << list_of_students[i].teacher_name;
					cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(2):
			cout << "Введите курс:";
			cin >> course;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].course = course) {
					cout << "Запись №";
					cout << i + 1;
					cout << ": Кафедра - ";
					cout << list_of_students[i].department;
					cout << ": Курс - ";
					cout << list_of_students[i].course;
					cout << ": Группа - ";
					cout << list_of_students[i].group;
					cout << ": Подгруппа - ";
					cout << list_of_students[i].subgroup;
					cout << " | Фамилия - ";
					cout << list_of_students[i].student_surname;
					cout << ": Имя - ";
					cout << list_of_students[i].student_name;
					cout << ": Отчество - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | Предмет - ";
					cout << list_of_students[i].subject_name;
					cout << " | Фамилия преподавателя - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | Имя преподавателя - ";
					cout << list_of_students[i].teacher_name;
					cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(3):
			cout << "Введите группу:";
			cin >> group;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].group = group) {
					cout << "Запись №";
					cout << i + 1;
					cout << ": Кафедра - ";
					cout << list_of_students[i].department;
					cout << ": Курс - ";
					cout << list_of_students[i].course;
					cout << ": Группа - ";
					cout << list_of_students[i].group;
					cout << ": Подгруппа - ";
					cout << list_of_students[i].subgroup;
					cout << " | Фамилия - ";
					cout << list_of_students[i].student_surname;
					cout << ": Имя - ";
					cout << list_of_students[i].student_name;
					cout << ": Отчество - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | Предмет - ";
					cout << list_of_students[i].subject_name;
					cout << " | Фамилия преподавателя - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | Имя преподавателя - ";
					cout << list_of_students[i].teacher_name;
					cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			cout << "Хотите ли вы также искать по подгруппе? (1 - да, 0 - нет): ";
			int search_subgroup;
			cin >> search_subgroup;
			if (search_subgroup == 1) {
				cout << "Введите подгруппу:";
				cin >> subgroup;
				for (int i = 0; i < current_size_st; i++) {
					if (list_of_students[i].group == group && list_of_students[i].subgroup == subgroup) {
						cout << "Запись №";
						cout << i + 1;
						cout << ": Кафедра - ";
						cout << list_of_students[i].department;
						cout << ": Курс - ";
						cout << list_of_students[i].course;
						cout << ": Группа - ";
						cout << list_of_students[i].group;
						cout << ": Подгруппа - ";
						cout << list_of_students[i].subgroup;
						cout << " | Фамилия - ";
						cout << list_of_students[i].student_surname;
						cout << ": Имя - ";
						cout << list_of_students[i].student_name;
						cout << ": Отчество - ";
						cout << list_of_students[i].student_patronymic;
						cout << " | Предмет - ";
						cout << list_of_students[i].subject_name;
						cout << " | Фамилия преподавателя - ";
						cout << list_of_students[i].teacher_surname;
						cout << " | Имя преподавателя - ";
						cout << list_of_students[i].teacher_name;
						cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
						cout << list_of_students[i].attended;
						cout << endl;
					}
				}
			}
			break;

		case(4):
			cout << "Введите имя студента:";
			cin >> student_name;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].student_name == student_name) {
					cout << "Запись №";
					cout << i + 1;
					cout << ": Кафедра - ";
					cout << list_of_students[i].department;
					cout << ": Курс - ";
					cout << list_of_students[i].course;
					cout << ": Группа - ";
					cout << list_of_students[i].group;
					cout << ": Подгруппа - ";
					cout << list_of_students[i].subgroup;
					cout << " | Фамилия - ";
					cout << list_of_students[i].student_surname;
					cout << ": Имя - ";
					cout << list_of_students[i].student_name;
					cout << ": Отчество - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | Предмет - ";
					cout << list_of_students[i].subject_name;
					cout << " | Фамилия преподавателя - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | Имя преподавателя - ";
					cout << list_of_students[i].teacher_name;
					cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(5):
			cout << "Введите фамилию студента:";
			cin >> student_surname;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].student_surname == student_surname) {
					cout << "Запись №";
					cout << i + 1;
					cout << ": Кафедра - ";
					cout << list_of_students[i].department;
					cout << ": Курс - ";
					cout << list_of_students[i].course;
					cout << ": Группа - ";
					cout << list_of_students[i].group;
					cout << ": Подгруппа - ";
					cout << list_of_students[i].subgroup;
					cout << " | Фамилия - ";
					cout << list_of_students[i].student_surname;
					cout << ": Имя - ";
					cout << list_of_students[i].student_name;
					cout << ": Отчество - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | Предмет - ";
					cout << list_of_students[i].subject_name;
					cout << " | Фамилия преподавателя - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | Имя преподавателя - ";
					cout << list_of_students[i].teacher_name;
					cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(6):
			cout << "Введите название предмета:";
			cin >> subject_name;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].subject_name == subject_name) {
					cout << "Запись №";
					cout << i + 1;
					cout << ": Кафедра - ";
					cout << list_of_students[i].department;
					cout << ": Курс - ";
					cout << list_of_students[i].course;
					cout << ": Группа - ";
					cout << list_of_students[i].group;
					cout << ": Подгруппа - ";
					cout << list_of_students[i].subgroup;
					cout << " | Фамилия - ";
					cout << list_of_students[i].student_surname;
					cout << ": Имя - ";
					cout << list_of_students[i].student_name;
					cout << ": Отчество - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | Предмет - ";
					cout << list_of_students[i].subject_name;
					cout << " | Фамилия преподавателя - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | Имя преподавателя - ";
					cout << list_of_students[i].teacher_name;
					cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(7):
			cout << "Введите имя преподавателя:";
			cin >> teacher_name;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].teacher_name == teacher_name) {
					cout << "Запись №";
					cout << i + 1;
					cout << ": Кафедра - ";
					cout << list_of_students[i].department;
					cout << ": Курс - ";
					cout << list_of_students[i].course;
					cout << ": Группа - ";
					cout << list_of_students[i].group;
					cout << ": Подгруппа - ";
					cout << list_of_students[i].subgroup;
					cout << " | Фамилия - ";
					cout << list_of_students[i].student_surname;
					cout << ": Имя - ";
					cout << list_of_students[i].student_name;
					cout << ": Отчество - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | Предмет - ";
					cout << list_of_students[i].subject_name;
					cout << " | Фамилия преподавателя - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | Имя преподавателя - ";
					cout << list_of_students[i].teacher_name;
					cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(8):
			cout << "Введите фамилию преподавателя:";
			cin >> teacher_surname;
			for (int i = 0; i < current_size_st; i++) {
				if (list_of_students[i].teacher_surname == teacher_surname) {
					cout << "Запись №";
					cout << i + 1;
					cout << ": Кафедра - ";
					cout << list_of_students[i].department;
					cout << ": Курс - ";
					cout << list_of_students[i].course;
					cout << ": Группа - ";
					cout << list_of_students[i].group;
					cout << ": Подгруппа - ";
					cout << list_of_students[i].subgroup;
					cout << " | Фамилия - ";
					cout << list_of_students[i].student_surname;
					cout << ": Имя - ";
					cout << list_of_students[i].student_name;
					cout << ": Отчество - ";
					cout << list_of_students[i].student_patronymic;
					cout << " | Предмет - ";
					cout << list_of_students[i].subject_name;
					cout << " | Фамилия преподавателя - ";
					cout << list_of_students[i].teacher_surname;
					cout << " | Имя преподавателя - ";
					cout << list_of_students[i].teacher_name;
					cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
					cout << list_of_students[i].attended;
					cout << endl;
				}
			}
			break;

		case(9):
			for (int i = 0; i < current_size_st; i++) {
				cout << "Запись №";
				cout << i + 1;
				cout << ": Кафедра - ";
				cout << list_of_students[i].department;
				cout << ": Курс - ";
				cout << list_of_students[i].course;
				cout << ": Группа - ";
				cout << list_of_students[i].group;
				cout << ": Подгруппа - ";
				cout << list_of_students[i].subgroup;
				cout << " | Фамилия - ";
				cout << list_of_students[i].student_surname;
				cout << ": Имя - ";
				cout << list_of_students[i].student_name;
				cout << ": Отчество - ";
				cout << list_of_students[i].student_patronymic;
				cout << " | Предмет - ";
				cout << list_of_students[i].subject_name;
				cout << " | Фамилия преподавателя - ";
				cout << list_of_students[i].teacher_surname;
				cout << " | Имя преподавателя - ";
				cout << list_of_students[i].teacher_name;
				cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
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
		cout << "Запись данных в файл.\n";
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
		cout << "Данные успешно записаны в файл all_data.txt" << endl;
	}
	else {
		cout << "Не удалось открыть файл all_data.txt" << endl;
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
		cout << "Данные успешно считаны из файлов" << endl;
	}
	else {
		cout << "Не удалось открыть один или несколько файлов" << endl;
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
//		cout << "Данные успешно считаны из файлов" << endl;
//	}
//	else {
//		cout << "Не удалось открыть один или несколько файлов" << endl;
//	}
//}

void filter_by_course() {

	int lower_bound, upper_bound;
	int choice;
	cout << "Выберите тип фильтрации:\n";
	cout << "1. Диапазон курсов\n";
	cout << "2. Все курсы >=\n";
	cout << "3. Все курсы <=\n";
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "Введите нижнюю границу диапазона: ";
		cin >> lower_bound;
		cout << "Введите верхнюю границу диапазона: ";
		cin >> upper_bound;
		break;
	case 2:
		cout << "Введите число: ";
		cin >> lower_bound;
		upper_bound = 5;
		break;
	case 3:
		cout << "Введите число: ";
		cin >> upper_bound;
		lower_bound = 1;
		break;
	default:
		cout << "Неверный выбор.\n";
		return;
	}

	for (int i = 0; i < current_size_st; i++) {
		if (list_of_students[i].course >= lower_bound && list_of_students[i].course <= upper_bound) {
			cout << "Запись №";
			cout << i + 1;
			cout << ": Кафедра - ";
			cout << list_of_students[i].department;
			cout << ": Курс - ";
			cout << list_of_students[i].course;
			cout << ": Группа - ";
			cout << list_of_students[i].group;
			cout << ": Подгруппа - ";
			cout << list_of_students[i].subgroup;
			cout << " | Фамилия - ";
			cout << list_of_students[i].student_surname;
			cout << ": Имя - ";
			cout << list_of_students[i].student_name;
			cout << ": Отчество - ";
			cout << list_of_students[i].student_patronymic;
			cout << " | Предмет - ";
			cout << list_of_students[i].subject_name;
			cout << " | Фамилия преподавателя - ";
			cout << list_of_students[i].teacher_surname;
			cout << " | Имя преподавателя - ";
			cout << list_of_students[i].teacher_name;
			cout << " | Посещал ли студент занятие (1 - да, 0 - нет): ";
			cout << list_of_students[i].attended;
			cout << endl;
		}

	}
}	









