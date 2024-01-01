//
// Created by Stephen Ni on 2024-01-01.
//

#include <iostream>
#include <cmath>

using namespace std;

long long check(long long x, long long val) {
    long long x_val = x * x + 100 * x + x / 3;

    return x_val;
}

int main() {
    long long n;
    cin >> n;

    long long l = 0;
    long long r = 1000000000;
    long long mid = (l + r) / 2;

    long long num = 1;
    int output;

    while(num != n) {
        num = check(mid, n);
        output = mid;

        if(n < num) {
            r = mid;
        } else {
            l = mid;
        }

        mid = (l + r) / 2;
    }

    cout << output;



    return 0;
}