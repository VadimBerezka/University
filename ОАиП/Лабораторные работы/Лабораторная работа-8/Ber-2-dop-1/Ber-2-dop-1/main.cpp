#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int size, sum = 0;
	cout << "������� ������ �������: ";
	cin >> size;
	cout << "������� �������� � ������: ";
	// �������� ������������� �������
	int* arr{ new int[size] };
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == 0) {
			sum += arr[i];
		}
	}
	cout << "�����:" << sum;
	return 0;
}