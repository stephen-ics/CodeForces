//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    long long b;
    cin >> b;

    vector<long long> divisors;

    for(long long i = 1; i * i <= b; i++) {
        if(i * i == b) {
            divisors.push_back(i);
        }  else if(b % i == 0) {
            divisors.push_back(i);
            divisors.push_back(b / i);
        }
    }

    cout << divisors.size();

    return 0;
}