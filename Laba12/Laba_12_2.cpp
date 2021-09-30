//
// Дано 2 файла вещественных чисел а1.txt и а2.txt. Найти количество
//нулевых элементов в двух файлов
#include "../everything.h"

int countZerosIn(string path) {
    ifstream f(path);
    string s;
    int zeros = 0;
    cout << path << ": ";

    while (getline(f, s)) {
        double num = stod(s);
        cout << num << ' ';
        if (abs(num) == 0) {
            zeros++;
        }
    }
    cout << endl;
    f.close();
    return zeros;
}

int main() {
    ifstream f("..\\Laba12\\a1.txt");
    int zeros1 = countZerosIn("..\\Laba12\\a1.txt");
    int zeros2 = countZerosIn("..\\Laba12\\a2.txt");

    cout << "a1.txt contains " << zeros1 << " zeros\n";
    cout << "a2.txt contains " << zeros2 << " zeros\n";
    cout << "Total zeros: " << zeros1 + zeros2;
    return 0;
}

