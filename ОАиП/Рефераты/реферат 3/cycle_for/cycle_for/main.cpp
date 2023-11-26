//#include <iostream> // Подключение библиотеки 
//using namespace std; // Использование пространства имен std
//
//int main() {
//    setlocale(LC_CTYPE, "Russian"); // Установка локали для вывода на русском языке
//    int n = 1000; // Объявление и инициализация переменной n со значением 1000
//    int sum = 0; // Объявление и инициализация переменной sum со значением 0
//
//    for (int i = 0; i < n; i++) { // Цикл для вычисления 
//        sum += i / 17; // Добавление значения i, деленного на 17, к переменной sum
//       sum -= i * 3;  // Вычитание значения i, умноженного на 3, из переменной sum
//    }
//
//    cout << "Результат: " << sum << endl; // Вывод значения переменной sum с сообщением "Результат: "
//    return 0; // Возврат значения 0, обозначающего успешное завершение программы
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    int n = 1000;
//    float sum = 0;
//
//    for (float i = 0; i < n; i++) {
//        sum += i / 17;
//    }
//
//    cout << "Результат: " << sum << endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    int n = 1000;
//    double sum = 0;
//
//    for (double i = 0; i < n; i++) {
//        sum += i / 17;
//        sum -= i * 3;
//    }
//
//    cout << "Результат: " << sum << endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    int n = 1000;
//    char ch = 'a';
//
//    for (int i = 0; i < n; i++) {
//        ch += i / 17;
//        ch -= i * 3;
//    }
//
//    cout << "Результат: " << ch << endl;
//    return 0;
//}

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    size_t n = 1000;
    size_t sum = 0;

    for (size_t i = 0; i < n; i++) {
        sum += i / 17;
        sum -= i * 3;
    }

    cout << "Результат: " << sum << endl;
    return 0;
}