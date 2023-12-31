//
// Created by Stephen Ni on 2023-12-31.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> map;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if(map.find(num) != map.end()) {
            map[num]++;
        } else {
            map[num] = 1;
        }
    }

    for (auto i : map) {
        if(i.second % 2 == 1) {
            cout << i.first;
        }
    }

    return 0;
}