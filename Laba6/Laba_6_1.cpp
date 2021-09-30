//
// Определить комбинированный (структурный) тип для представления
//информации по горным вершинам, состоящей из названия вершины и ее высоты. Ввести
//информацию по 20 вершинам. Вывести среднее значение высот всех 20 вершин. Далее
//вывести названия всех вершин ниже среднего.
//
#include "../everything.h"

struct Mountain {
    string name;
    double height;

    Mountain(const string &name, double height) : name(name), height(height) {}

    friend ostream &operator<<(ostream &os, const Mountain &mountain) {
        os << "name: " << mountain.name << " height: " << mountain.height;
        return os;
    }
};

int main() {
    //  Ввести информацию по 10 вершинам
    Mountain mounts[] = {
            Mountain("Elbrus", 5642 ),
            Mountain("Dykh-Tau", 5205 ),
            Mountain("Shkhara", 5193 ),
            Mountain("Koshtan-Tau", 5152 ),
            Mountain("Pik Pushkina", 5100 ),

            Mountain("Jangi-Tau", 5085 ),
            Mountain("Kazbek", 5034 ),
            Mountain("Mishrigi", 5019 ),
            Mountain("Katyn-Tau", 4979 ),
            Mountain("Kukurtlu", 4978 ),

            Mountain("Pik Schota Rustaveli", 4960 ),
            Mountain("Gestola", 4860 ),
            Mountain("Dzhimara", 4780 ),
            Mountain("Klyuchevskoi", 4750 ),
            Mountain("Uilpata", 4649 ),

            Mountain("Kamen", 4619 ),
            Mountain("Tikhtengen", 4618 ),
            Mountain("Ailama", 4546 ),
            Mountain("Jailik", 4533 ),
            Mountain("Salynngantau", 4508 ),

    };
    // Размер статического массива = размер массива / размер одного элемента
    int size = sizeof(mounts) / sizeof(Mountain);


    // Вывести среднее значение высот всех 20 вершин
    double mean = 0;
    for (int i = 0; i < size; ++i) {
        mean += mounts[i].height;
    }
    mean /= size;
    cout << "Mean height is " << mean << endl << endl;


    // вывести названия всех вершин ниже среднего
    cout << "Mounts that are lower than " << mean << ": " << endl;
    for (int i = 0; i < size; ++i) {
        if (mounts[i].height < mean)
            cout << mounts[i].name << endl;
    }

    return 0;
}

