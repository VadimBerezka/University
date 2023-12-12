#include <iostream>
using namespace std;
void main()
{
	double z, y, x;
	int n = 2;
	int	b = -0.12;
	int	g = 10;
	int j = -4;
	x = 1.3 * pow(g, j);
	z = 1 / (x - 1) + sin(x) - sqrt(n);
	y = (exp(-b) + 1) / 2 * z;
	cout << "z=" << z << endl;
	cout << "y=" << y<< endl;
}