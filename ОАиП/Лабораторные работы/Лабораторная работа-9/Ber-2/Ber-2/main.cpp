#include <iostream> 
using namespace std;

int main() {
  double a = 4, b = 7, e = 0.0001, x;
  x = (a + b) / 2;
  if ((cos(x) + x - 7) * (cos(a) + a - 7) <= 0) {
    b = x;
  }
  else {
    a = x;
  }
  while (true) {
    if (abs(a - b) > 2 * e) {
      x = (a + b) / 2;
      if ((cos(x) + x - 7) * (cos(a) + a - 7) <= 0) {
        b = x; 
      }
      else {
        a = x;
      }
    }
    else {
      break;
    }
    
  }
  cout << "x=" << x;
}