#include <cstdio>
#include "center_of_mass.h"

int main()
{
    const char* inputFile  = "input.txt";
    const char* outputFile = "output.txt";

    double** points = nullptr;
    int      K      = 0;

    if (readData(inputFile, &points, &K) != 0) {
        std::fprintf(stderr, "Ошибка чтения входного файла\n");
        return 1;
    }

    double sumXM, sumYM, sumM;
    computeMomentSums(points, K, &sumXM, &sumYM, &sumM);

    double XC, YC;
    computeCenter(sumXM, sumYM, sumM, &XC, &YC);

    if (writeResult(outputFile, XC, YC) != 0) {
        std::fprintf(stderr, "Ошибка записи выходного файла\n");
        freeData(points, K);
        return 2;
    }

    freeData(points, K);
    return 0;
}