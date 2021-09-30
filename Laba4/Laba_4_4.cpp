//
// Дана строка текста. Определить сколько раз встречается каждый символ в
//строке. Например: Пусть исходная строка Str: “x w x y x w” . Тогда “х” – встречается 3
//раза “y”- встречается 1 раз, “w”- встречается 2 разa. Далее удалить все слова
//«проблема».
//
#include "../everything.h"

string randomString(int size) {
    static string CHARS = "bcdefghijklmnopqrs";

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
    string problemStr = "problem";
    string word = randomString(17);
    int actualIndexOfInsertion = rand() % word.size();
    word.replace(actualIndexOfInsertion, 1, problemStr);
    cout << "Initial string: " << word << endl;

    // Определить сколько раз встречается каждый символ в строке.
    map<char, int> counter;

    // add all chars of str1 to counter map
    for (int i = 0; i < word.size(); ++i) {
        counter[word[i]] = 0;
    }

    for (int i = 0; i < word.size(); ++i) {
        auto c = word[i];
        if (counter.count(c)) {
            counter[c]++;
        }
    }

    for (auto const& entity: counter) {
        cout << "'" << entity.first<< "': " << entity.second << endl;
    }

    // Далее удалить все слова «проблема».
    int problemCounter = 0;
    unsigned long long index = 0;
    while (index < word.size()) {
        index = word.find(problemStr, index);
        if (index == string::npos)
            break;
        word.replace(index, problemStr.size(), "");
        problemCounter++;
        index = 0;
    }

    cout << "Processed string: " << word << endl;

    return 0;
}

