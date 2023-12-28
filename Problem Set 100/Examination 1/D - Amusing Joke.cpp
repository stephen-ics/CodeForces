//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string guest, residence, scramble;
    cin >> guest >> residence >> scramble;

    if(guest.length() + residence.length() != scramble.length()) {
        cout << "NO";
    } else {
        string combined = guest + residence;
        sort(combined.begin(), combined.end());
        sort(scramble.begin(), scramble.end());

        bool possible = true;

        for(int i = 0; i < combined.length(); i++) {
            if(combined[i] != scramble[i]) {
                cout << "NO";
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES";
        }

    }

    return 0;
}