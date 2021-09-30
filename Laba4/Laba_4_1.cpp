//
// Пользователь вводит текст . Вывести исходный текст, заменив в нем слово
//«Иванов И.И.» на «Сидоров А.А.». Заменить круглые скобки на фигурные, подсчитав
//их количество.
//
#include "../everything.h"

// {Everyone} knows that Ivanov I.I. is {the best} student
int main() {
    // создать слова
    string input;
    cout << "Enter a sentence: " << endl;
    getline(cin, input);

    // заменив в нем слово «Иванов И.И.» на «Сидоров А.А.»
    size_t index = 0;
    string ivanovStr = "Ivanov I.I.";
    string sidorovStr = "Sidorov A.A.";
    while (index < input.size()) {
        index = input.find(ivanovStr, index);
        if (index == string::npos)
            break;
        input.replace(index, ivanovStr.size(), sidorovStr);
        index = 0;
    }

    // Заменить круглые скобки на фигурные, подсчитав их количество.
    int openCount = 0;
    int closeCount = 0;
    index = 0;

    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '}') {
            input[i] = ')';
            closeCount++;
        } else if (input[i] == '{') {
            input[i] = '(';
            openCount++;
        }
    }

    cout << "Processed sentence: " << input << endl;
    cout << openCount << " '{' was replaced with '('" << endl;
    cout << closeCount << " '}' was replaced with ')'" << endl;



    return 0;
}

