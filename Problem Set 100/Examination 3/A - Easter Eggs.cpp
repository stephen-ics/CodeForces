//
// Created by Stephen Ni on 2024-01-14.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    int num = 1;
    unordered_map<int, char> flags;

    flags[1] = 'R';
    flags[2] = 'O';
    flags[3] = 'Y';
    flags[4] = 'G';

    while(n > 3) {
        cout << flags[num];
        num++;
        n--;

        if(num > 4) {
            num = 1;
        }
    }

    cout << "BIV";

    return 0;
}