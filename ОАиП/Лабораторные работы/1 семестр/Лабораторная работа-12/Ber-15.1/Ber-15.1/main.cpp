#include <iostream> 
#include <iomanip>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, k;
	cin >> n;
	bool t = false;
	int a[500];
	for (int i = 0; i < n; i++) { // ��������� ������ a ������� � ����������
		cin >> *(a + i);
	}
	for (int i = 0; i < n - 1; i++) { // �������� �� ��������� �������
		if (*(a + i) < 0) { // ���� ������� ������ 0
			for (int j = i + 1; j < n; j++) { // �������� �� ��������� �������, ������� �� ����������, � ���� ������������� �������
				if (*(a + j) > 0) { // ���� �������, �� ������ �� �������
					k = *(a + j);
					*(a + j) = *(a + i);
					*(a + i) = k;
					t = true;
					break;
				}
			}
			if (t == true) {
				t = false;
			}
			else { // ���� �� ����� �� ������, ������ ��� ��������� ������������ � ����������� ����
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) { // ������� ������ ����� ������
		cout << *(a + i) << " ";
	}
}
