#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int count = 0;

    for (int nominal2 = 0; nominal2 <= 100; nominal2 += 2) {
        for (int nominal5 = 0; nominal5 <= 100; nominal5 += 5) {
            for (int nominal20 = 0; nominal20 <= 100; nominal20 += 20) {
                for (int nominal50 = 0; nominal50 <= 100; nominal50 += 50) {
                    if (nominal50 + nominal20 + nominal5 + nominal2 == 100) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << " �������� ���������� ������ ������ ����� ��� ������ ����� ������������ 50 ���., 20 ���., 5 ���. � 2 ���. "  << endl;

    return 0;
}