#include <iostream>
using namespace std;
void main()
{
	double y, w, z;
	int x = 1.4;
	int	m = 6;
	int	g = 10;
	int j = -5;
	z = 0.05 * pow(g, j);
	y = sqrt(1 + x) - cos(2 / m);
	w = 0.6 * z - 2 * exp(-2 * y * m);
	cout << "y=" << y << endl;
	cout << "w=" << w << endl;
}