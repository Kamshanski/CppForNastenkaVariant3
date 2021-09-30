//
//  Описать рекурсивную функцию для вычисления суммы первых k
//слагаемых. Входные параметры функции: х – вещественное и k – целое : см. методичку
#include "../everything.h"

double S(double x, int k) {
    return (k == 0)
        ? 0.
        : (k * cos(x * k) + S(x, k -1));
}

int main() {
    double x = 2;
    for (int i = 0; i < 7; ++i) {
        cout << "n = " << i << ": " << S(x, i) << endl;
    }

    return 0;
}

