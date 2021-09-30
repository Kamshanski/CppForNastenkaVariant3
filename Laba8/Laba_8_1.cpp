//
// Оформить функцию поиска количества элементов равных 5 . В главной
//программе дано 3 одномерных массива p,q,r длиной 10 элементов каждый. Применить
//функцию для каждого из 3-х заданных массивов. (в функции не должно быть
//операторов ввода или вывода)
#include "../everything.h"

int countFives(int* array, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == 5)
            count++;
    }
    return count;
}

int randInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    int size = 10;
    int* p = new int[size];
    int* q = new int[size];
    int* r = new int[size];
    for (int i = 0; i < size; ++i) {
        p[i] = randInt(0, 8);
        q[i] = randInt(0, 8);
        r[i] = randInt(0, 8);
    }

    cout << "p: [";
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << p[i];
    }
    cout << "] contains " << countFives(p, size) << " fives." << endl;

    cout << "q: [";
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << q[i];
    }
    cout << "] contains " << countFives(q, size) << " fives." << endl;

    cout << "r: [";
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << r[i];
    }
    cout << "] contains " << countFives(r, size) << " fives." << endl;

    return 0;
}

