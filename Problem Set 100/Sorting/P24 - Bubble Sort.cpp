//
// Created by Stephen Ni on 2023-12-27.
//

#include<iostream>

using namespace std;


void bubbleSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);

            }
        }

        for(int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }

        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    return 0;
}