#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    string number, result;
    cout << "¬ведите целое число: ";
    cin >> number;

  
    for (char element : number) {
        if (element != '3' && element != '6') {
            result += element;
        }
    }

    cout << "–езультат: " << result << endl;

    return 0;
}