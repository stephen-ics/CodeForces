//
// Created by Stephen Ni on 2024-01-02.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int count = 0;

    for(int i = 0; i < n-1; i++) {
        count += (arr[i+1] - arr[i] - 1);
    }

    cout << count;

    return 0;
}