#include "center_of_mass.h"
#include <cstdio>
#include <cstdlib>

int readData(const char* fileName,
             double** X, double** Y, double** M, int* K)
{
    FILE* f = std::fopen(fileName, "r");
    if (!f) return -1;

    if (std::fscanf(f, "%d", K) != 1 || *K <= 0) {
        std::fclose(f);
        return -2;
    }

    *X = new double[*K];
    *Y = new double[*K];
    *M = new double[*K];

    for (int i = 0; i < *K; ++i)
        if (std::fscanf(f, "%lf", &(*X)[i]) != 1) {
            std::fclose(f);
            delete[] *X; delete[] *Y; delete[] *M;
            return -3;
        }

    for (int i = 0; i < *K; ++i)
        if (std::fscanf(f, "%lf", &(*Y)[i]) != 1) {
            std::fclose(f);
            delete[] *X; delete[] *Y; delete[] *M;
            return -4;
        }

    for (int i = 0; i < *K; ++i)
        if (std::fscanf(f, "%lf", &(*M)[i]) != 1) {
            std::fclose(f);
            delete[] *X; delete[] *Y; delete[] *M;
            return -5;
        }

    std::fclose(f);
    return 0;                                 
}

void computeMomentSums(const double* X, const double* Y, const double* M, int K,
                       double* sumXM, double* sumYM, double* sumM)
{
    *sumXM = *sumYM = *sumM = 0.0;
    for (int i = 0; i < K; ++i) {
        *sumXM += X[i] * M[i];
        *sumYM += Y[i] * M[i];
        *sumM  += M[i];
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

void freeData(double* X, double* Y, double* M)
{
    delete[] X;
    delete[] Y;
    delete[] M;
}