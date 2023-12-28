//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long val;
            cin >> val;
            sum += val;
        }

        long long sqrtSum = sqrt(sum);
        if(sqrtSum * sqrtSum == sum) {
            cout << "YES";
        } else {
            cout << "NO";
        }

        cout << endl;
    }

    return 0;
}