//
// Created by Stephen Ni on 2024-01-04.
//

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> map;

    bool possible = true;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        if(arr[i] != i+1) {
            cout << "NO";
            possible = false;
            break;
        }
    }

    if(possible) {
        cout << "YES";
    }

    return 0;
}