//
// Описать функцию типа void, сортировки одномерного массива длинной N
//по убыванию методом «Пузырька». В главной программе Дано два массива а и b.
//Отсортировать а и, b – по убыванию. Определить , что больше наименьший элемент а
//или наибольшей элемент b.

#include "../everything.h"

// Описать функцию типа void, сортировки одномерного массива длинной N
//по убыванию методом «Пузырька».
void bubbleSortDesc(double* array, int size) {
    bool isSorted = false;
    double buf;
    while(!isSorted) {
        isSorted = true;
        for (int i = 0; i < size-1; i++) {
            if(array[i] < array[i+1]){
                isSorted = false;

                buf = array[i];
                array[i] = array[i+1];
                array[i+1] = buf;
            }
        }
    }
}


int main() {
    // Дано два массива а и b.
    int N = 6;
    double a[] = {5,  1,  4,  3,  4,   7 };
    double b[] = {7,  1,  2,  -3, 100, 5 };

    //Отсортировать а и, b – по убыванию.
    bubbleSortDesc(&a[0], N);
    bubbleSortDesc(&b[0], N);

    cout << "a {";
    for (int i = 0; i < N; ++i) {
        cout << a[i] << ' ';
    }
    cout << '}' << endl;

    cout << "b { ";
    for (int i = 0; i < N; ++i) {
        cout << b[i] << ' ';
    }
    cout << '}' << endl;

    // Определить , что больше наименьший элемент а
    //или наибольшей элемент b.
    if (a[N-1] > b[0]) {
        cout << "min(a) > max(b)";
    } else if (a[N-1] < b[0]) {
        cout << "min(a) < max(b)";
    } else {
        cout << "min(a) == max(b)";
    }
    return 0;
}

