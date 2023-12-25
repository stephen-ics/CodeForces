//
// Created by Stephen Ni on 2023-12-25.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string inputStr;
    cin >> inputStr;

    int fours = 0;
    int sevens = 0;

    for(int i = 0; i < inputStr.length(); i++) {
        int num = inputStr[i] - '0';

        if(num == 4) {
            fours++;
        }
        if(num == 7) {
            sevens++;
        }
    }

    int luckyDigits = fours + sevens;
    string strLucky = to_string(luckyDigits);

    bool lucky = true;

    for(int i = 0; i < strLucky.length(); i++) {
        if(strLucky[i] != '4' && strLucky[i] != '7') {
            cout << "NO";
            lucky = false;
            break;
        }
    }

    if(lucky) {
        cout << "YES";
    }

    return 0;
}

