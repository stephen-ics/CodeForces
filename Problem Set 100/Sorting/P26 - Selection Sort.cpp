//
// Created by Stephen Ni on 2023-12-27.
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

    for(int i = 0; i < n-1; i++) {

        int lowestIndex = i;
        for(int j = i; j < n; j++) {
            if(arr[j] < arr[lowestIndex]) {
                lowestIndex = j;
            }
        }

        swap(arr[i], arr[lowestIndex]);

        for(int j = 0; j < n; j++) {
            cout << arr[j] << " ";
        };

        cout << endl;
    }

    return 0;
}