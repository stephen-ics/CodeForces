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

    int sum = 1; // accounts for f(1)

    vector<int> numbers(n+1, 2);

    for(int i = 2; i <= n; i++) {
        for(int j = 2*i; j <= n; j = j + i) {
            numbers[j]++;
        }
    }

    for(int i = 2; i < n+1; i++) {
        sum += numbers[i];
    }

    cout << sum;

    return 0;
}