//
// Создать комбинированный (структурный) тип для меню ресторана
//"Дракон" (наименование изделия, вес, стоимость). Описать функцию нахождения
//общего веса изделий в одном таком комбинированном массиве. Пользователь задает два
//комбинированных массива по N элементов в каждом (для двух отделений ресторана).
//Применить функцию два раза для заданных двух отделений ресторана. . (Так же будет
//уместно описать процедуру ввода комбинированного массива и процедуру вывода.)
#include <ostream>
#include "../everything.h"

struct Food {
    string name;
    double weight;
    double price;

    Food(const string &name, double weight, double price) : name(name), weight(weight), price(price) {}

    friend ostream &operator<<(ostream &os, const Food &food) {
        os << food.name << ", " << food.weight << ", " << food.price;
        return os;
    }
};

double sumWeight(Food** array, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum+= array[i]->weight;
    }
    return sum;
}

void readFoodArray(Food**& array, int& size) {
    cout << "Enter number of elements and then enter elements one by one (name weight price)" << endl;
    cin >> size;
    array = new Food*[size];
    for (int i = 0; i < size; ++i) {
        string name;
        double weight;
        double price;
        cin >> name >> weight >> price;
        array[i] = new Food(name, weight, price);
    }
}

void printFoodArray(Food** array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *array[i] << endl;
    }
}

/*
5
Salad1 55 666
Salad2 44 45
Chips 67 578
Beer 424 759
Meat 756 2567
3
Vine 72 676
Cake 522 75
Salt 72 447

 */
int main() {
    int size1 = 0;
    int size2 = 0;
    Food** food1 = nullptr;
    Food** food2 = nullptr;

    readFoodArray(food1, size1);
    readFoodArray(food2, size2);

    cout << "first sum: " << sumWeight(food1, size1) << endl;
    cout << "second sum: " << sumWeight(food2, size2) << endl;


    return 0;
}

