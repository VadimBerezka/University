#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double n = 200, a = 2, b = 7, h = (b - a) / n, s = 0, x = a;
	while (true) {
		if (x > (b - h)) {
			break;
		}
		else {
			s += h * ((pow(sin(x), 2) + 1 + (pow(sin(x + h), 2) + 1))) / 2;
			x += h;
		}
	}
	cout << "s= " << s;
	return 0;
}
