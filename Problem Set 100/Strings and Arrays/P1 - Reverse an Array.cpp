//
// Created by Stephen Ni on 2023-12-21.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr[i] = val;
    }

    for (int i = 0; i < n/2; i++) {
        swap(arr[i], arr[n-1-i]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}