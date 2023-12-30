//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll total_product = 1;
    for(int i = 1; i <= n; i++) {
        total_product *= i;
    }

    cout << total_product;

    return 0;
}