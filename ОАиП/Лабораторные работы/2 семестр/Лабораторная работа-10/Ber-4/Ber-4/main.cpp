#include <iostream>
using namespace std;

int numcq(int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		if (b == 0)
			return 0;
		else
			return floor(a / b) + numcq(b, a % b);
	}
	else
	{
		cout << "нет";
		return -1;
	}
}

int main()
{
	cout << "Введите a, b: ";
	int a, b;
	cin >> a >> b;
	cout << numcq(a, b);
	return 0;
}