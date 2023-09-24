#include <iostream>
using namespace std;
void main()
{
	double p, q, x;
	int t = 6;
	int	y = -1.2;
	int	g = 10;
	int j = 6;
	x = 0.4 * pow(g, j);
	p = 2.6 * t + cos(y / (3 * x + y));
	q = sin(t) / cos(t);
	cout << "p=" << p<< endl;
	cout << "q=" << q<< endl;
}