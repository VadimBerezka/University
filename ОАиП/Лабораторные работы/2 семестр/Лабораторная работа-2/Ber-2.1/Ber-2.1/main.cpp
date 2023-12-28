#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main() {
    const int rows = 4; const int cols = 4;
    int matrixM1[rows][cols];
    int matrixM2[rows][cols];
    int matrixM3[rows][cols];
    int i, j;

    FILE* out = fopen("fC.txt", "w");
    FILE* fileA = fopen("fA.txt", "r");
    FILE* fileB = fopen("fB.txt", "r");

    int ka = fgetc(fileA) - '0';
    int kb = fgetc(fileB) - '0';

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fscanf(fileA, "%d", &matrixM1[i][j]);
        }
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fscanf(fileB, "%d", &matrixM2[i][j]);
        }
    }


    fprintf(out, "%d\n", ka);

    matrixM3[i][j] = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
                matrixM3[i][j] = matrixM1[i][j] + matrixM2[i][j];
            fprintf(out, "%d ", matrixM3[i][j]);
        }
        fprintf(out, "\n");
    }

    fclose(fileA);
    fclose(fileB);
    fclose(out);
    return 0;
}