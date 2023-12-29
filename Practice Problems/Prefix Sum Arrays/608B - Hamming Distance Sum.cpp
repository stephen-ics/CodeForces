//
// Created by Stephen Ni on 2023-12-29.
//

#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int main() {
    string a, b;
    cin >> a >> b;

    int max = 200001;
    int prefix_count_array[max][2];

    for(int i = 1; i <= b.size(); i++) {
        for(int j = 0; j < 2; j++) {
            prefix_count_array[i][j] = prefix_count_array[i-1][j];
        }

        prefix_count_array[i][b[i - 1] - '0']++;
    }

    ll sum = 0;
    for(int i = 0; i < a.size(); i++) {
        int c = a[i] - '0';

        for(int j = 0; j < 2; j++) {
            sum += abs(c - j) * (prefix_count_array[b.size() - a.size() + i + 1][j] - prefix_count_array[i][j]); // this compares a[i] and matches it to any possible it will be matched against
        }
        // the idea is that abs(c - j) one will evaluate to 1 and the other will evaluate to 0, 0 * num = 0, so it will not add to the sum, the j just iterates over both values
        // then count array * 1 = the amount of times that letter has been counted up to that point


    } // we need to do abs to get the difference as if c = 1, j = 1, and we do not want -1

    cout << sum << endl;

    return 0;
}