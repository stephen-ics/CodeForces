//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum = 0;
    int product = 1;

    int zeroes = 0;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if(num < 0) {
            sum += -(num + 1);
            product *= -1;
        } else if(num > 0) {
            sum += num - 1;
            product *= 1;
        } else {
            zeroes += 1;
        }
    }

    while(zeroes != 0) {
        if(product == -1) {
            sum += 1;
            product *= -1;
        } else {
            sum += 1;
            product *= 1;
        }

        zeroes--;
    }

    if(product == -1) {
        sum += 2;
    }

    cout << sum;

    //check difference from negatives and positives to -1 and 1, if product is negative add 2 to chain signs of one of them
    return 0;
}