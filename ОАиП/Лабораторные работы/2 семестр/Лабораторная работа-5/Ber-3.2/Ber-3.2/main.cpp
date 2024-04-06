#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define sizeS 50 

union AllClients
{
	char name[sizeS];
	char surname[sizeS];
	char object[sizeS];
	char cost[sizeS];
	char sum[sizeS];
	char date[sizeS];
	int srok;

} cl;

struct Clients
{
	string name;
	string surname;
	string object;
	string cost;
	string sum;
	string date;
	int srok;
};

struct Clients list_of_clients[sizeS], free_client;
int current_size_cl = 0;

void new_write();
void del_write();
void out_write();
void write_to_file();
void read_from_file();

void main()
{
	setlocale(LC_CTYPE, "Rus");
	int choice = 1;

	while (choice != 0) {
		cout << " \n1. ����� ������\n2. ������� ������\n3. ������� ������ � �������\n4. �������� ������ � ����\n5. ��������� ������ �� �����\n0. ���������\n(������� �����) ";
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

		default:
			break;
		}
	}
}

void new_write() {
	if (current_size_cl < sizeS) {
		cout << "\n ������ �" << current_size_cl + 1 << ": ";

		cout << "\n ������� ���: ";
		cin >> cl.name;
		list_of_clients[current_size_cl].name = cl.name;

		cout << "\n ������� �������: ";
		cin >> cl.surname;
		list_of_clients[current_size_cl].surname = cl.surname;

		cout << "\n ������� ������������ ������: ";
		cin >> cl.object;
		list_of_clients[current_size_cl].object = cl.object;

		cout << "\n ������� ��������� ���������($): ";
		cin >> cl.cost;
		list_of_clients[current_size_cl].cost = cl.cost;

		cout << "\n ������� ����� ��� �����($): ";
		cin >> cl.sum;
		list_of_clients[current_size_cl].sum = cl.sum;

		cout << "\n ������� ���� �����(**.**.****): ";
		cin >> cl.date;
		list_of_clients[current_size_cl].date = cl.date;

		cout << "\n ������� ���� ��������(� ����): ";
		cin >> cl.srok;
		list_of_clients[current_size_cl].srok = cl.srok;

		current_size_cl++;
	}
	else {
		cout << " ������� ������������ ���-�� �����" << endl;
	}
}

void del_write()
{
	int d;
	cout << " ����� ������, ������� ���� �������(��� �������� ���� ����� ������� -1): ";
	cin >> d;
	if (d == -1) {
		for (int i = 0; i < sizeS; i++) {
			list_of_clients[i] = free_client;
		}
		current_size_cl = 0;
	}
	else {
		for (int i = d - 1; i < current_size_cl; i++) {
			list_of_clients[i] = list_of_clients[i + 1];
		}
		current_size_cl--;
	}
}

void out_write()
{ 
	string object;
	cout << "\n������� ������������ ������, ��� ������ (��� ������ ���� ������� ������� -1): ";
	cin >> object;
	if (object == "-1") {
		for (int i = 0; i < current_size_cl; i++) {
			cout << "������ �";
			cout << i + 1;
			cout << ": ��� - ";
			cout << list_of_clients[i].name;
			cout << " | ������� - ";
			cout << list_of_clients[i].surname;
			cout << " | ������������ ������ - ";
			cout << list_of_clients[i].object;
			cout << " | ��������� ���������($) - ";
			cout << list_of_clients[i].cost;
			cout << " | ����� ��� �����($) - ";
			cout << list_of_clients[i].sum;
			cout << " | ���� �����(**.**.****) - ";
			cout << list_of_clients[i].date;
			cout << " | ���� ��������(���) - ";
			cout << list_of_clients[i].srok;
			cout << endl;
		}
	}

	else {
		for (int i = 0; i < current_size_cl; i++) {
			if (list_of_clients[i].object == object) {
				cout << "������ �";
				cout << i + 1;
				cout << ": ��� - ";
				cout << list_of_clients[i].name;
				cout << " | ������� - ";
				cout << list_of_clients[i].surname;
				cout << " | ������������ ������ - ";
				cout << list_of_clients[i].object;
				cout << " | ��������� ���������($) - ";
				cout << list_of_clients[i].cost;
				cout << " | ����� ��� �����($) - ";
				cout << list_of_clients[i].sum;
				cout << " | ���� �����(**.**.****) - ";
				cout << list_of_clients[i].date;
				cout << " | ���� ��������(���) - ";
				cout << list_of_clients[i].srok;
				cout << endl;
			}
		}
	}
}

void write_to_file() {
	ofstream outfile("clients.txt");
	for (int i = 0; i < current_size_cl; i++) {
		outfile << list_of_clients[i].name << " "
			<< list_of_clients[i].surname << " "
			<< list_of_clients[i].object << " "
			<< list_of_clients[i].cost << " "
			<< list_of_clients[i].sum << " "
			<< list_of_clients[i].date << " "
			<< list_of_clients[i].srok << "\n";
	}
	outfile.close();
}

void read_from_file() {
	ifstream infile("clients.txt");
	int i = 0;
	while (infile >> list_of_clients[i].name
		>> list_of_clients[i].surname
		>> list_of_clients[i].object
		>> list_of_clients[i].cost
		>> list_of_clients[i].sum
		>> list_of_clients[i].date
		>> list_of_clients[i].srok) {
		i++;
	}
	current_size_cl = i;
	infile.close();
}