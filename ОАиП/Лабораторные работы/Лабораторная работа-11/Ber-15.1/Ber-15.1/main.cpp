#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	int A; char tmp[33];
	cout << "Введите число А: " << endl; cin >> A;
	(A & 1) == 1 ? cout << "Число нечетное." << endl : cout << "Число четное." << endl;
}
