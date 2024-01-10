//
// Created by Stephen Ni on 2024-01-10.
//

#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll n, k;

    cin >> n >> k;

    ll half;
    if(n % 2 == 0) {
        half = n / 2;
    } else {
        half = n / 2  + 1;
    }

    // if k > half (k is even) --> k -= half, k *= 2
    // else if k >= half (k is odd) --> (k *= 2) - 1

    if(k > half) {
        k -= half;
        k *= 2;
    } else {
        k *= 2;
        k--;
    }

    cout << k;

    return 0;
}