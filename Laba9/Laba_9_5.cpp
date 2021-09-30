//
//  Дано 3 квадратные матрицы А,В и С. Вычислить квадрат той матрицы (А*А), в
//которой сумма элементов первого столбца наибольшая. Вычисление суммы элементов
//оформить в виде функции. Вычисление квадрата матрицы оформить в виде процедуры
#include "../everything.h"

double sumFirstColumn(double** matrix, int rows) {
    double sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += matrix[i][0];
    }
    return sum;
}

void square(double **M, int size, double** R) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            R[i][j] = 0;
            for (int k = 0; k < size; k++)
                R[i][j] += M[i][k] * M[k][j];
        }
    }
}

int randInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

double** createMatrix(int rows, int cols) {
    double **matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = randInt(0, 9);
        }
    }
    return matrix;
}

void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}



int main() {
    int size = 5;
    double** A = createMatrix(size, size);
    double** B = createMatrix(size, size);
    double** C = createMatrix(size, size);

    double sumA = sumFirstColumn(A, size);
    double sumB = sumFirstColumn(B, size);
    double sumC = sumFirstColumn(C, size);

    double** sqr = createMatrix(size, size);
    double** M = (sumA > sumB && sumA > sumC) ? A : (sumB > sumC) ? B : C;
    square(M, size, sqr);

    cout << "A:\n";
    printMatrix(A, size, size);
    cout << "B:\n";
    printMatrix(B, size, size);
    cout << "C:\n";
    printMatrix(C, size, size);

    cout << "A first column sum: " << sumA << endl;
    cout << "B first column sum: " << sumB << endl;
    cout << "C first column sum: " << sumC << endl;

    cout << "Square of matrix " << ((sumA > sumB && sumA > sumC) ? "A" : (sumB > sumC) ? "B" : "C") << ":\n";
    printMatrix(sqr, size, size);

    return 0;
}

