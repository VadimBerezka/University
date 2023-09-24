#include <iostream>
using namespace std;
void main()
{
	double w, v, a;
	int b = 40;
	int	x = 1.1;
	int g = 10;
	int j = -6;
	a = 5 * pow(g, j);
	w = (a + b) * tan(x) / (x + 1);
	v = 1 / 2 * b - sqrt(w - a * b);
	cout << "w=" << w << endl;
	cout << "v=" << v << endl;
}