//
// Created by Stephen Ni on 2023-12-27.
//

#include <iostream>
#include <algorithm>

using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;

    int length = r - l + 1;

    int temp[length];

    while(i <= m && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= m) { // if remaining elements in i array after j is empty
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= r) { // if remaining elements in j array after i is empty
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    long long n;
    cin >> n;

    long long sticks[n];
    for(long long i = 0; i < n; i++) {
        cin >> sticks[i];
    }

//  mergeSort(sticks, 0, n-1);

    sort(sticks, sticks+n);

    long long x = 0, y = 0;

    for(long long i = 0; i < n/2; i++) {
        y += sticks[sizeof(sticks)/sizeof(long long) - 1 - i];
        x += sticks[i];
    }

    if(n % 2 != 0) {
        y += sticks[n/2];
    }

    cout << x*x + y*y;

    return 0;
}