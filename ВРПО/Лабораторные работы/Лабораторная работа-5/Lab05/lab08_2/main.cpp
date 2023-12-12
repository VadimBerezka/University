#include <iostream>
int var = 1;
using namespace std;
int main()
{
    cout << "var= " << var << endl;
    int var = 2;
    cout << "var= " << var << endl;
    while (var > 0)
    {
        int var = 0;
        --var;
        cout << "var= " << var << endl;
        system("pause");
    }
    system("pause");
    return 0;
}