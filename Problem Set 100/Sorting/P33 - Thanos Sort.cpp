//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <vector>

using namespace std;

vector<bool> counts(4, false);

void breakDown(int arr[], int l, int r, int count) {
    bool ascending = true;
    int length = r - l + 1;

    for(int i = l; i < r; i++) {
        int t1 = arr[i];
        int t2 = arr[i+1];

        if(arr[i] > arr[i+1]) {
            ascending = false;
            break;
        }
    }

    if(!ascending) {
        count++;

        int m = (l + r) / 2;
        breakDown(arr, l, m, count);
        breakDown(arr, m+1, r, count);
    } else {
        if(count != 0) {
            counts[count-1] = true;
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

    int count = 0;

    breakDown(arr, 0, n-1, count); // true is 1, false is 0

    // [ false, true, false, false]
    // we are trying to find the first position in which we have a true (that is the least amount of splits it will take)
    // if we do not have a true it means it will take no splits

    int num = 0;
    int numFalse = 0;
    for(int i = 0; i < 4; i++) {
        if(!counts[i]) {
            num++;
            numFalse++;
        } else {
            break;
        }
    }

    if(numFalse == 4) {
        num = 0;
    } else {
        num++;
    }

    int sum = n;
    for(int i = 0; i < num; i++) {
        sum /= 2;
    }

    if(sum < 2) {
        cout << 1;
    } else {
        cout << sum;
    }

    return 0;
}