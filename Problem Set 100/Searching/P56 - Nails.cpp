//
// Created by Stephen Ni on 2023-12-31.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int query;
        cin >> query;

        int l = 0;
        int r = n - 1;
        int mid = (l + r) / 2;

        while(r != l + 1 && r != l) {
            if(query < arr[mid]) {
                r = mid;
            } else {
                l = mid;
            }

            mid = (l + r) / 2;
        }

        if(arr[l] <= query) {
            cout << arr[l + 1];
        } else {
            cout << arr[l];
        }

        cout << endl;
    }

    return 0;
}