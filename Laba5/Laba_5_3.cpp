//
// Задан список из десяти городов. (массив [.] string). Присвоить переменной
//g название города с максимальным числом букв
//
#include "../everything.h"

int main() {
    string cities[] = {
            "Almetyevsk",
            "Pskov",
            "Novgorod",
            "Gagarin",
            "Tomsk",
            "Kemerovo",
            "Yuzhno-Sakhalinsk",
            "Ivan-gorod",
            "Cheboksary",
            "Kargopol",
    };
    // Размер статического массива = размер массива / размер одного элемента
    int citiesSize = sizeof(cities) / sizeof(string);

    // Вывод массива
    cout << "Initial array:"<< endl;
    for (int i = 0; i < citiesSize; ++i) {
        cout << cities[i] << endl;
    }


    // найти последний город к буквой "к" на конце
    int index = -1;
    int maxCounter = 0;
    for (int i = 0; i < citiesSize; ++i) {
        int counter = 0;
        size_t citySize = cities[i].size();
        for (int j = 0; j < citySize; ++j) {
            char ch = cities[i][j];
            if (ch == 'g' || ch == 'G') {
                counter++;
            }
        }
        if (maxCounter < counter) {
            maxCounter = counter;
            index = i;
        }
    }
    if (index < 0) {
        cout << "No city that comprises letter 'g' was found";
        return 0;
    } else {
        cout << "City with the largest number of letter 'g' is " << cities[index];
    }


    return 0;
}

