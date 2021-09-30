//
// Даны 3 слова в 3-х разных переменных. Образовать новую последовательность
//символов, состоящую из первых букв каждого слова. (слитно без пробелов).
//(использовать склейку «+»)(не использовать find, erase, substr…)
//
#include "../everything.h"

string randomString(int size) {
    static string CHARS = "abcdefghijklmnopqrstuvwxyz";

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
    string word3 = randomString(8);
    cout << "Word 1: " << word1 << endl;
    cout << "Word 2: " << word2 << endl;
    cout << "Word 3: " << word3 << endl;

    // Образовать новую последовательность
    //символов, состоящую из первых букв каждого слова
    string newWord;

    newWord += word1[0];
    newWord += word2[0];
    newWord += word3[0];
    cout << "New word : " << newWord << endl;

    return 0;
}

