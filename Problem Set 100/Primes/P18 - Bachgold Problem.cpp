//
// Created by Stephen Ni on 2023-12-26.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int twos = 0, threes = 0;

    if(n % 2 == 0) {
        twos = n/2;

    } else {
        threes = 1;
        twos = (n-3)/2;
    }

    cout << twos + threes << endl;

    for(int i = 0; i < twos; i++) {
        cout << 2 << " ";
    }

    if(threes == 1) {
        cout << 3;
    }


    return 0;
}

