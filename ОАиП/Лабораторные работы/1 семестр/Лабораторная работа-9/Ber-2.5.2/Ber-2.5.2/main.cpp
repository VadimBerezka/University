#include <iostream> 
using namespace std;

int main() {
  double a = 4, b = 7, n = 200, h = (b - a) / (2 * n), x = a + 2 * h, S, s1 = 0, s2 = 0, i = 1;
  while (i < n) {
  s2 += (pow(cos(x), 3));
  x += h; 
  s1 += (pow(cos(x), 3));
  x += h;
  i++;
  }
  S = h / 3 * (pow(cos(a), 3) + 4 * pow(cos(a+h), 3) + 4 * s1 + 2 * s2 + pow(cos(b), 3));
  cout << "S=" << S;
  return 0;
}