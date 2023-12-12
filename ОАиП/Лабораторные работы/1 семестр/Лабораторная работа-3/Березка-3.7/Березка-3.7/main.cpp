#include <iostream>
using namespace std;
void main()
{
	double t, s, y;
	double x = 0.1;
	int j = 12;
	int	g = 10;
	int k = -6;
	y = 5 * pow(g, k);
	s = 0.4 * x - 1 / j * tan(y);
	t = s - sin(s);
	cout << "s=" << s << endl;
	cout << "t=" << t << endl;
}