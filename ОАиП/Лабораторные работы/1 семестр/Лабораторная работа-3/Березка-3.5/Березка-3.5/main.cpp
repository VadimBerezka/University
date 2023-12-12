#include <iostream>
using namespace std;
void main()
{
	double t, u, s, a;
	double y = -0.956;
	int	n = 4;
	int	g = 10;
	int j = -6;
	a = 5 * pow(g, j);
	t = 1 / sqrt(y) + 14 * a;
	u = (t + 1) / (a + 2);
	s = log( (2 * n / 3) + exp(-n) / u);
	cout << "t=" << t << endl;
	cout << "u=" << u << endl;
	cout << "s=" << s << endl;
}