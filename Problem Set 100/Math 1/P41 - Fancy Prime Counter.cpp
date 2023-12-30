//
// Created by Stephen Ni on 2023-12-29.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> primes(300000, 1);

    for(int i = 2; i < 300000; i++) {
        if(primes[i]) {
            for(int j = 2 * i; j < 300000; j += i) {
                primes[j] = 0;
            }
        }
    }

    int prime_sums[300005];
    prime_sums[0] = 0;
    prime_sums[1] = 0;
    prime_sums[2] = 1;

    for(int i = 3; i < 300005; i++) {
        prime_sums[i] = prime_sums[i - 1];
        if(primes[i]) {
            prime_sums[i]++;
        }
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int lower, upper;
        cin >> lower >> upper;

        if(lower == 1) {
            cout << prime_sums[upper];
        } else {
            cout << prime_sums[upper] - prime_sums[lower  - 1];
        }

        cout << endl;
    }


    return 0;
}

// for this problem just find all primes between 1 and 300,000 (O(n) * log(n))
// then find the summation to find the number of primes at each interval
// then do subtraction to find the number of primes between each interval