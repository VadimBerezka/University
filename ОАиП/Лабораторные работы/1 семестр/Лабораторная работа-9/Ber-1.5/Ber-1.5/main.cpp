#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double n = 200, a = 1, b = 3, h = (b - a) / n, s = 0, x = a;
	while (true) {
		
		if (x > (b - h)) {
			break;
		}
		else {
			s += h * (pow(x, 3) - 3 + pow(x + h, 3) - 3) / 2;
			x += h;
		}
	}
	cout << "s= " << s;
	return 0;
}
