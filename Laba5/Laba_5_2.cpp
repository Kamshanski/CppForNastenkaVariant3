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


    // Присвоить переменной g название города с максимальным числом букв
    string g;
    int maxSize = 0;
    for (int i = 0; i < citiesSize; ++i) {
        if (maxSize < cities[i].size()) {
            maxSize = cities[i].size();
            g = cities[i];
        }
    }

    cout << "City with the largest size is " << g;



    return 0;
}

