#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main() {

    FILE* out = fopen("g.txt", "w");
    FILE* file = fopen("f.txt", "r");
    int g;
    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < 10; i++) {
        fscanf(file, "%d", &g);
        if (g > 0 && positiveCount < 5) {
            fprintf(out, "%d\t", g);
            positiveCount++;
        }
    }
    // можно было сделать через if else if
    rewind(file); // Возвращаем указатель файла в начало

    for (int i = 0; i < 10; i++) {
        fscanf(file, "%d", &g);
        if (g < 0 && negativeCount < 5) {
            fprintf(out, "%d\t", g);
            negativeCount++;
        }
    }

    fclose(file);
    fclose(out);
    return 0;
}