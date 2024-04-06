#include <iostream>
#include <fstream>

# define str_len 30                               

using namespace std;

void input(int size);
void output();
void find(char* account_num);
void delete_line(int line_number);

struct Clients
{
	char name[str_len];
	char surname[str_len];
	char patronymic[str_len];
	char account_type[str_len];
	char account_num[str_len];
	double sum;
	char data[str_len];
};
int number;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	char account_num[str_len];
	int line_number;

	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по номеру счета\n";
		cout << "4.Удалить строку\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Введите количество клиентов: ";
			cin >> number;
			input(number);
			break;

		case 2:
			output();
			break;

		case 3:
			cout << "Введите номер счета: ";
			cin >> account_num;
			find(account_num);
			break;

		case 4:
			cout << "Введите номер строки для удаления: ";
			cin >> line_number;
			delete_line(line_number);
			break;

		case 0:
			exit(0);
			break;
		}

	} while (choice != 0);
}


void input(int size)
{
	fstream f;
	Clients buf;
	f.open("base.txt", ios::out | ios::app);

	if (f.is_open())
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Имя: ";
			cin >> buf.name;

			cout << "Фамилия: ";
			cin >> buf.surname;

			cout << "Отчество: ";
			cin >> buf.patronymic;

			cout << "Тип счета: ";
			cin >> buf.account_type;

			cout << "Номер счета: ";
			cin >> buf.account_num;

			cout << "Сумма на счете: ";
			cin >> buf.sum;

			cout << "Дата последнего изменения: ";
			cin >> buf.data;

			f << buf.name << " " << buf.surname << " " << buf.patronymic << " " << buf.account_type << " " << buf.account_num << " " << buf.sum << " " << buf.data << "\n";
		}

		f.close();
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	fstream f;
	Clients buf;
	f.open("base.txt", ios::in);

	if (f.is_open())
	{
		cout << "\nИмя\t Фамилия\t Отчество\t Тип счета\t Номер счета\t Баланс счета\t Дата изменения\n";
		while (f >> buf.name >> buf.surname >> buf.patronymic >> buf.account_type >> buf.account_num >> buf.sum >> buf.data)
		{
			cout << buf.name << "\t " << buf.surname << "\t " << buf.patronymic << "\t " << buf.account_type << "\t " << buf.account_num << "\t " << buf.sum << "\t " << buf.data << "\n";
		}
		cout << endl;
		f.close();
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void find(char* account_num)
{
	fstream f;
	bool flag = false;
	Clients buf;
	f.open("base.txt", ios::in);

	if (f.is_open())
	{
		while (f >> buf.name >> buf.surname >> buf.patronymic >> buf.account_type >> buf.account_num >> buf.sum >> buf.data)
		{
			if (strcmp(account_num, buf.account_num) == 0)   //сравнение строк
			{
				cout << "\nНомер счета\t Имя\t Фамилия\t Отчество\t Тип счета\t Баланс счета\t Дата изменения\n";
				cout << buf.account_num << "\t " << buf.name << "\t " << buf.surname << "\t " << buf.patronymic << "\t " << buf.account_type << "\t " << buf.sum << "\t " << buf.data << "\n";
				flag = true; break;
			}
		}
		f.close();
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void delete_line(int line_number)
{
	fstream f;
	fstream temp;
	int count = 0;
	Clients buf;
	f.open("base.txt", ios::in);
	temp.open("temp.txt", ios::out);

	if (f.is_open() && temp.is_open())
	{
		while (f >> buf.name >> buf.surname >> buf.patronymic >> buf.account_type >> buf.account_num >> buf.sum >> buf.data)
		{
			count++;
			if (count != line_number)
			{
				temp << buf.name << " " << buf.surname << " " << buf.patronymic << " " << buf.account_type << " " << buf.account_num << " " << buf.sum << " " << buf.data << "\n";
			}
		}
		f.close();
		temp.close();

		remove("base.txt");
		rename("temp.txt", "base.txt");
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}
