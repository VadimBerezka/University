#include <iostream>
using namespace std;

int F(int m, int n)
{
	if (m >= 0 && n >= 0)
	{
		if ((m + n) % 2 == 0)
			return m >= n ? m : n;
		else
			return F((m + n + 1) / 2, n + 1) + F(m, (n + m + 1) / 2);
	}
	else
	{
		cout << "���" << endl;
		return -1;
	}
}
int main() {

	int m, n;
	cout << "������� m, n: ";
	cin >> m >> n;
	cout << F(m, n);
	return 0;
}