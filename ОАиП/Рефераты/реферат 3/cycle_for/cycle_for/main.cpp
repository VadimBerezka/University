//#include <iostream> // ����������� ���������� 
//using namespace std; // ������������� ������������ ���� std
//
//int main() {
//    setlocale(LC_CTYPE, "Russian"); // ��������� ������ ��� ������ �� ������� �����
//    int n = 1000; // ���������� � ������������� ���������� n �� ��������� 1000
//    int sum = 0; // ���������� � ������������� ���������� sum �� ��������� 0
//
//    for (int i = 0; i < n; i++) { // ���� ��� ���������� 
//        sum += i / 17; // ���������� �������� i, ��������� �� 17, � ���������� sum
//       sum -= i * 3;  // ��������� �������� i, ����������� �� 3, �� ���������� sum
//    }
//
//    cout << "���������: " << sum << endl; // ����� �������� ���������� sum � ���������� "���������: "
//    return 0; // ������� �������� 0, ������������� �������� ���������� ���������
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
//    cout << "���������: " << sum << endl;
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
//    cout << "���������: " << sum << endl;
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
//    cout << "���������: " << ch << endl;
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

    cout << "���������: " << sum << endl;
    return 0;
}