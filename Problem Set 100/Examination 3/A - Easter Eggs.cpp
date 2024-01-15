//
// Created by Stephen Ni on 2024-01-14.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 7) {
        cout << "ROYGBIV";
    } else if(n == 8) {
        cout << "ROYGBIVG";
    } else if(n == 9) {
        cout << "ROYGBIVGB";
    } else if(n == 10) {
        cout << "ROYGBIVGBI";
    } else if(n == 11) {
        cout << "ROYGBIVGBIV";
    } else {
        int n2 = n;

        n2 -= 7;
        cout << "ROYGBIV";

        int num = 1;
        unordered_map<int, char> flags;

        flags[1] = 'R';
        flags[2] = 'O';
        flags[3] = 'Y';
        flags[4] = 'G';

        while(n2 > 4) {
            cout << flags[num];
            num++;
            n2--;

            if(num > 4) {
                num = 1;
            }
        }

        if(num == 1) {
            cout << "BOIV";

        } else if(num == 2) {
            cout << "BOIV";

        } else if(num == 3) {
            cout << "YBIV";
        } else {
            cout << "VIBG";
        }
    }

    return 0;
}