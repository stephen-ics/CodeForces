//
// Created by Stephen Ni on 2023-12-27.
//

#include <iostream>
#include <cmath>

using namespace std;

int countDivisors(int n) {
    int count = 2; // the 2 divisors being 1 and itself

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(i == sqrt(n)) {
                count++;
            } else {
                count += 2;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    int sum = 1; // accounts for f(1)

    for(int i = 2; i <= n; i++) { // this is an O(n * sqrt(n)) algorithm)
        sum += countDivisors(i);
    }

    cout << sum;

    return 0;
}