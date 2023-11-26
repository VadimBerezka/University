#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int n = 3, m = 3;
	int A[n][m];
	int i, j, kol = 0, row = 0, column = 0;
	float sum = 0, arithmetic_mean;
	cout << "Введите элементы массива" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> A[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (A[i][j] > 0)
			{
				sum += A[i][j];
				kol += 1;
				column = i;
				row = j;
			}


	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\n";
		for (int j = 0; j < m; j++)
			cout << "A[" << i << "," << j << "] =" << A[i][j] << "\t";
	}

	arithmetic_mean = sum / kol;
	cout << endl;
	cout << "Сумма всех положительных элементов: " << sum << endl;
	cout << "Кол-во всех положительных элементов: " << kol << endl;
	cout << "Среднее арифметическое всех положительных элементов: " << arithmetic_mean << endl;
}
