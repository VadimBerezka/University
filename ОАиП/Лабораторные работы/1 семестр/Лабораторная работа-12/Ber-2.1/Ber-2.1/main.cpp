#include <iostream>
using namespace std;

int main()
{
	int a[10], b[10], s[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;		
		cout << a[i] << "\t ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		b[i] = rand() % 100;
		cout << b[i] << "\t ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		*(s + i) = *(a + i) + *(b + i);
		cout << s[i] << "\t ";
	}
	return 0;
}