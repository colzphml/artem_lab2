#include "center_of_mass.h"
#include <cstdio>
#include <cstdlib>
#include <new>

int readData(const char* fileName, double*** matrix, int* K)
{
    FILE* f = std::fopen(fileName, "r");
    if (!f) return -1;

    if (std::fscanf(f, "%d", K) != 1 || *K <= 0) {
        std::fclose(f);
        return -2;
    }

    *matrix = new double*[*K];
    for (int i = 0; i < *K; ++i) {
        (*matrix)[i] = new (std::nothrow) double[3];
        if (!(*matrix)[i]) {
            for (int j = 0; j <= i; ++j) delete[] (*matrix)[j];
            delete[] *matrix;
            std::fclose(f);
            freeData(*matrix, *K);
            return -3;
        }
    }

    for (int i = 0; i < *K; ++i)
        if (std::fscanf(f, "%lf", &(*matrix)[i][0]) != 1) {
            std::fclose(f);
            freeData(*matrix, *K);
            return -4;
        }

    for (int i = 0; i < *K; ++i)
        if (std::fscanf(f, "%lf", &(*matrix)[i][1]) != 1) {
            std::fclose(f);
            freeData(*matrix, *K);
            return -5;
        }

    for (int i = 0; i < *K; ++i)
        if (std::fscanf(f, "%lf", &(*matrix)[i][2]) != 1) {
            std::fclose(f);
            freeData(*matrix, *K);
            return -6;
        }

    std::fclose(f);
    return 0;
}

void computeMomentSums(const double* const* matrix, int K,
                       double* sumXM, double* sumYM, double* sumM)
{
    *sumXM = *sumYM = *sumM = 0.0;
    for (int i = 0; i < K; ++i) {
        const double x = matrix[i][0];
        const double y = matrix[i][1];
        const double m = matrix[i][2];

        *sumXM += x * m;
        *sumYM += y * m;
        *sumM  += m;
    }
}

void computeCenter(double sumXM, double sumYM, double sumM,
                   double* XC, double* YC)
{
    *XC = sumXM / sumM;
    *YC = sumYM / sumM;
}

int writeResult(const char* fileName, double XC, double YC)
{
    FILE* f = std::fopen(fileName, "w");
    if (!f) return -1;
    std::fprintf(f, "%.6f %.6f\n", XC, YC);
    std::fclose(f);
    return 0;
}

void freeData(double** matrix, int K)
{
    for (int i = 0; i < K; ++i) delete[] matrix[i];
    delete[] matrix;
}