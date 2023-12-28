//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == b) {
            cout << c;
        } else if (a == c) {
            cout << b;
        } else {
            cout << a;
        }

        cout << endl;
    }

    return 0;
}