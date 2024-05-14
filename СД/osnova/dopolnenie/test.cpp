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
