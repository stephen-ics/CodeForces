//
// Created by Stephen Ni on 2023-12-29.
//

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll stones[n];
    for(int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    ll sumStones[n];
    sumStones[0] = stones[0];

    for(int i = 1; i < n; i++) {
        sumStones[i] = sumStones[i-1] + stones[i];
    }

    sort(stones, stones + n);

    ll sortedStones[n];
    sortedStones[0] = stones[0];

    for(int i = 1; i < n; i++) {
        sortedStones[i] = sortedStones[i-1] + stones[i];
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        ll type, l, r;
        cin >> type >> l >> r;

        if(type == 2) {
            if(l == 1) {
                cout << sortedStones[r-1];
            } else {
                cout << sortedStones[r-1] - sortedStones[l-2];
            }
        } else {
            if(l == 1) {
                cout << sumStones[r-1];
            } else {
                cout << sumStones[r-1] - sumStones[l-2];
            }
        }


        cout << endl;
    }

    return 0;
}