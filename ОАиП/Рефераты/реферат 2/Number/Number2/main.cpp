#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
 
int main() {
    setlocale(0,"");
    cout << "Добро пожаловать в игру: угадай число, есть 5 попыток " << endl;
    srand(static_cast<unsigned int>(time(0)));
    int tries = 1;
    string a; int secr1; int secr2;
    int secr = rand()%100+1;
    secr1 = rand()%secr + 1;
    secr2 = rand()%secr + secr1;
    cout << "Если мое число не верно, то напишите: Меньше; Больше. Если угадал, то напиши Да." << endl;
    cout << "Попытка номер: " << tries << " Мое число: "<< secr << endl;
    getline(cin, a);
    do {
 
        if (a == "Больше"){
++tries;
cout << "Попытка номер: " << tries << endl;
cout << secr2 << endl;
getline(cin,a);
}
else if (a == "Меньше") {
    ++tries;
    cout << "Попытка номер: " << tries << endl;
    cout << secr1 << endl;
    getline(cin,a);
}
else if (a == "Да") {
cout << "Молодец!!!, ваше количество попыток: " << tries; break;
} else
    {cout << "Не то ввёл!!!, введи нормально " << endl;
        getline(cin,a); }
    }  while(tries != 5); if (tries == 5)
        cout << "I проиграл!!!, количество попыток равно: " << tries << endl;
 return 0;
}