//
//  Описать рекурсивную функцию для вычисления ...
//(неиспользовать: x pow(x,n)) : см. методичку
#include "../everything.h"
const int LIMIT = 5;
double y(double x, int n = 1, double mul = 1, double root = 1) {
    if (n <= LIMIT) {
        mul = mul * x;
        root = sqrt(mul+root);
        n = n + 1;
        return y(x, n, mul, root);
    } else {
        return root;
    }
}

int main() {
    for (int i = 0; i < 7; ++i) {
        cout << "n = " << i << ": " << y(i) << endl;
    }

    return 0;
}

