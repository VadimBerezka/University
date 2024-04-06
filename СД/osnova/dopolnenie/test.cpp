//void new_write() {
//	if (current_size_st < sizeS) {
//		cout << "\n Запись №" << current_size_st + 1 << ": ";
//
//		cout << "\n Введите название кафедры: ";
//		cin >> list_of_students[current_size_st].department;
//		ofstream file_department("department.txt", ios::app);
//		file_department << list_of_students[current_size_st].department << endl;
//		file_department.close();
//
//		cout << "\n Введите номер группы: ";
//		cin >> list_of_students[current_size_st].group;
//		ofstream file_group("group.txt", ios::app);
//		file_group << list_of_students[current_size_st].group << endl;
//		cout << "\n Введите номер подгруппы: ";
//		cin >> list_of_students[current_size_st].subgroup;
//		file_group << list_of_students[current_size_st].subgroup << endl;
//		file_group.close();
//
//		cout << "\n Введите имя: ";
//		cin >> list_of_students[current_size_st].student_name;
//		ofstream file_student_name("student_name.txt", ios::app);
//		file_student_name << list_of_students[current_size_st].student_name << " ";
//		cout << "\n Введите фамилию: ";
//		cin >> list_of_students[current_size_st].student_surname;
//		file_student_name << list_of_students[current_size_st].student_surname << endl;
//		file_student_name.close();
//
//		cout << "\n Введите название предмета: ";
//		cin >> list_of_students[current_size_st].subject_name;
//		ofstream file_subject_name("subject_name.txt", ios::app);
//		file_subject_name << list_of_students[current_size_st].subject_name << endl;
//		file_subject_name.close();
//
//		cout << "\n Введите имя преподавателя: ";
//		cin >> list_of_students[current_size_st].teacher_name;
//		ofstream file_teacher_name("teacher_name.txt", ios::app);
//		file_teacher_name << list_of_students[current_size_st].teacher_name << " ";
//		cout << "\n Введите фамилию преподавателя: ";
//		cin >> list_of_students[current_size_st].teacher_surname;
//		file_teacher_name << list_of_students[current_size_st].teacher_surname << endl;
//		file_teacher_name.close();
//
//		int attended;
//		do {
//			cout << "\n Посещал ли студент занятие (1 - да, 0 - нет): ";
//			cin >> attended;
//			if (attended != 1 && attended != 0) {
//				cout << "Некорректное значение. Пожалуйста, введите 1 (да) или 0 (нет).\n";
//			}
//		} while (attended != 1 && attended != 0);
//		list_of_students[current_size_st].attended = attended;
//		ofstream file_attended("attended.txt", ios::app);
//		file_attended << list_of_students[current_size_st].attended << endl;
//		file_attended.close();
//
//		current_size_st++;
//	}
//	else {
//		cout << " Введено максимальное кол-во строк" << endl;
//	}
//}



//void del_write()
//{
//	string filename;
//	cout << "Введите название файла, из которого нужно удалить информацию: ";
//	cin >> filename;
//
//	ifstream file(filename.c_str());
//	if (!file.good()) {
//		cout << "Файл " << filename << " не существует. Удаление невозможно.\n";
//		return;
//	}
//	file.close();
//
//	int d;
//	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
//	cin >> d;
//
//	if (d == -1) {
//		ofstream file(filename.c_str(), ios::trunc);
//		file.close();
//		cout << "Все строки удалены из файла " << filename << endl;
//	}
//	else {
//		string temp_filename = "temp.txt";
//		ofstream temp_file(temp_filename.c_str());
//		ifstream file(filename.c_str());
//
//		string line;
//		int line_number = 1;
//		while (getline(file, line)) {
//			if (line_number != d) {
//				temp_file << line << endl;
//			}
//			line_number++;
//		}
//
//		file.close();
//		temp_file.close();
//
//		remove(filename.c_str());
//		rename(temp_filename.c_str(), filename.c_str());
//
//		cout << "Строка " << d << " удалена из файла " << filename << endl;
//	}
//}
