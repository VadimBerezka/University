// ����������� ���������
#include <iostream>
using namespace std;
int main()
{
    // ���������� ����������� ������ �� ������� �����
    setlocale(LC_CTYPE, "Russian");
    // �������� ����������
    const int maxSize = 100;
    int k, arr[maxSize], min = 0, max = 99, n;
    cout << "������� ���������� ��������� �������: "; // �����
    cin >> k; // ����
    srand(time(NULL));
    // �������� ����� for ��� ���������� ������� ���������� �������
    for (int i = 0; i < k; i++) {
        arr[i] = (int)((double)rand() / (double)RAND_MAX * (max - min) + min);
        cout << arr[i] << " ";
    }
    cout << "������� ���������� ������� ��� ������: "; // �����
    cin >> n; // ����
    // �������� ����� for, � ������� ���������� �������� �� n ��������� �����
    for (int i = 0; i < n; i++) {
        int initial = arr[0];
        for (int j = 0; j < k - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[k - 1] = initial;
    }
    // ����� ����������
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
