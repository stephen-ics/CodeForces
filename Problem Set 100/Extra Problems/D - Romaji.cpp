//
// Created by Stephen Ni on 2024-01-15.
//

#include <iostream>
#include <string>

using namespace std;

bool checkVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') {
        return true;
    }

    return false;
}

int main() {
    string s;
    cin >> s;

    bool isVowel;
    bool isNextVowel;

    bool output = true;

    for(int i = 0; i < s.length() - 1; i++) {
        isVowel = checkVowel(s[i]);

        if(!isVowel) {
            isNextVowel  = checkVowel(s[i + 1]);

            if(isNextVowel) {
                i++;
            } else {
                if(s[i] != 'n') {
                    output = false;
                    break;
                }
            }
        }
    }

    if(!checkVowel(s[s.length() - 1]) && s[s.length() - 1] != 'n') {
        output = false;
    }

    if(output) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}