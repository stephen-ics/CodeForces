//
// Created by Stephen Ni on 2023-12-28.
//

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n < 4) {
        cout << 0;
    } else {
        long long sticks[n];
        for(long long i = 0; i < n; i++) {
            cin >> sticks[i];
        }

        sort(sticks, sticks+n);
        cout << sticks[n - 4]*sticks[n - 4];

    }

    return 0;
}