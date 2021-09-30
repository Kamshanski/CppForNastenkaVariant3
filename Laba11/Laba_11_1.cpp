//
// Описать рекурсивную функцию для вычисления n –го члена ряда 6, 3, 3/2,
//¾, 3/8, … 3/256
#include "../everything.h"

double sequence(int n) {
    return (n == 0) ? 6 : sequence(n-1)/2;
}

int main() {
    for (int i = 0; i < 7; ++i) {
        cout << "n = " << i << ": " << sequence(i) << endl;
    }

    return 0;
}

