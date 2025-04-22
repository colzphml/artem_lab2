#ifndef CENTER_OF_MASS_H
#define CENTER_OF_MASS_H

int readData(const char* fileName,
             double** X, double** Y, double** M, int* K);

void computeMomentSums(const double* X, const double* Y, const double* M, int K,
                       double* sumXM, double* sumYM, double* sumM);

void computeCenter(double sumXM, double sumYM, double sumM,
                   double* XC, double* YC);

int writeResult(const char* fileName, double XC, double YC);

void freeData(double* X, double* Y, double* M);

#endif /* CENTER_OF_MASS_H */