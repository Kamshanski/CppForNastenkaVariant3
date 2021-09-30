//
// Дан список фамилий сотрудников. (массив [.] string). Переписать в другой
//список только те фамилии, которые заканчиваются на ‘в’. Затем упорядочить по
//алфавиту второй список методом «пузырька»
//
#include "../everything.h"

int main() {
    string names[] = {
            "Teterin",
            "Kolobov",
            "Subbotin",
            "Fokin",
            "Blohin",
            "Seliverstov",
            "Pestov",
            "Kondrat'ev",
            "Silin",
            "Merkushev",
            "Lytkin",
            "Turov",
    };
    // Размер статического массива = размер массива / размер одного элемента
    int size = sizeof(names) / sizeof(string);

    // Вывод массива
    cout << "Initial array:"<< endl;
    for (int i = 0; i < size; ++i) {
        cout << names[i] << endl;
    }


    // Переписать в другой список только те фамилии, которые заканчиваются на ‘в’.
    string* names2 = new string[size];
    int size2 = 0;
    for (int i = 0; i < size; ++i) {
        if (names[i][names[i].size() - 1] == 'v') {
            names2[size2++] = names[i];
        }
    }

    //  Затем упорядочить по алфавиту второй список методом «пузырька»
    bool isSorted = false;
    string buf;
    while(!isSorted) {
        isSorted = true;
        for (int i = 0; i < size2-1; i++) {
            if(names2[i] > names2[i+1]){
                isSorted = false;

                buf = names2[i];
                names2[i] = names2[i+1];
                names2[i+1] = buf;
            }
        }
    }


    // Вывод итогового массива
    cout << endl << "Processed array:"<< endl;
    for (int i = 0; i < size2; ++i) {
        cout << names2[i] << endl;
    }

    return 0;
}

