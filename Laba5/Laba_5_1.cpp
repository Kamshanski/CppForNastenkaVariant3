//
// Задан список из десяти городов. (массив [.] string)Поменять местами
//название последнего города таблицы и последнего города, начинающегося с буквы «к».
//
#include "../everything.h"

int main() {
    string cities[] = {
            "Almetyevsk",
            "Pskov",
            "Novgorod",
            "Tomsk",
            "Gagarin",
            "Kemerovo",
            "Yuzhno-Sakhalinsk",
            "Ivan-gorod",
            "Cheboksary",
            "Kargopol"
    };
    // Размер статического массива = размер массива / размер одного элемента
    int citiesSize = sizeof(cities) / sizeof(string);

    // Вывод массива
    cout << "Initial array:"<< endl;
    for (int i = 0; i < citiesSize; ++i) {
        cout << cities[i] << endl;
    }


    // найти последний город к буквой "к" на конце
    int indexOfLastCityThatEdsWithK = -1;
    for (int i = 0; i < citiesSize; ++i) {
        if (cities[i][cities[i].size() - 1] == 'k') {
            indexOfLastCityThatEdsWithK = i;
        }
    }
    if (indexOfLastCityThatEdsWithK < 0) {
        cout << "City with last 'K' latter are not found";
        return 0;
    }

    // Поменять местами название последнего города таблицы
    // и последнего города, начинающегося с буквы «к»
    string temp = cities[citiesSize - 1];
    cities[citiesSize - 1] = cities[indexOfLastCityThatEdsWithK];
    cities[indexOfLastCityThatEdsWithK] = temp;

    // Вывод массива
    cout << endl << "Processed array:"<< endl;
    for (int i = 0; i < citiesSize; ++i) {
        cout << cities[i] << endl;
    }

    return 0;
}

