//
// Created by Stephen Ni on 2024-01-05.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int john = 0;

    for(int i = 0; i < 4; i++) {
        int val;
        cin >> val;
        john += val;
    }

    int sums[n];

    for(int i = 0; i < n; i++) {
        sums[i] = 0;
    }

    for(int i = 0; i < n-1; i++) {
        int sum = 0;
        for(int j = 0; j < 4; j++) {
            int val;
            cin >> val;
            sum += val;
        }

        sums[i] = sum;
    }

    sort(sums, sums + n);

    for(int i = 0; i < n; i++) {
        if(john >= sums[n - i - 1]) {
            cout << i + 1;
            break;
        }
    }

    return 0;
}