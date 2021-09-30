//
// Дан файл вещественных чисел a.txt Найти количество нулевых элементов
//и сумму отрицательных элементов
#include "../everything.h"


int main() {
    ifstream f("..\\Laba12\\a.txt");
    string s;
    int zeros = 0;
    double negativeSum = 0;

    while (getline(f, s)) {
        double num = stod(s);
        cout << num << ' ';
        if (abs(num) == 0) {
            zeros++;
        }
        if (num < 0) {
            negativeSum += num;
        }
    }

    cout << endl << "Zeros: " << zeros << endl
         << "Sum of negative nums: " << negativeSum;
    f.close();
    return 0;
}

