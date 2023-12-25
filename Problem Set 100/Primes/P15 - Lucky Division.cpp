//
// Created by Stephen Ni on 2023-12-25.
//

#include <iostream>
#include <string>

using namespace std;

bool isLuckyNumber(string num) {
    for(int i = 0; i < num.length(); i++) {
        if(num[i] != '4' && num[i] != '7')  {
            return false;
        }
    }

    return true;
}


int main() {
    int n;
    cin >> n;

    bool isLucky = isLuckyNumber(to_string(n));

    if(isLucky) {
        cout << "YES";
    } else {
        bool isDivisible = false;

        for(int i = 1; i <= n/2 ; i++) {
            if(n % i == 0) {
                if(isLuckyNumber(to_string(i))) {
                    isDivisible = true;
                    cout << "YES";
                    break;
                }
            }
        }

        if(!isDivisible) {
            cout << "NO";
        }
    }

    return 0;
}

// find all divisors
// check if divisors are lucky?