//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>

using namespace std;

void printOutput(int k) {
    if(k % 3 == 0) {
        cout << k - 1 << " " << k - 1 << " " << k + 2;
    } else if(k % 3 == 1) {
        cout << k << k + 2 << k - 2;
    } else if(k % 3 == 2) {
        cout << k << k + 1 << k - 2;
    }
}

int main() {
    int n;
    cin >> n;

    if(n % 3 == 0) {
        int k = n / 3;
        if(k % 3 == 0) {
            cout << k - 1 << " " << k - 1 << " " << k + 2;
        } else if(k % 3 == 1) {
            cout << k << " " << k << " " << k;
        } else if(k % 3 == 2) {
            cout << k << " " << k << " " << k;
        }
    } else if(n % 3 == 1) {
        int k = (n - 1) / 3;
        if(k % 3 == 0) {
            cout << k - 1 << " " << k + 1 << " " << k + 1;
        } else if(k % 3 == 1) {
            cout << k << " " << k << " " << k + 1;
        } else if(k % 3 == 2) {
            cout << k - 1 << " " << k << " " << k + 2;
        }
    } else if(n % 3 == 2) {
        int k = (n - 2) / 3;
        if(k % 3 == 0) {
            cout << k - 1 << " " << k + 1 << " " << k + 2;
        } else if(k % 3 == 1) {
            cout << k << " " << k + 1 << " " << k + 1;
        } else if(k % 3 == 2) {
            cout << k << " " << k << " " << k + 2;
        }
    }

    return 0;
}