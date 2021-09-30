//
//  Описать функцию типа void с передачей параметров по ссылке или
//указателю ShiftLeft(A, В, С), выполняющую левый циклический .сдвиг: значение А
//переходит в С, значение С — в В, значение В — в А (А, В, С — вещественные
//параметры, являющиеся одновременно входными и выходными). С помощью этой
//функции в главной программе выполнить левый циклический сдвиг для двух данных
//наборов из трех чисел: (А1, В1, С1) и (А2, В2, С2)
#include "../everything.h"

// Передача по ссылке
void ShiftLeft(int& a, int& b, int& c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}


int main() {
    int a, b, c;
    a = 1; b = 2; c = 3;
    cout << "(" << a << ", " << b << ", " << c << ") -> ";
    ShiftLeft(a,b,c);
    cout << "(" << a << ", " << b << ", " << c << ")" << endl;

    a = 5; b = 9; c = 4;
    cout << "(" << a << ", " << b << ", " << c << ") -> ";
    ShiftLeft(a,b,c);
    cout << "(" << a << ", " << b << ", " << c << ")" << endl;
return 0;
}

