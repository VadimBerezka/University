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
	int z[500];
	for (int i = 0; i < n; i++) { // ��������� ������ a ������� � ����������
		cin >> *(z + i);
	}
	for (int i = 0; i < n - 1; i++) { // �������� ������ �� ��������� �������, ������� � �������
		for (int j = i + 1; j < n; j++) { // �������� ������ �� ��������� �������, ������� �� �������
			if (*(z + i) == *(z + j)) { // ���������� ��
				for (int k = j; k < n; k++) { // ���� ��� �����, �� ������� ������������� ������ �� �������
					*(z + k) = *(z + k + 1);
				}
				n--;
				j--;
			}
		}
	}
	cout << "���������� ��������� ��������� � ������� z = " << n << endl;
}
