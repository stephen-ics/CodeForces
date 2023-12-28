//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isVowel(string word, int index) {
    if(word[index] == 'a' || word[index] == 'e') {
        return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string word;
        cin >> word;

        for(int i = 0; i < n; i++) {
            if(i + 2 == word.length()) {
                cout << word[i] << word[i+1];
                i += 2;
            } else if(i + 3 == word.length()) {
                cout << word[i] << word[i+1] << word[i+2];
                i += 3;
            }
            else if(isVowel(word, i+3)) {
                cout << word[i] << word[i+1] << ".";
                i += 1;
            } else {
                cout << word[i] << word[i+1] << word[i+2] << ".";
                i += 2;
            }
        }

        cout << endl;
    }

    return 0;
}