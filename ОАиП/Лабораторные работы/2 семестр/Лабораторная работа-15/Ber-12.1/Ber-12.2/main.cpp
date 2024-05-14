#include <iostream>
#include <ctime>
#include <vector>

// Функция сортировки слиянием
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));
    const int sizeA = 5000;
    int A[sizeA];
    for (int i = 0; i < sizeA; i++) {
        A[i] = rand() % 100;
    }

    int B[sizeA];
    int sizeB = 0;
    for (int i = 0; i < sizeA; i += 2) {
        B[sizeB++] = A[i];
    }

    clock_t start = clock();
    mergeSort(B, 0, sizeB - 1);  // Сортировка слиянием
    clock_t end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Время выполнения сортировки слиянием: " << time_taken << " секунд" << std::endl;

    std::cout << "Задача выполнена успешно!" << std::endl;

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < sizeB; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
