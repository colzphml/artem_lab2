#include <cstdio>
#include "center_of_mass.h"

int main()
{
    const char* inputFile  = "input.txt";
    const char* outputFile = "output.txt";

    double* X = nullptr;
    double* Y = nullptr;
    double* M = nullptr;
    int      K = 0;

    if (readData(inputFile, &X, &Y, &M, &K) != 0) {
        std::fprintf(stderr, "Ошибка чтения входного файла\n");
        return 1;
    }

    double sumXM, sumYM, sumM;
    computeMomentSums(X, Y, M, K, &sumXM, &sumYM, &sumM);

    double XC, YC;
    computeCenter(sumXM, sumYM, sumM, &XC, &YC);

    if (writeResult(outputFile, XC, YC) != 0) {
        std::fprintf(stderr, "Ошибка записи выходного файла\n");
        freeData(X, Y, M);
        return 2;
    }

    freeData(X, Y, M);
    return 0;
}