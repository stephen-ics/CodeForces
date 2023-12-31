//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}



int main() {
    int b;
    cin >> b;

    unordered_map<int, int> exists;

    int count = 0;

    for(int i = 1; i <= b; i++) {
        int val = gcd(i, b);

        int ans = b / val;

        if(!exists[ans]) {
            count++;
            exists[ans] = 1;
        }
    }

    cout << count;


    return 0;
}