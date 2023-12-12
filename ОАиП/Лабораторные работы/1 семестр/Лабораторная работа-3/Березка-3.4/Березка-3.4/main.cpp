#include <iostream>
using namespace std;
void main()
{
	double t, u, x;
	int k = 4;
	int	a = 8.1;
	int	g = 10;
	int j = -4;
	x = 2 * pow(g, j);
	t = 2 * k / a + log(2 + x);
	u = sqrt(k - 1) / (t + 1);
	cout << "t=" << t<< endl;
	cout << "u=" << u<< endl;
}