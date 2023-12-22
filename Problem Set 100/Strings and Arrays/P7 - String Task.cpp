//
// Created by Stephen Ni on 2023-12-22.
//

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// pre-condition: v is alphabetic ASCII, upper or lower case
bool isvowel(char v) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};

    for(int i = 0; i < 6; i++) {
        if (v == vowels[i]) {
            return true;
        }
    }
    return false;
}


int main() {
    string str;
    cin >> str;

    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    string consonants;

    for(int i = 0; i < str.length(); i++) {
        if(!isvowel(str[i])) {
            cout << "." << str[i];
        }
    };


    cout << consonants;

    return 0;
}