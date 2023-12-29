//
// Created by Stephen Ni on 2023-12-29.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> c(200005, 0);

    for(int i = 0; i < n; i++) {
        int d1, d2;
        cin >> d1 >> d2;

        c[d1]++;
        c[d2+1]--;
    }

    int count = 0;
    for(int i = 0; i < 200005; i++) {
        count += c[i];

        if(count >= k) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }

    vector<int> p(200005, 0);
    for(int i = 0; i < 200005; i++) {
        p[i] = c[i - 1] + p[i - 1];
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << p[r + 1] - p[l] << endl;
    }

    return 0;
}
