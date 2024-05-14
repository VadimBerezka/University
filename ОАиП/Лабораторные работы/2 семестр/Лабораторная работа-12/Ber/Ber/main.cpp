#include "Heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP rc = heap::EQUAL;
    if (A1->x > A2->x)
        rc = heap::GREAT;
    else if (A2->x > A1->x)
        rc = heap::LESS;
    return rc;
#undef A2
#undef A1 
}

int main()
{
    setlocale(LC_ALL, "rus");
    int k, choice;
    heap::Heap h1 = heap::create(30, cmpAAA);

    for (;;)
    {
        cout << "1 - ����� ���� �� �����" << endl;
        cout << "2 - �������� �������" << endl;
        cout << "3 - ������� ������������ �������" << endl;
        cout << "4 - ������� ����������� �������" << endl;
        cout << "5 - ������� ������� �� �������" << endl;
        cout << "6 - ���������� ��� ����" << endl;
        cout << "7 - ������� ��� ��������, ������ ������������� ��������" << endl;
        cout << "0 - �����" << endl;
        cout << "�������� �����" << endl;  cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            h1.scan(0);
            break;
        case 2: {
            AAA* a = new AAA;
            cout << "������� ����" << endl;
            cin >> k;
            a->x = k;
            h1.insert(a);
        }
              break;
        case 3:
            h1.extractMax();
            break;
        case 4:
            h1.extractMin();
            break;
        case 5: {
            int index;
            cout << "������� ������ ��������, ������� ����� �������: ";
            cin >> index;
            h1.extractI(index);
        }
            break;
        case 6: {
            int maxsize2;
            cout << "������� ������������ ������ ������ ����: ";
            cin >> maxsize2;
            heap::Heap h2 = heap::create(maxsize2, cmpAAA);
            for (;;) {
                cout << "�������� ������� �� ������ ���� (1 - ��, 0 - ���): ";
                int addChoice;
                cin >> addChoice;
                if (addChoice == 0)
                    break;
                else if (addChoice == 1) {
                    AAA* a = new AAA;
                    cout << "������� ����: ";
                    cin >> k;
                    a->x = k;
                    h2.insert(a);
                }
                else {
                    cout << "�������� �����. ��������� ����." << endl;
                }
            }
            heap::Heap mergedHeap = h1.unionHeap(h2);
            cout << "������������ ����:" << endl;
            mergedHeap.scan(0);
        }
            break;

        case 7:
            h1.removeAllMax();
            break;

        default:
            cout << endl << "�������� �����. ��������� ����." << endl;
        }
    }

    return 0;
}