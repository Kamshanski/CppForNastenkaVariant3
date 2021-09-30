//
// Описать функцию типа void поиска минимального элемента и его 2-ух
//позиций во всей матрице. Даны две матрицы A( ), B( ). Поменять местами
//минимальные элементы матриц А и В.

#include "../everything.h"

// Описать функцию типа void поиска минимального элемента и его 2-ух
//позиций во всей матрице.
void findTwoMins(double* matrix, int size,  double & min,
                 int& r1, int& c1, int& r2, int& c2)
{
    double minElem = INT_MAX;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (minElem > matrix[i*size + j]) {
                minElem = matrix[i*size + j];
                r1 = i;
                c1 = j;
            } else if (minElem == matrix[i*size + j]) {
                r2 = i;
                c2 = j;
            }
        }
    }
    min = minElem;
}

int main() {
    // Даны две матрицы A( ), B( ).
    const int N = 3;
    double A[N][N] = {
            {1,  0,  2},
            {9,  5,  0},
            {5,  5,  9}
    };
    double B[N][N] = {
            {2,  3,  4},
            {5,  6,  5},
            {6,  3,  2}
    };

    // Описать функцию типа void поиска минимального элемента и его 2-ух
    //позиций во всей матрице.
    double minA, minB;
    int ar1, ac1, ar2, ac2;
    int br1, bc1, br2, bc2;

    findTwoMins(&A[0][0], N, minA, ar1, ac1, ar2, ac2);
    findTwoMins(&B[0][0], N, minB, br1, bc1, br2, bc2);

    cout << "Min of A is " << minA << " on ("
         << ar1 << ", " << ac1 << ") and ("
         << ar2 << ", " << ac2 << ")\n";
    cout << "Min of B is " << minB << " on ("
         << br1 << ", " << bc1 << ") and ("
         << br2 << ", " << bc2 << ")\n";

    // Поменять местами
    //минимальные элементы матриц А и В.
    A[ar1][ac1] = A[ar2][ac2] = minB;
    B[br1][bc1] = B[br2][bc2] = minA;

    cout << "A matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(2) << A[i][j];
        }
        cout << endl;
    }
    cout << "B matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(2) << B[i][j];
        }
        cout << endl;
    }

    return 0;
}

