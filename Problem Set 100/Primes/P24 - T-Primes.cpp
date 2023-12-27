//
// Created by Stephen Ni on 2023-12-27.
//

#include<iostream>
#include<cmath>

using namespace std;

void isTPrime(long long n) {
    long long count = 0;

    for(long long i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(n / i == i) {
                count++;
            }
            else {
                count += 2;
            }
        }
    }

    if(count == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    long long n;
    cin >> n;

    for(long long i = 0; i < n; i++) {
        long long num;
        cin >> num;

        isTPrime(num);
    }

    return 0;
}