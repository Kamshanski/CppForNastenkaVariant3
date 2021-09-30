//
// Создать комбинированный (структурный) тип для расписания экзаменов и
//зачетов (предмет, вид отчетности, число, преподаватель). Описать процедуру
//сортировки по фамилии преподавателя в одном таком комбинированном массиве.
//Пользователь задает два комбинированных массива по N элементов в каждом.(для
//зимней и летней сессий). Применить функцию два раза для заданных двух сессий. . (Так
//же будет уместно описать процедуру ввода комбинированного массива и процедуру
//вывода.)

#include "../everything.h"

struct Exam {
    string subject;
    string examType;
    int day;
    string professor;

    friend ostream &operator<<(ostream &os, const Exam &exam) {
        os << "" << exam.subject << ", " << exam.examType << ", " << exam.day << ", " << exam.professor;
        return os;
    }

    Exam(const string &subject, const string &examType, int day, const string &professor) :
            subject(subject),examType(examType),day(day),professor(professor) {}
};

// Описать процедуру
//сортировки по фамилии преподавателя в одном таком комбинированном массиве
void selectionSort(Exam**arr, int size, bool asc = true) {
    if (size < 2) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        Exam* extremum = arr[i]; // max for asc or min for desc
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (!(asc ^ (extremum->professor > arr[j]->professor))) { //extremum if asc and bigger or desc and smaller
                extremum = arr[j];
                index = j;
            }
        }
        Exam* temp = arr[i];
        arr[i] = extremum;
        arr[index] = temp;
    }
}


void read(Exam**& array, int N) {
    string subject;
    string examType;
    int day;
    string professor;
    cout << "Enter " << N << " items to the array:\n";
    for (int i = 0; i < N; ++i) {
        cin >> subject >> examType >> day >> professor;
        array[i] = new Exam(subject, examType, day, professor);
    }
}

void print(Exam** array, int N) {
    for (int i = 0; i < N; ++i) {
        cout << *array[i] << endl;
    }
}

/*
4
Math Exam 5 Alexin
Physics Exam 9 Veradsky
Chemistry Exam 29 Sankov
Math Exam 6 Yuriev
Physics Exam 15 Antohin
Physics Exam 7 Alexin
Chemistry Exam 24 Dzerzhinky
Math Exam 1 Kulibin
 */
int main() {
    int N;
    cout << "Enter arrays size:\n";
    cin >> N;

    Exam** exams1 = new Exam*[N];
    Exam** exams2 = new Exam*[N];

    // Пользователь задает два комбинированных массива по N элементов в каждом
    read(exams1, N);
    read(exams2, N);

    // Применить функцию два раза для заданных двух сессий.
    selectionSort(exams1, N);
    selectionSort(exams2, N);

    cout << "First array: \n";
    print(exams1, N);

    cout << endl << "Second array: \n";
    print(exams2, N);

    return 0;
}

