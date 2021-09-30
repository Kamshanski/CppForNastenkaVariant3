//
// Организовать файл целых чисел . Определить наибольший элемент файла
//среди элементов файла номера которых кратны трем.
#include "../everything.h"


int main() {
    ifstream input("..\\Laba12\\integers.txt");
    string s;
    int count = 0;
    cout << "Nums that can be divided by 3: ";
    while (getline(input, s)) {
        int num = stoi(s);
        if (num != 0 && (num % 3 == 0)) {
            count++;
            cout << num << ' ';
        }
    }
    cout << endl;

    cout << "Total amount: " << count << " nums";

    input.close();
    return 0;
}

