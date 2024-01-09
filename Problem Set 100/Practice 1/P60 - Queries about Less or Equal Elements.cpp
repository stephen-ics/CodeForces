//
// Created by Stephen Ni on 2024-01-08.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr1[n];
    int arr2[m];
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    sort(arr1, arr1 + n);

    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    for(int i = 0; i < m; i++) {
        int val = arr2[i];

        int l = 0;
        int r = n;
        int mid = (l + r) / 2;

        while(mid != r && mid != l) {
            if(arr1[mid] > val) {
                r = mid;
            } else {
                l = mid;
            }

            mid = (l + r) / 2;
        }

        if(val < arr1[0]) {
            cout << 0 << " ";
        }
        else if(val > arr1[l]) {
            cout << l + 1 << " ";
        } else {
            cout << r << " ";
        }
    }

    return 0;
}