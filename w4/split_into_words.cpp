#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Напишите функцию SplitIntoWords, разбивающую строку на слова по пробелам.
*/


vector<string> SplitIntoWords(const string& s) {
    vector<string> res;

    auto s_start = begin(s);
    auto s_end = begin(s);

    while (s_end != end(s)) {
        s_end = find_if(s_start, end(s), [](char a) {return a == ' '; } );
        res.push_back({s_start, s_end});
        s_start = s_end;
        ++s_start;
    }
    return res;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}