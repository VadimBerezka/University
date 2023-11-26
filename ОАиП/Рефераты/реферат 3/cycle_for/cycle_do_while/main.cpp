//#include <iostream>
//using namespace std;
//
//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    int n = 1000;
//    int sum = 0;
//    int i = 0;   
//
//    do {
//        sum += i / 17;
//        sum -= i * 3; // Вычитание значения i, умноженного на 3, из переменной sum
//        i++;
//    } while (i < n);
// 
//    cout << "Результат: " << sum << endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;

//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    int n = 1000;
//    float sum = 0;
//    float i = 0;
//
//    do {
//        sum += i / 17;
//        sum -= i * 3;
//        i++;
//    } while (i < n);
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
//    double i = 0;
//
//    do {
//        sum += i / 17;
//        sum -= i * 3;
//        i++;
//    } while (i < n);
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
//    int i = 0;
//
//    do {
//        ch += i / 17;
//        ch -= i * 3;
//        i++;
//    } while (i < n);
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
    size_t i = 0;

    do {
        sum += i / 17;
        sum -= i * 4;
        i++;
    } while (i < n);

    cout << "Результат: " << sum << endl;
    return 0;
}