//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int checkGolden(vector<int> arr, int l, int r) {
    int sum = 0;

    for(int i = 0; i <= l; i++) {
        sum += arr[i];
    }

    int sum2 = 0;
    for(int i = l+1; i <= r; i++) {
        int t1 = arr[i];
        sum2 += arr[i];
    }

    if(sum == sum2) {
        return sum;
    } else {
        return 10000000;
    }
}

bool checkChain(vector<int> arr, int r, int sum, int size) {
    if(r == size) {
        return true;
    }

    bool notEqual = true;

    int sum2 = 0;
    while(r != size) {
        r++;
        sum2 += arr[r];

        if(sum2 == sum) {
            sum2 = 0;
            notEqual = false;
        }

        if(r != size) {
            notEqual = true;
        }
    }

    if(notEqual) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int n;
    cin >> n;

    string sumStr;
    cin >> sumStr;

    vector<int> sums;

    for(int i = 0; i < n; i++) {
        if(sumStr[i] != '0') {
            sums.push_back(sumStr[i] - '0');
        }
    }

    int size = sums.size();

    if(size == 0) {
        cout << "YES";
    } else {
        bool golden = false;

        for(int i = 0; i < size-1; i++) {
            for(int j = i; j < size; j++) {
                int sum = checkGolden(sums, i, j);
                if(sum != 10000000) {
                    if(checkChain(sums, j, sum, size-1)) {
                        cout << "YES";
                        golden = true;
                        break;
                    }
                }
            }

            if(golden) {
                break;
            }
        }

        if(!golden) {
            cout << "NO";
        }

    }

    return 0;
}

// 7 = 3, 7 = 3 + 4 --> 3 + 4 = 5, 3 + 4 = 5 + 2

// 1 2 4 8
// 1 = 2, 1 = 2 + 4, 1 = 2 + 8
// 1 + 2 = 4, 1 + 2 = 4 + 8
// 1 + 2 + 4 = 8

// remove all 0s they dont impact anything just make things complicated
