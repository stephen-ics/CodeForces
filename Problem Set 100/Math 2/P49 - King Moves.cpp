//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string pos;
    cin >> pos;

    char str = pos[0];
    char num = pos[1];

    if(str == 'b' || str == 'c' || str == 'd' || str == 'e' || str == 'f' || str == 'g') {
        if(num == '8' || num == '1') {
            cout << 5;
        } else {
            cout << 8;
        }
    } else if (str == 'a' || str == 'h') {
        if(num == '8' || num == '1') {
            cout << 3;
        } else {
            cout << 5;
        }
    } else {
        cout << 8;
    }



    return 0;
}