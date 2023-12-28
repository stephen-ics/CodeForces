//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    // just count amount of times each letter appears if not three print letter
    for(int i = 0; i < n; i++) {
        string square;
        for(int i = 0; i < 3; i++) {
            string subsquare;
            cin >> subsquare;
            square += subsquare;
        }

        int a = 0, b = 0, c = 0;

        for(int i = 0; i < square.length(); i++) {
            if(square[i] == 'A') {
                a++;
            } else if (square[i] == 'B') {
                b++;
            } else if (square[i] == 'C') {
                c++;
            }
        }

        if(a == 2) {
            cout << 'A';
        } else if (b == 2) {
            cout << 'B';
        } else {
            cout << 'C';
        }

        cout << endl;
    }


    return 0;
}