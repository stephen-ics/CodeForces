//
// Created by Stephen Ni on 2023-12-27.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int r, g, b; // <= 10^9 can use int (around 2 billion)
        cin >> r >> g >> b;

        if(r + g >= b-1 && r + b >= g-1 && b + g >= r-1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}