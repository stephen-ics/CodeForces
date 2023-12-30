//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>

using namespace std;
typedef long long ll;

void collatz(ll n) {
    if(n != 1) {
        if(n % 2 == 0) {
            cout << n / 2 << endl;
            collatz(n / 2);

        } else {
            cout << (n * 3) + 1 << endl;
            collatz((n * 3) + 1);
        }
    }
}

int main() {
    ll n;
    cin >> n;

    cout << n << endl;

    collatz(n);

    return 0;
}