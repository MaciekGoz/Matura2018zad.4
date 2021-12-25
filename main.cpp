#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int const N = 1000;

int differentChars(string s) {
    sort(s.begin(), s.end());
    int chars = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[i + 1]) {
            chars++;
        }
    }
    return chars;
}

int absoluteValue(int n) {
    if (n >= 0)
        return n;
    else
        return n + 2*(-n);
}

bool islessThan10(string s) {
    for (int i = 0; i < s.size()-1; i++) {
        if (absoluteValue(s[i] - s[i+1]) > 10)
            return false;
    }
    return true;
}

int main() {

    ifstream in("sygnaly.txt");
    ofstream out("wyniki4.txt");

    string przeslanie;

    int max = 0;
    string maxCharacters;

    out << "4.3" << endl;

    for (int i = 0; i <= N; i++) {
        string word;
        in >> word;

        if (i % 40 == 0) {
            przeslanie += word[9];
        }

        if (differentChars(word) > max) {
            max = differentChars(word);
            maxCharacters = word;
        }

        if (islessThan10(word))
            out << word << endl;
    }
    out << "4.1" << endl;
    out << przeslanie << endl;
    out << "4.2" << endl;
    out << maxCharacters << " " << max << endl;
}
