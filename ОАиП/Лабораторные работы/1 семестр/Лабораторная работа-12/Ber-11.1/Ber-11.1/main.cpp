#include <iostream> 
#include <iomanip>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cin >> n;
	bool t = false;
	int a[500];
	for (int i = 0; i < n; i++) { // ��������� ������ ������� � ����������
		cin >> *(a + i);
	}
	for (int j = 1; j < 2000000000; j++) { // ������ ���� �������� ����������� �����
		for (int i = 0; i < n; i++) { // ��������� ���� ������� �� ��������� �������
			if (*(a + i) == j) { // ��������� �� �� ���������
				t = true; // ���� �������, �� ��������� ����������� ����
				break;
			}
		}
		if (t == false) { //���� �� �������, �� ������� ��� ����� � ��������� ������� ����
			cout << j;
			break;
		}
		else { // ����� ���������� �������
			t = false;
		}
	}
}
