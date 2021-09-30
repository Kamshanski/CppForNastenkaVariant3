//
// Создать динамические массивы, используя указатели. Дан двумерный
//массив a, размером (nn). Упорядочить по возрастанию параллель главной диагонали
//расположенной над диагональю.
//
#include "../everything.h"

void selectionSort(double *arr, int size, bool asc = true) {
    if (size < 2) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        double extremum = arr[i]; // max for asc or min for desc
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (!(asc ^ (extremum > arr[j]))) { //extremum if asc and bigger or desc and smaller
                extremum = arr[j];
                index = j;
            }
        }
        double temp = arr[i];
        arr[i] = extremum;
        arr[index] = temp;
    }
}

int main() {
    int N = 0;
    bool firstRead = true;
    do {
        if (!firstRead)
            cout << "N cannot be lower than 2. Try Again.\n";
        cout << "Enter N:\n";
        cin >> N;
        firstRead = false;
    } while (N < 2); // Размер матрицы как минимум 2.

    // создать матрицу
    double** a = new double*[N];
    for (int i = 0; i < N; ++i) {
        a[i] = new double[N];

        // заполнить матрицу
        for (int j = 0; j < N; ++j) {
            a[i][j] = (rand() % 65) - 32; // -32..32
        }
    }

    // вывести массив в терминал
    cout << "Initial matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(6) << a[i][j];
        }
        cout << endl;
    }

    // Упорядочить по возрастанию пятую строку матрицы.
    int diagonalSize = N - 1;
    double* diagonal = new double[diagonalSize];    // Отдельный массив для диагонали
    for (int i = 0; i < diagonalSize; ++i) {
        diagonal[i] = a[i][i+1];
    }
    selectionSort(diagonal, diagonalSize);
    for (int i = 0; i < diagonalSize; ++i) {
        a[i][i+1] = diagonal[i];
    }


    // вывести массив в терминал
    cout << "Processed matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(6) << a[i][j];
        }
        cout << endl;
    }

    // Чистка памяти
    delete[] diagonal;
    for (int i = 0; i < N; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

