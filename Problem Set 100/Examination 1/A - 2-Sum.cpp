//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <unordered_map> // hash map

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    unordered_map<int, int> hash_table;

    int nums[n];
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    bool possible = false;

    for(int i = 0; i < n; i++) {
        int second_integer = x - nums[i];

        if(hash_table.find(second_integer) != hash_table.end()) {
            cout << "YES";
            possible = true;
            break;
        } else {
            hash_table[nums[i]] = i;
        }
    }

    if(!possible) {
        cout << "NO";
    }

    return 0;
}