//
// Дана строка текста. Известно, что в ней есть один элемент равный ‘a’,
//найти где он находится и упорядочить по алфавиту элементы , расположенные за этим
//элементом = ‘a’.
//
#include "../everything.h"

string randomString(int size) {
    static string CHARS = "bcdefghijklmnopqrs123456789";

    ostringstream o;

    for (int i = 0; i < size; ++i) {
        o << CHARS[rand() % CHARS.size()];
    }
    return o.str();
}

void selectionSort(char *arr, int size, bool asc = true) {
    if (size < 2) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        char extremum = arr[i]; // max for asc or min for desc
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (!(asc ^ (extremum > arr[j]))) { //extremum if asc and bigger or desc and smaller
                extremum = arr[j];
                index = j;
            }
        }
        char temp = arr[i];
        arr[i] = extremum;
        arr[index] = temp;
    }
}

int main() {
    // создать слово
    string word = randomString(17);
    int actualIndexOfA = rand() % word.size();
    word[actualIndexOfA] = 'a';
    cout << "Initial string: " << word << endl;

    // найти индекс буквы "а"
    int aIndex = -1;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == 'a') {
            aIndex = i;
            break;
        }
    }
    if (aIndex < 0) {
        cout << "Letter 'a' is not found!";
        return 0;
    }

    // сортировка элементов после буквы а
    selectionSort(&word[aIndex+1], word.size() - aIndex - 1);

    cout << "Processed string: " << word << endl;

    return 0;
}

