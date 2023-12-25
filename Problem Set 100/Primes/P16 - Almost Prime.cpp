//
// Created by Stephen Ni on 2023-12-25.
//

#include <iostream>
#include <string>

using namespace std;

bool checkPrime(int num) {
    if(num == 1) {
        return false;
    }

    for(int i = 2; i <= num/2; i++) {
        if(num % i == 0)  {
            return false;
        }
    }

    return true;
}

bool checkAlmostPrime(int num) {
    int count = 0;

    for(int i = 1; i <= num/2; i++) {
        if(num % i == 0) {
            if(checkPrime(i)) {
                count++;
            }
        }
    }

    if(count == 2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;

    int count = 0;

    for(int i = 1; i <= n; i++) {
        if(checkAlmostPrime(i)) {
            count++;
        }
    }

    cout << count;

    return 0;
}

// find all divisors
// check if divisors are lucky?