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
    for(int i = 1; i < 200005; i++) {
        p[i] = c[i - 1] + p[i - 1];
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << p[r + 1] - p[l] << endl;
    }

    return 0;
}

// the main takeaway for this problem is that when you have a range of values e.g 92 - 97, most of the time if you are looking for the amount of time each number shows up you don't have the loop through each number
// you can increment beginning and decrement the ending value and all values that sum up to the 'k' threshold (appear more than k times) are valid
// it can be thought of as 'layers' on intervals
// the last part summation is more the "common prefix sum array" part, where the amount of valid numbers in a range is equivalent to the amount of valid numbers up to the upper bound subtracted by the amount of valid numbers up to the lowest bound
// taking the summation is similar to taking the area a.k.a taking the interval, so if A is the accumulation of B and B is the accumulation of C, you can perceive an relationship of integrals/derivatives