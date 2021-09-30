//
// Сформировать массив, каждый элемент которого имеет следующую
//структуру знакомый= фамилия: string; номертел:10000..99999; адрес:string;
//Вывести на экран сообщение пользователю вида:
//Выберете номер действия:
//1. загрузить все данные из файла на экран;
//2. ввести новые данные в файл ;
//3. добавить данных в конец файла;
//4. сортировка базы данных по алфавиту (по фамилии);
//5. есть ли в книжке телефон данного человека;
//6. определить кому принадлежит данный телефон;
//7. вывод: список людей, живущих на данной улице.;
//0--выход из программы;
//Ваш выбор___
//Основную программу организовать в виде цикла do – while «пока не выбран
//пункт 0—выход».
//Для вариантов выбора использовать оператор SWITCH - CASE.
//Каждый пункт меню (действие) оформить виде метода (подпрограммы-функции
//или подпрограммы-процедуры)
#include <ostream>
#include "../everything.h"

struct Person {
    string name;
    int phoneNum;
    string address;

    Person(const string &name, int phoneNum, const string &address) : 
            name(name), phoneNum(phoneNum), address(address) 
            {
                if (phoneNum < 10000 || phoneNum > 99999) {
                    cout << "Phone number must be in [10000, 99999]";
                    exit(1);
                }
            }

    Person() {}

    friend ostream &operator<<(ostream &os, const Person &person) {
        os << person.name << ", " << person.phoneNum << ", " << person.address;
        return os;
    }

};

void selectionSort(Person* arr, int size, bool asc = true) {
    if (size < 2) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        Person extremum = arr[i]; // max for asc or min for desc
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (!(asc ^ (extremum.name > arr[j].name))) { //extremum if asc and bigger or desc and smaller
                extremum = arr[j];
                index = j;
            }
        }
        Person temp = arr[i];
        arr[i] = extremum;
        arr[index] = temp;
    }
}

string FILE_PATH = "..\\Laba13\\people.txt";

Person* people = nullptr;
int size = 0;

fstream* openFile() {
    return new fstream(FILE_PATH);
}

void closeFile(fstream* f) {
    if (f != nullptr) {
        f->close();
        delete f;
    }
}

void clearFile() {
    ofstream f(FILE_PATH, ios::out | ios::trunc);
    if (f) {f.close();}// проверка доступности файла
    else {cout << "File is occupied by another process\n";}
}

void readFromFile() {
    fstream* f = openFile();
    if (*f) {// проверка доступности файла
        size = 0;
        while (!f->eof()) {
            Person *s = &people[size++];
            *f >> s->name >> s->phoneNum >> s->address;
        }
        closeFile(f);
    }else {
        cout << "File is occupied by another process\n";
    }
}


Person readPerson() {
    cout << "Enter: name phoneNumber(5 digits) address" << endl;
    Person s;
    cin >> s.name >> s.phoneNum >> s.address;
    return s;
}

void savePersons() {
    clearFile();
    fstream* f = openFile();
    if (*f) {   // проверка доступности файла
        for (int i = 0; i < size; ++i) {
            *f << people[i].name  << " "
               << people[i].phoneNum << " "
               << people[i].address;
            if (i != size - 1) {
                *f << endl;
            }
        }
        closeFile(f);
    } else {
        cout << "File is occupied by another process\n";
    }

}

void printAll() {
    for (int i = 0; i < size; ++i) {
        cout << setw(3) << i << ") " << people[i] << endl;
    }
}

void insertFirst() {
    Person s = readPerson();

    size++;
    for (int i = size; i > 0; --i) {
        people[i] = people[i-1];
    }
    people[0] = s;

    savePersons();
}

void insertLast() {
    Person s = readPerson();
    people[size++] = s;
    savePersons();
}

void sortDb() {
    selectionSort(people, size);
    savePersons();
    printAll();
}

void checkPhoneNum() {
    int phoneNum;
    cout << "Enter phone number:";
    cin >> phoneNum;
    for (int i = 0; i < size; ++i) {
        if (people[i].phoneNum == phoneNum) {
            cout << "This phone number is present in the contacts list" << endl;
            return;
        }
    }
    cout << "No people with such phone number" << endl;
}

void checkWhosePhoneNum() {
    int phoneNum;
    cout << "Enter phone number:";
    cin >> phoneNum;

    for (int i = 0; i < size; ++i) {
        if (people[i].phoneNum == phoneNum) {
            cout << people[i].name << endl;
            return;
        }
    }
    cout << "No people with this phone number" << endl;
}

void printPersonsOnStreet() {
    string street;
    cout << "Enter street: ";
    cin >> street;

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (people[i].address == street) {
            cout << people[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No people live on this street" << endl;
    }
}

void printMenu() {
    ostringstream o;
    o << "\nSelect your action:" << endl
      << "1. show all data from the file" << endl
      << "2. insert new data to the file" << endl
      << "3. add data to the end of the file" << endl
      << "4. sort database by name" << endl
      << "5. check if phone number exists..." << endl
      << "6. check who's owner of the phone number..." << endl
      << "7. print people who live on street..." << endl
      << "0. shutdown";
    string infoMsg = o.str();
    cout << infoMsg << endl;
    string yourChoiceMsg = "\nYour choice: ";
    cout << yourChoiceMsg;
}


int main() {
    people = new Person[50];
    readFromFile();

    bool mayExit = false;
    do {
        printMenu();

        char command;
        cin >> command;
        if (command >= '0' && command <= '7') {
            switch (command) {
                case '1': printAll(); break;
                case '2': insertFirst(); break;
                case '3': insertLast(); break;
                case '4': sortDb(); break;
                case '5': checkPhoneNum(); break;
                case '6': checkWhosePhoneNum(); break;
                case '7': printPersonsOnStreet(); break;
                case '0': mayExit = true; break;
            }
        } else {
            cout << "Unknown command. Try again" << endl;
        }
    } while (!mayExit);

    cout << endl << "Shutdown program" << endl;
    return 0;
}