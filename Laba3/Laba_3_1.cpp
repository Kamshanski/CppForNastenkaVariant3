//
// Даны два слова по 8 символов (две переменные).. Сколько раз во втором
//слове встречается последняя буква первого слова. (не использовать find, erase, substr…)
//
#include "../everything.h"

string randomString(int size) {
    static string CHARS = "abcdefg";

    ostringstream o;

    for (int i = 0; i < size; ++i) {
        o << CHARS[rand() % CHARS.size()];
    }
    return o.str();
}

int main() {
    // создать слова
    string word1 = randomString(8);
    string word2 = randomString(8);
    cout << "Word 1: " << word1 << endl;
    cout << "Word 2: " << word2 << endl;

    // Сколько раз во втором слове встречается последняя буква первого слова.
    char lastChar = word1[word1.size() - 1];
    int count = 0;
    for (int i = 0; i < word2.size(); ++i) {
        if (word2[i] == lastChar) {
            count++;
        }
    }
    cout << "Char '" << lastChar << "' was found " << count << " times";

    return 0;
}

