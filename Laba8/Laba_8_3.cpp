//
// Описать функцию, вычисляющую количество слов «Иванушка» в
//тексте. В главной программе дано 3 текста S1 и S2 и S3. Выяснить, в каком тексте
//больше слов «Иванушка», используя функцию.
#include "../everything.h"


double countIvanushka(string& input) {
    int index = 0;
    int count = 0;
    string ivan = "Ivanushka";
    while (index < input.size()) {
        index = input.find(ivan, index);
        if (index == string::npos)
            break;
        count++;
        index++;
    }
    return count;
}

int maxIndexOf(int a, int b, int c) {
    if (a >= b && a >= c) {
        return 0;
    }
    if (b >= a && b >= c) {
        return 1;
    }
    return 2;
}

int main() {
    // src: https://chto-takoe-lyubov.net/stikhi-pro-ivanushku-durachka/
    string S1 = string("Poslushaj, Ivanushka-durachok,\n") +
                 "Pust' Osen' celuetsya goryacho,\n" +
                 "No ty pogodi -\n" +
                 "Za nej ne hodi.\n" +
                 "Pomni, Ivanushka-durachok,\n" +
                 "Sledom za Osen'yu - vsadnik s mechom.";

    string S2 = string("SHeptal ej Ivanushka-durachok.\n") +
                 "Mol, duraku, dazhe smert' ni po chem.";

    string S3 = string("Prochitav ves' tekst na kamne, Vanya molcha otoshel.\n") +
            "Posmotrel napravo, pryamo, vlevo vzglyad on perevel.\n"+
            "Na sekundu rasteryavshis', Vanya repu pochesal,\n"+
            "Na konya opyat' vskochil i nalevo poskakal.";

    int count1 = countIvanushka(S1);
    cout << S1 << endl << "/\\ contains " << count1 << " Ivanushka /\\\n\n";
    int count2 = countIvanushka(S2);
    cout << S2 << endl << "/\\ contains " << count2 << " Ivanushka /\\\n\n";
    int count3 = countIvanushka(S3);
    cout << S3 << endl << "/\\ contains " << count3 << " Ivanushka /\\\n\n";

    cout << "The ";
    int textIndex = maxIndexOf(count1, count2, count3);
    switch (textIndex) {
        case 0: cout << "first"; break;
        case 1: cout << "second"; break;
        case 2: cout << "third"; break;
    }
    cout << " test has the most Ivanushka in the text";


    return 0;
}

