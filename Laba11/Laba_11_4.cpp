//
//  Описать рекурсивную функцию для вычисления n –го члена ряда по
//формуле: : см. методичку
#include "../everything.h"

double T(int n) {
    return (n == 0)
        ? 2
        : (n == 1)
            ? 2
            : 3 * T(n-1) * pow(T(n-2), 5);
}

int main() {
    for (int i = 0; i < 7; ++i) {
        cout << "n = " << i << ": " << T(i) << endl;
    }

    return 0;
}

