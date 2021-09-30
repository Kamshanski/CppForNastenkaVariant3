//
// Смотри задание в методичке - там формулы
#include "../everything.h"

double sumOfCubes(double* array, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

double u(double* x, double* y, double* d, int size) {
    double ySum = sumOfCubes(y, size);
    double dSum = sumOfCubes(d, size);
    if (ySum > 0) {
        return sumOfCubes(x, size) - dSum;
    }
    return ySum / dSum;
}

int randInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    int size = 40;
    double * x = new double[size];
    double * y = new double[size];
    double * d = new double[size];
    for (int i = 0; i < size; ++i) {
        x[i] = randInt(0, 8);
        y[i] = randInt(0, 8);
        d[i] = randInt(0, 8);
    }

    cout << "x: [";
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << x[i];
    }
    cout << "]" << endl;

    cout << "y: [";
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << y[i];
    }
    cout << "]" << endl;

    cout << "y: [";
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << y[i];
    }
    cout << "]" << endl;

    cout << "u(x,y,d) = " << u(x,y,d, size);

    return 0;
}

