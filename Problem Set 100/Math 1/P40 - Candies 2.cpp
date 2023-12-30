//
// Created by Stephen Ni on 2023-12-29.
//

#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;


    int first_candy;
    cin >> first_candy;

    int candies_sum[n];
    candies_sum[0] = first_candy;
    for(int i = 1; i < n; i++) {
        int new_candy;
        cin >> new_candy;

        candies_sum[i] = candies_sum[i-1] + new_candy;
    }

    for(int i = 0; i < q; i++) {
        int q1, q2;
        cin >> q1 >> q2;

        if(q1 == 0) {
            cout << candies_sum[q2];
        } else {
            cout << candies_sum[q2] - candies_sum[q1-1];
        }

        cout << endl;
    }

    return 0;
}