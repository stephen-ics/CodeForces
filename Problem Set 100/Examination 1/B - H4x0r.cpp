//
// Created by Stephen Ni on 2023-12-28.
//

#include<iostream>
#include<string>

using namespace std;

int main() {
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'a') {
            cout << 4;
        } else if(str[i] == 'i') {
            cout << 1;
        } else if(str[i] == 'e') {
            cout << 3;
        } else if(str[i] == 'o') {
            cout << 0;
        } else if(str[i] == 's') {
            cout << 5;
        }
        else {
            cout << str[i];
        }
    }

    return 0;
}