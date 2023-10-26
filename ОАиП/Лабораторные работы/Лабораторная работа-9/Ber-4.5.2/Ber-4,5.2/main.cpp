#include <iostream> 
using namespace std;

int main() {
	double a = 4, b = 7, n = 200, h = (b - a) / (2 * n), x = a + 2 * h, S, s1 = 0, s2 = 0, i = 1;
	while (i < n) {
		s2 += (exp(x) - 1 / x);
		x += h;
		s1 += (exp(x) - 1 / x);
		x += h;
		i++;
	}
	S = h / 3 * (exp(a) - 1 / a) + (4 * (exp(a + h) - 1 / a + h)) + 4 * s1 + 4 * s2 + (exp(b) - 1 / b);
	cout <<"s=" << S;
	return 0;
}