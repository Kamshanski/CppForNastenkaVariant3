//
// Оформить функцию поиска номера последнего нулевого элемента в
//массиве, В главной программе Дано 3 одномерных массива a,b,c длиной 20 элементов
//каждый. Применить функцию для каждого из 3-х заданных массивов. Найти сумму
//найденных номеров элементов. (в функции не должно быть операторов ввода или
//вывода)
#include "../everything.h"

int findLastZeroIndex(int* array, int size) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] == 0)
            index = i;
    }
    return index;
}

int randInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    int size = 20;
    int* a = new int[size];
    int* b = new int[size];
    int* c = new int[size];
    for (int i = 0; i < size; ++i) {
        a[i] = randInt(0, 3);
        b[i] = randInt(0, 3);
        c[i] = randInt(0, 3);
    }

    cout << "a: [";
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << a[i];
    }
    double aIndex = findLastZeroIndex(a, size);
    cout << "] index of last zero is " << aIndex << endl;

    cout << "b: [";
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << b[i];
    }
    double bIndex = findLastZeroIndex(b, size);
    cout << "] index of last zero is " << bIndex << endl;

    cout << "c: [";
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << c[i];
    }
    double cIndex = findLastZeroIndex(c, size);
    cout << "] index of last zero is " << cIndex << endl;


    cout << "Sum of indexes: " << aIndex + bIndex + cIndex << endl;

    return 0;
}

