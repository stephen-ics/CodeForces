//
// Created by Stephen Ni on 2023-12-31.
//

#include <iostream>
#include <unordered_map>

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        map[num] = i;
    }

    int q;
    cin >> q;

    int q_arr[q+1];
    for(int i = 0; i < q; i++) {
        cin >> q_arr[i+1];
    }

    for(int i = 1; i <= q; i++) {
        if(map.find(q_arr[i]) != map.end()) {
            cout << map[q_arr[i]];
        } else {
            cout << -1;
        }

        cout << endl;
    }


    return 0;
}