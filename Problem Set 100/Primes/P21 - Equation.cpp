//
// Created by Stephen Ni on 2023-12-27.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << 9 << " " << 8;
    } else {
        cout << 3*n << " " << 2*n;
    }

    return 0;
}