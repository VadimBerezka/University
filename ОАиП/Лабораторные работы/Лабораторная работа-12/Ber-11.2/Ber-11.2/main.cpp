#include <iostream> 
#include <iomanip>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, m, z, s = 0, s2 = 0;
	cin >> n >> m; // ������� ��������
	cin >> z; // ��������� �����-������������
	int a[500];
	int b[500];
	for (int i = 0; i < n; i++) { // ��������� ������ a ������� � ����������
		cin >> *(a + i);
	}
	for (int i = 0; i < m; i++) { // ��������� ������ b ������� � ����������
		cin >> *(b + i);
	}
	for (int i = 0; i < n; i++) { // �������� �� ������� a � ������� ���-�� �������� ������� z
		if (*(a + i) < z) {
			s += 1;
		}
	}
