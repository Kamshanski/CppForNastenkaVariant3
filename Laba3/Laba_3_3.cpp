//
// Имеется некоторая последовательность символов. Образовать новую
//последовательность, включив в нее символы исходной, кроме символов пробелов.
//(использовать склейку «+»)(не использовать find, erase, substr…)
//
#include "../everything.h"

string randomString(int size) {
    static string CHARS = "abcdefghijklmnopqrstuvwxyz        ";

    ostringstream o;

    for (int i = 0; i < size; ++i) {
        o << CHARS[rand() % CHARS.size()];
    }
    return o.str();
}

int main() {
    // создать слова
    string word = randomString(15);
    cout << "Initial word: " << word << endl;

    // Образовать новую
    // последовательность, включив в нее символы исходной, кроме символов пробелов.
    string newWord;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] != ' ') {
            newWord += word[i];
        }
    }
    cout << "New word: " << newWord << endl;

    return 0;
}

