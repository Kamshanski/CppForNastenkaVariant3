//
// .Создать функцию типа void для поиска max и его номера в массиве . В главной
//программе Даны три вектора(массива) x(n),y(n),z(n). Вызвать 3 раза функцию типа void.
//Далее Если наибольший элемент вектора x равен 7 и находится во 2-ой половине этого
//вектора и если в векторе y наибольший элемент равен 100, тогда все элементы вектора z
//, последующие за его наибольшим элементом, заменить на их модули.

#include "../everything.h"

// Передача по ссылке
void findMax(double* array, int size, double& max, int& maxIndex) {
    double maxElem = -DBL_MAX;
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > maxElem) {
            maxElem = array[i];
            index = i;
        }
    }
    maxIndex = index;
    max = maxElem;
}


int main() {
    // Даны три вектора(массива) x(n),y(n),z(n).
    int N = 6;
    double x[] = {5,  1,  4,  3,  4,   7 };
    double y[] = {7,  1,  2,  -3, 100, 5 };
    double z[] = {-1, 2,  5,  -3, 4,   -3};
    // Вызвать 3 раза функцию типа void
    double xMax, yMax, zMax;
    int xIndex, yIndex, zIndex;
    findMax(&x[0], N, xMax, xIndex);
    findMax(&y[0], N, yMax, yIndex);
    findMax(&z[0], N, zMax, zIndex);

    cout << "Max of x[] is " << xMax << " on " << xIndex <<" position " << endl;
    cout << "Max of y[] is " << yMax << " on " << yIndex <<" position " << endl;
    cout << "Max of z[] is " << zMax << " on " << zIndex <<" position " << endl;

    // Далее Если наибольший элемент вектора x равен 7 и находится во 2-ой половине этого
    //вектора и если в векторе y наибольший элемент равен 100, тогда все элементы вектора z
    //, последующие за его наибольшим элементом, заменить на их модули.
    if (xMax == 7 && ((((double)N) / 2.0) <= ((double)xIndex)) && yMax == 100) {
        for (int i = zIndex + 1; i < N; ++i) {
            z[i] = abs(z[i]);
        }
        cout << "Task criteria is true, all items after max item in Z " << zMax
             << " are replaced with abs" << endl;
        cout << "z [ ";
        for (int i = 0; i < N; ++i) {
            cout << z[i] << ' ';
        }
        cout << "]";
    }

    return 0;
}

