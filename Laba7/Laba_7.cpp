#include "../everything.h"

// Создать функцию, которая определяет периметр треугольника по трем его
//сторонам. Для создаваемой функции: подобрать имя; указать тип функции; выбрать
//имена и типы входных параметров; описать тело функции с обязательным оператором в
//конце; в главной программе вызвать созданную функцию два раза с различными
//входными данными. Вывести результаты в главной программе.
double trianglePerimeter(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

void task1() {
    double a,b,c;
    a= 5; b = 6; c = 7;
    cout << "Triangle perimeter of (" << a << ", " << b << ", " << c << "): " << trianglePerimeter(a, b, c) << endl;
    a= 1.3; b = 6.2; c = 88;
    cout << "Triangle perimeter of (" << a << ", " << b << ", " << c << "): " << trianglePerimeter(a, b, c) << endl;
}

//Реализовать функцию . Функция вычисляет диагональ
//прямоугольника по заданным двум сторонам . В главной программе задано два
//прямоугольника . Найти их диагонали, вызвав функцию 2 раза.
double rectangleDiagonal(double a, double b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}

void task2() {
    double a,b;
    a= 3; b = 4;
    cout << "Rectangle diagonal of (" << a << ", " << b << "): " << rectangleDiagonal(a, b) << endl;
    a= 4.2; b = 6.5;
    cout << "Rectangle diagonal of (" << a << ", " << b << "): " << rectangleDiagonal(a, b) << endl;

}


//
//Описать функцию CircleS(R) вещественного типа, находящую площадь
//круга радиуса R (R — вещественное). С помощью этой функции найти площади трех
//кругов с данными радиусами. Площадь круга радиуса R вычисляется по формуле S =
//р*R^2. В качестве значения р использовать 3,14.
double CircleS(double R) {
    static const double pi = 3.14;
    return pi * pow(R, 2);
}

void task3() {
    double a;
    a= 3;
    cout << "Circle area of (" << a << "): " << CircleS(a) << endl;
    a= 5.6;
    cout << "Circle area of (" << a << "): " << CircleS(a) << endl;

}

//Даны действительные числа a, b. Получить u = min(a, b-a), y = min(ab, a+b),
//k = min(u+y^2, 3.14). Описать функции нахождения минимального числа из 2 заданных
//величин.
double u(double a, double b) {
    double dif = b-a;
    return dif < a ? dif : a;
}
double y(double a, double b) {
    double sum = b-a;
    double mul = b-a;
    return sum < mul ? sum : mul;
}
double k(double a, double b) {
    double q = u(a, b) + pow(y(a, b), 2);
    double p = 3.14;
    return q < p ? q : p;
}

void task4() {
    double a,b;
    a= 3; b = 4;
    cout << "k(" << a << ", " << b << "): " << k(a, b) << endl;
    a= 4.2; b = 6.5;
    cout << "k(" << a << ", " << b << "): " << k(a, b) << endl;

}


int main() {
    task1();
    task2();
    task3();
    task4();

    return 0;
}

