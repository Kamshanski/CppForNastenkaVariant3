//
// Создать динамические массивы, используя указатели. Дан двумерный
//массив a, размером (nm). Найти минимальный элемент в каждой строке матрицы.
//Затем каждую строку матрицы разделить на минимальный элемент строки.
//
#include "../everything.h"

int main() {
    int N, M;
    cout << "Enter N:\n";
    cin >> N;
    cout << "Enter M:\n";
    cin >> M;
    // создать матрицу
    double** a = new double*[N];
    for (int i = 0; i < N; ++i) {
        a[i] = new double[M];

        // заполнить матрицу
        for (int j = 0; j < M; ++j) {
            a[i][j] = (rand() % 65) - 32; // -32..32
        }
    }

    // вывести массив в терминал
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << setw(6) << a[i][j];
        }
        cout << endl;
    }

    // найти минимальные элементы в каждой строке
    double* minElement = new double[N];
    for (int i = 0; i < N; ++i) {
        minElement[i] = INT_MAX;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (minElement[i] > a[i][j]) {
                minElement[i] = a[i][j];
            }
        }
    }

    // Вывести матрицу и минимальные элементы каждой строки
    cout << "Min elements of each row: " << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << setw(6) << a[i][j];
            a[i][j] /= minElement[i];   // каждую строку матрицы разделить на минимальный элемент строки
        }
        cout << " -> " << setw(3) << minElement[i] << endl;
    }

    // вывести массив в терминал
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << setw(6)<< std::setprecision(2)  << a[i][j];
        }
        cout << endl;
    }

    // Чистка памяти
    for (int i = 0; i < N; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

