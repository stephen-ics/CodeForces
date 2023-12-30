//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool checkDivisors(long long n, long long a, long long b) {
    vector<long long> divisors;

    long long count = 0;
    for(long long i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            count++;
            divisors.push_back(i);
        }

        if(count == 3) {
            break;
        }
    }

    long long lgstDiv, scndDiv;

    if(divisors.size() == 2) {
        lgstDiv = n / divisors[1];
        scndDiv = divisors[1];
    } else {
        lgstDiv = n / divisors[1];
        scndDiv = n / divisors[2];
    }

    if(scndDiv == a && lgstDiv == b) {
        return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        long long a, b;
        cin >> a >> b;

        bool loop = true;
        long long count = b;

        if(a == 1) {
            count = b * b;
        } else {
            while (loop) {
                count += b;
                if(count % a == 0) {
                    loop = checkDivisors(count, a, b);
                }

                if(!loop) {
                    break;
                }
            }
        }

        cout << count <<  endl;
    }



    return 0;
}