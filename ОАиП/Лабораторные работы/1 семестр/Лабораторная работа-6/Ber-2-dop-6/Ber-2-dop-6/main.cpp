#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    string number, result;
    cout << "������� ����� �����: ";
    cin >> number;

  
    for (char element : number) {
        if (element != '3' && element != '6') {
            result += element;
        }
    }

    cout << "���������: " << result << endl;

    return 0;
}