//
// Создать динамические массивы, используя указатели. Дан двумерный
//массив a, размером (nn)(или квадратная матрица а). Найти количество и сумму
//отрицательных элементов, нижней треугольной матрицы, расположенной ниже
//побочной диагонали, исключая саму побочную диагональ
//
#include "../everything.h"

int main() {
    int N;
    cout << "Enter N:\n";
    cin >> N;
    int count = 0; // количество отрицательных элементов
    double sum = 0; // суммa отрицательных элементов
    // создать матрицу
    double** a = new double*[N];
    for (int i = 0; i < N; ++i) {
        a[i] = new double[N];

        // заполнить матрицу
        for (int j = 0; j < N; ++j) {
            a[i][j] = (rand() % 65) - 32; // -32..32

            if ((i > N - j -1) && (a[i][j] < 0)) {
                count++;
                sum += a[i][j];
            }
        }
    }

    // вывести массив в терминал
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }

    cout << "Sum: " << sum << endl;
    cout << "Count: " << count << endl;


    // Чистка памяти
    for (int i = 0; i < N; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

