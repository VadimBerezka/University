#include <iostream> 
#include <iomanip>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, m, max;
	cin >> n >> m;
	bool t = false;
	int a[500];
	int b[500];
	for (int i = 0; i < n; i++) { // ��������� ������ a ������� � ����������
		cin >> *(a + i);
	}
	for (int i = 0; i < m; i++) { // ��������� ������ b ������� � ����������
		cin >> *(b + i);
	}
	max = *a; // ����������� ���������� max �������� ������� �������� ������� a
	for (int i = 1; i < n; i++) { // ������� ������������ ������� � ������� a
		if (*(a + i) > max) {
			max = *(a + i);
		}
	}
	for (int i = 0; i < m; i++) { // ���� ������������ ������� �� ������� a � ������� b
		if (*(b + i) == max) {
			cout << "���������� ������� ������� a ���������� � ������� b" << endl;
			t = true;
			break;
		}
	}
	if (t == false) {
		cout << "���������� ������� ������� a �� ���������� � ������� b" << endl;
	}
}
