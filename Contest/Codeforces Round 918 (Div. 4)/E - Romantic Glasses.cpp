//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>

using namespace std;

bool findSum(long long arr[], long long l, long long r) {
    long long odd = 0, even = 0;

    for(int i = l; i <= r; i++) {
        if(i % 2 == 0) {
            even += arr[i];
        } else {
            odd += arr[i];
        }
    }

    if(odd == even) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;

    for(int k = 0; k < n; k++) {
        int t;
        cin >> t;

        long long arr[t];
        for(int i = 0; i < t; i++) {
            cin >> arr[i];
        }

        bool notPossible = true;

        for(int i = 1; i < t; i++) {
            int increment = t - i + 1;
            for(int j = 0; j < increment-1; j++) {
                long long s1 = j;
                long long s2 = j+i;

                bool compare = findSum(arr, s1, s2);
                if(compare) {
                    cout << "YES";
                    notPossible = false;
                    break;
                }
            }

            if(!notPossible) {
                break;
            }
        }

        if(notPossible) {
            cout << "NO";
        }

        cout << endl;
    }

    // if there is any sum of 3, 5, 7 (increment by 2) that satisfies odd number = even number
    // try l = 1, r = 2, 3, 4, 5, 6
    // l = 2, r = 3, 4, 5, 6, 7

    return 0;
}