//
// Created by Stephen Ni on 2023-12-29.
//

#include<iostream>
#include<unordered_map>
#include<utility>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    unordered_map<int, int> coffee_recipes;

    for(int i = 0; i < n; i++) {
        int d1, d2;
        cin >> d1 >> d2;

        for(int t = d1; t <= d2; t++) {
            if(coffee_recipes.find(t) != coffee_recipes.end()) {
                coffee_recipes[t]++;
            } else {
                coffee_recipes[t] = 1;
            }
        }
    }

    unordered_map<int, int> questions;

    for(int i = 0; i < q; i++) {
        int q1, q2;
        cin >> q2 >> q2;

        for(int t = q1; t <= q2; t++) {
            if(questions.find(t) != questions.end()) {
                questions[t]++;
            } else {
                questions[t] = 1;
            }
        }
    }

    for(int i = 0; i < q; i++) {
        int q1, q2;
        cin >> q1 >> q2;

        int count = 0;

        for(int j = q1; j <= q2; j++) {
            if(coffee_recipes.find(j) != coffee_recipes.end()) {
                if(coffee_recipes[j] >= k) {
                    count++;
                }
            }
        }

        cout << count << endl;
    }



    return 0;
}