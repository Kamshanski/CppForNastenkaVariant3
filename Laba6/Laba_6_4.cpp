//
// Определить структурный тип, описывающий гостиничный номер (название
//гостиницы, номер, комфортность (люкс, полулюкс стандарт, эконом), количество
//человек, стоимость). Заполнить структурный массив 10-ю записями. Переписать из
//исходного массива в другой массив, информацию только о тех гостиничных номерах, в
//название гостиницы которых есть по 2 буквы «а». Затем новый массив отсортировать
//по названию гостиницы по алфавиту. (рационально переставлять все поля структуры
//разом )
//
#include "../everything.h"

const int LUXURY = 0;
const int HALF_LUXURY = 1;
const int STANDARD = 2;
const int ECONOMY = 3;

struct Room {
    string name;
    int number;
    int comfort;
    int guests;
    double price;

    Room() {}

    Room(const string &name, int number, int comfort, int guests, double price) : name(name), number(number),
                                                                                  comfort(comfort), guests(guests),
                                                                                  price(price) {}

    string getComfort() const {
        switch (comfort) {
            case LUXURY: return "LUXURY";
            case HALF_LUXURY: return "HALF_LUXURY";
            case STANDARD: return "STANDARD";
            case ECONOMY: return "ECONOMY";
            default: return "UNKNOWN";
        }
    }                                                                             
                                                                                  
    friend ostream &operator<<(ostream &os, const Room &room) {
        os << "name: " << room.name 
           << " number: " << room.number 
           << " comfort: " << room.getComfort()
           << " guests: " << room.guests 
           << " price: "
           << room.price;
        return os;
    }
};

int randInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void selectionSort(Room *arr, int size, bool asc = true) {
    if (size < 2) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        Room extremum = arr[i]; // max for asc or min for desc
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (!(asc ^ (extremum.name > arr[j].name))) { //extremum if asc and bigger or desc and smaller
                extremum = arr[j];
                index = j;
            }
        }
        Room temp = arr[i];
        arr[i] = extremum;
        arr[index] = temp;
    }
}

int main() {
    // Заполнить структурный массив 10-ю записями
    Room array[] = {
            Room("Rosa", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
            Room("Saigon", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
            Room("Dragon", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
            Room("Casanero", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
            Room("Tomichka", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
            Room("Krasnaya Zvezda", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
            Room("Tutanhamon", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
            Room("Palundra", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
            Room("Amur", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
            Room("Super Star", randInt(100, 555), randInt(LUXURY, ECONOMY), randInt(1, 4), randInt(500, 7000)),
    };
    // Размер статического массива = размер массива / размер одного элемента
    int size = sizeof(array) / sizeof(Room);

    // Ввести массив
    cout << "Initial array:"<< endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << endl;
    }
    cout << endl;

    // Переписать из исходного массива в другой массив, информацию
    // только о тех гостиничных номерах, в
    // название гостиницы которых есть по 2 буквы «а».
    Room* rooms = new Room[size];
    int roomsSize = 0;
    for (int i = 0; i < size; ++i) {
        int counterOfA = 0;
        string& hotelName = array[i].name;
        for (int j = 0; j < hotelName.size(); ++j) {
            if (hotelName[j] == 'a') {
                counterOfA++;
            }
        }
        if (counterOfA == 2) {
            rooms[roomsSize++] = array[i];
        }
    }

    // Затем новый массив отсортировать по названию гостиницы по алфавиту.
    selectionSort(rooms, roomsSize);

    // Ввести массив
    cout << "Processed array:"<< endl;
    for (int i = 0; i < roomsSize; ++i) {
        cout << rooms[i] << endl;
    }
    cout << endl;

    return 0;
}

