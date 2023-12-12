#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k;
	puts("Добро пожаловать в салон FERRARI. Вы хотите купить машину? (1-да, 2-нет)");
	cin >> k;
	switch (k)
	{
	case 1: { puts("Какая модель Вас интересует? (1- F430, 2- 599 GTB FIORANO, 3- 458 ITALIA, 4- 458 SPECIALE)");
		cin >> k;
		switch (k)
		{
		case 1: puts("Отличный выбор"); break;
		case 2: puts("Хороший выбор"); break;
		case 3: puts("Эта машина создана для Вас"); break;
		case 4: puts("Машина не самая новая, но пойдет"); break;
		}
		break;
	}
	case 2: puts("Жаль, будем рады видеть Вас еще"); break;
	default: puts("Некорректный вариант"); break;
	}
		return 0;
}
