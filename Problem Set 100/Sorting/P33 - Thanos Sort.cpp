//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <vector>

using namespace std;

int maxLength;

void breakDown(int arr[], int l, int r) {
    bool ascending = true;
    int length = r - l + 1;

    for(int i = l; i < r; i++) {
        if(arr[i] > arr[i+1]) {
            ascending = false;
            break;
        }
    }

    if(!ascending) {
        int m = (l + r) / 2;
        breakDown(arr, l, m);
        breakDown(arr, m+1, r);
    } else {
        if(maxLength < length) {
            maxLength = length;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    breakDown(arr, 0, n-1); // true is 1, false is 0

    cout << maxLength;

    return 0;
}