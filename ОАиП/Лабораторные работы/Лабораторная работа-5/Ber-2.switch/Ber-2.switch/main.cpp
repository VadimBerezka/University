#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k;
	puts("����� ���������� � ����� FERRARI. �� ������ ������ ������? (1-��, 2-���)");
	cin >> k;
	switch (k)
	{
	case 1: { puts("����� ������ ��� ����������? (1- F430, 2- 599 GTB FIORANO, 3- 458 ITALIA, 4- 458 SPECIALE)");
		cin >> k;
		switch (k)
		{
		case 1: puts("�������� �����"); break;
		case 2: puts("������� �����"); break;
		case 3: puts("��� ������ ������� ��� ���"); break;
		case 4: puts("������ �� ����� �����, �� ������"); break;
		}
		break;
	}
	case 2: puts("����, ����� ���� ������ ��� ���"); break;
	default: puts("������������ �������"); break;
	}
		return 0;
}
