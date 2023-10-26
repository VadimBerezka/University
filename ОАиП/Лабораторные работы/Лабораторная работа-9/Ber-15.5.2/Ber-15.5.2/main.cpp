#include <iostream>
using namespace std;
int main()
{
setlocale(LC_CTYPE, "Russian");
double n = 200, a = 2, b = 7, h = (b - a) / (2 * n), x = a + 2 * h, s1 = 0, s2 = 0, i = 1, s;
while (i < n) {
	s2 += pow(sin(x), 2) + 1;
	x += h;
	s1 += pow(sin(x), 2) + 1;
	x += h;
	i++;
}
s = h / 3 * (pow(sin(x), 2) + 1 + (4 * (pow(sin(x + h), 2) + 1) + 4 * s1 + 4 * s2 + (pow(sin(x), 2) + 1)));
cout << "s=" << s;
return 0;
}
