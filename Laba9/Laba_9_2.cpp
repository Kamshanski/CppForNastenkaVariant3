//
//  Реализовать функцию типа void с передачей параметров-результатов
//по ссылке. Функция вычисляет характеристики прямоугольника по заданным двум
//сторонам . Выходные результаты функции – Характеристики прямоугольника – это
//периметр, диагональ и площадь . В главной программе задано два прямоугольника .
//Найти их характеристики, вызвав функцию 2 раза.
#include "../everything.h"

// Передача по ссылке
void rectangularParams(double& a,
                       double& b,
                       double& perimeter,
                       double& diagonal,
                       double& area) {
    diagonal = sqrt(pow(a, 2) + pow(b, 2));
    perimeter = 2 * a + 2 * b;
    area = a*b;
}


int main() {
    double a, b, perimeter, diagonal, area;
    a = 1; b = 1;
    rectangularParams(a, b, perimeter, diagonal, area);
    cout << endl << "[1, 1] -> diagonal:  "<< diagonal << ", perimeter: " << perimeter << " area: " << area << endl;
    a = 3; b = 4;
    rectangularParams(a, b, perimeter, diagonal, area);
    cout << endl << "[3, 4] -> diagonal:  "<< diagonal << ", perimeter: " << perimeter << " area: " << area << endl;
    return 0;
}

