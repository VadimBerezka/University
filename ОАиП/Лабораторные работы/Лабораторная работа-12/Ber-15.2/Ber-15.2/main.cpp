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
	int f[500];
	int d[500];
	for (int i = 0; i < n; i++) { // ��������� ������ f ������� � ����������
		cin >> *(f + i);
	}
	for (int i = 0; i < m; i++) { // ��������� ������ d ������� � ����������
		cin >> *(d + i);
	}
	max = *f; // ����������� ���������� max �������� ������� �������� ������� f
	for (int i = 1; i < n; i++) { // ������� ������������ ������� � ������� f
		if (*(f + i) > max) {
			max = *(f + i);
		}
	}
	for (int i = 0; i < m; i++) { // ���� ������������ ������� �� ������� f � ������� d
		if (*(d + i) == max) {
			cout << "���������� ������� ������� f ���������� � ������� d" << endl;
			t = true;
			break;
		}
	}
	if (t == false) {
		cout << "���������� ������� ������� f �� ���������� � ������� d" << endl;
	}
}
