#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double P, Q;
	int per = 3, days = 0;
	cout << "Введите на сколько тыс.руб компания реализовала товаров : ";
	cin >> P;
	cout << "Какое значение выручка должна превысить : ";
	cin >> Q;
	while (P <= Q) {
		P += P * per / 100;
		days++;
	};
	cout << P << endl;
	cout << "Количество дней, которые понадобятся чтобы превысить это значение: " << days;
	return 0;
}
