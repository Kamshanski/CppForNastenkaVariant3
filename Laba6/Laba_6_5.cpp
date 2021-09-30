//
// Определить комбинированный (структурный) тип для представления
//информации по горным вершинам, состоящей из названия вершины и ее высоты. Ввести
//информацию по 10 вершинам. Вывести название самой высокой вершины из всех 10.
//Затем вывести информацию, отсортированную по возрастанию высоты вершины.
//(рационально переставлять все поля структуры разом )
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

int randInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void selectionSort(Mountain *arr, int size, bool asc = true) {
    if (size < 2) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        Mountain extremum = arr[i]; // max for asc or min for desc
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (!(asc ^ (extremum.height > arr[j].height))) { //extremum if asc and bigger or desc and smaller
                extremum = arr[j];
                index = j;
            }
        }
        Mountain temp = arr[i];
        arr[i] = extremum;
        arr[index] = temp;
    }
}


int main() {
    //  Ввести информацию по 20 вершинам
    Mountain array[] = {
            Mountain("Dykh-Tau", 5205 ),
            Mountain("Mishrigi", 5019 ),
            Mountain("Kazbek", 5034 ),
            Mountain("Jangi-Tau", 5085 ),
            Mountain("Kukurtlu", 4978 ),
            Mountain("Elbrus", 5642 ),
            Mountain("Koshtan-Tau", 5152 ),
            Mountain("Pik Pushkina", 5100 ),
            Mountain("Shkhara", 5193 ),
            Mountain("Katyn-Tau", 4979 ),
    };
    // Размер статического массива = размер массива / размер одного элемента
    int size = sizeof(array) / sizeof(Mountain);

    // Вывод массива
    cout << "Initial array:"<< endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << endl;
    }
    cout << endl;

    // Вывести название самой высокой вершины из всех 10.
    // Затем вывести информацию, отсортированную по возрастанию высоты вершины.
    selectionSort(array, size);

    cout << "Largest mountain is " << array[size - 1] << endl<<endl;

    // Ввести массив
    cout << "Processed array:"<< endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << endl;
    }
    cout << endl;

    return 0;
}

