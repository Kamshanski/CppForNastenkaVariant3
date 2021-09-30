//
// В тексте заменить цифры на их словесные названия (использовать Case) (не
//использовать find)
//
#include "../everything.h"

string randomString(int size) {
    static string CHARS = "   abcdefghijklmnopqrstuvwxyz123456789";

    ostringstream o;

    for (int i = 0; i < size; ++i) {
        o << CHARS[rand() % CHARS.size()];
    }
    return o.str();
}

int main() {
    // создать слова
    string word = randomString(15);
    cout << "Initial string: " << word << endl;

    int wordSize = word.size();
    for (int i = wordSize - 1; i > 0; --i) {
        string replacement;
        switch (word[i]) {
            case '0': replacement = "zero"; break;
            case '1': replacement = "one"; break;
            case '2': replacement = "two"; break;
            case '3': replacement = "three"; break;
            case '4': replacement = "four"; break;
            case '5': replacement = "five"; break;
            case '6': replacement = "six"; break;
            case '7': replacement = "seven"; break;
            case '8': replacement = "eight"; break;
            case '9': replacement = "nine"; break;
            default: continue;
        }

        word.replace(i, 1, replacement);
    }


    cout << "Processed string: " << word << endl;

    return 0;
}

