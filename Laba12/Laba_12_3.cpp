//
// Организовать текстовый файл. Организовать замену символов в файле.
//"старый" символ и "новый" символ запрашиваются и вводятся с клавиатуры.(создавая
//новый дополнительный файл)
#include "../everything.h"


int main() {
    ifstream input("..\\Laba12\\text.txt");
    ofstream output("..\\Laba12\\text_filtered.txt");
    cout << "Initial file:\n";
    string s;
    string totalText;
    while (getline(input, s)) {
        totalText += s;
        totalText += "\n";
    }
    cout << totalText << endl;

    char oldCh, newCh;
    cout << "Enter char to replace:\n";
    cin >> oldCh;
    cout << "Enter new char:\n";
    cin >> newCh;

    for (int i = 0; i < totalText.size(); ++i) {
        if (totalText[i] == oldCh) {
            output << newCh;
        } else {
            output << totalText[i];
        }
    }

    input.close();
    output.close();
    return 0;
}

