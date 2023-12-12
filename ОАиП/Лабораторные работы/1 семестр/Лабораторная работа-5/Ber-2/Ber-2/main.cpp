#include <iostream>
using namespace std;

int main()
{
	
	setlocale(LC_CTYPE, "Russian");

    int a, b, c;
    cout << "Введите три числа: ";
    cin >> a;
    cin >> b;
    cin >> c;

    if (a == b || a == c || b == c) 
    {
      cout << "Есть хотя бы одна пара равных чисел." << endl;
    }
    else {
      cout << "Нет пары равных чисел." << endl;
    }
	return 0;
}
