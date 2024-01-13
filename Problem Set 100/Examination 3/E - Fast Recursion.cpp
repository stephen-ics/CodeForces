//
// Created by Stephen Ni on 2024-01-12.
//

#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map<ll, ll> memo;

ll cnt(ll n) {
    if(n == 0) {
        return 1;
    } else if (memo.find(n) != memo.end()) {
        return memo[n];
    } else {
        memo[n] = cnt(n-1) + cnt(n/2) + cnt(n/3);
    }

    return cnt(n-1) + cnt(n/2) + cnt(n/3);
}

int main() {
    ll n;
    cin >> n;
    cout << cnt(n) << endl;

    return 0;
}