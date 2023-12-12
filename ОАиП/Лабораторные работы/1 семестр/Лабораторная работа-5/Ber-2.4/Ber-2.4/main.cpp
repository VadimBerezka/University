#include <iostream>
using namespace std;
int main()
{
  
    setlocale(LC_CTYPE, "Russian");
    int r, p, q, md;
    cout << "Введите радиус шара: ";
    cin >> r;
    cout << "Введите первую диагональ ромба : ";
    cin >> p;
    cout << "Введите первую диагональ ромба : ";
    cin >> q;
    md = min(p, q);
    if (2 * r <= md)
        cout << "Пройдет";
    else
        cout << "Не пройдет";
    return 0;
}
