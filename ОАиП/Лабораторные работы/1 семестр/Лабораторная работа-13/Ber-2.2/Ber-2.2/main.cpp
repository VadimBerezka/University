	#include <iostream>
	using namespace std;
	
	int main() {

		setlocale(LC_CTYPE, "Russian");
		char str[100];
		int min_g = 100, count = 1;

		cout << "������� ������, ��������� �� ����� ����� � ������: ";
		cin >> str;

		for (int i = 0; *(str + i) != '\0'; i++) {
			if (*(str + i) == *(str + i + 1)) {
				count++;
			}
			else {
				min_g = min(min_g, count);
				count = 1;
			}
		}

		cout << "����� �������� ������ �������:" << min_g;
		return 0;
	}