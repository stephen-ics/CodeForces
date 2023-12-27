//
// Created by Stephen Ni on 2023-12-27.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> isPrime(n+1, true);

    for(int i = 2; i <= sqrt(n); i++) {
        if(isPrime[i]) {
            for(int j = 2*i; j <= n; j = j+ i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            count++;
        }
    }

    cout << count << endl;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            cout << i << " ";
        }
    }

    return 0;
}