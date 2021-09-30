//
// Определить комбинированный (структурный) тип для представления
//анкеты студента, состоящей из его фамилии, дня рождения и пола. «День рождения»
//состоит из полей: «число», «месяц», «год». Ввести информацию по 25 студентам из
//группы. Вывести фамилию самого старшего мальчика из группы.
//
#include "../everything.h"

struct Student {
    string name;
    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;
    bool sex; // false Male, true Female

    Student() {}

    Student(const string &name, int dayOfBirth, int monthOfBirth, int yearOfBirth, bool sex) :
            name(name), dayOfBirth(dayOfBirth),
            monthOfBirth(monthOfBirth),
            yearOfBirth(yearOfBirth),
            sex(sex) {}

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << student.name
           << ", " << student.dayOfBirth
           << "." << student.monthOfBirth
           << "."<< student.yearOfBirth 
           << ", " << ((student.sex) ? "Female" : "Male");
        return os;
    }
};

int randInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    Student array[] = {
            Student("Vadim", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Valentin", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Valery", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Vasily", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Veniamin", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Victor", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Vladimir", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Vladislav", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Vsevolod", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Timofey", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Sasha", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Simeon", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Simon", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Slava", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Stanislav", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Stepan", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Svetoslav", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Sviatoslav", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Yakov", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Yaroslav", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Yefim", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Yegor", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Yermolay", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Yevgeny", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
            Student("Yury", randInt(1, 29), randInt(1, 12), randInt(1995, 2002), (bool) randInt(0, 1)),
    };
    // Размер статического массива = размер массива / размер одного элемента
    int size = sizeof(array) / sizeof(Student);

    // Ввести информацию по 25 студентам из группы
    cout << "Initial array:"<< endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << endl;
    }
    cout << endl;

    //Вывести фамилию самого старшего мальчика из группы.
    Student oldestBoy;
    int maxYear = INT_MAX;
    int maxMonth = INT_MAX;
    int maxDay = INT_MAX;
    for (int i = 0; i < size; ++i) {
        if (!array[i].sex) { // MALE
            if (maxYear < array[i].yearOfBirth) {
                continue;
            } else if (maxYear == array[i].yearOfBirth) {
                if (maxMonth < array[i].monthOfBirth) {
                    continue;
                } else if (maxMonth == array[i].monthOfBirth) {
                    if (maxDay < array[i].dayOfBirth) {
                        continue;
                    }
                }
            }

            oldestBoy = array[i];
            maxYear = oldestBoy.yearOfBirth;
            maxMonth = oldestBoy.monthOfBirth;
            maxDay = oldestBoy.dayOfBirth;
        }
    }

    cout << endl << "The oldest boy is: " << oldestBoy << endl;\
    return 0;
}

