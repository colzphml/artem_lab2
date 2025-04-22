#ifndef CENTER_OF_MASS_H
#define CENTER_OF_MASS_H


int readData(const char* fileName, double*** matrix, int* K);

void computeMomentSums(const double* const* matrix, int K,
                       double* sumXM, double* sumYM, double* sumM);

void computeCenter(double sumXM, double sumYM, double sumM,
                   double* XC, double* YC);

int writeResult(const char* fileName, double XC, double YC);

void freeData(double** matrix, int K);

#endif /* CENTER_OF_MASS_H */