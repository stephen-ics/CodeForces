//
// Created by Stephen Ni on 2023-12-25.
//

#include <iostream>
#include <cmath>

using namespace std;

void reduce(long long &x, long long &y) {
    long long first, second;

    if (x > y) {
        first = x;
        second = y;
    } else {
        first = y;
        second = x;
    }

    for(long long i = 2; i <= second; i++) {
        if(first % i == 0 && second % i == 0) {
            x /= i;
            y /= i;
            reduce(x, y);
            break;
        }
    }
}

int main() {
    long long a, b, x, y;
    cin >> a >> b >> x >> y;

    reduce(x, y);

    cout << x << " " << y;

    long long countW = a / x;
    long long countH = b / y;

    if(countW > countH) {
        cout << countH;
    } else {
        cout << countW;
    }

    return 0;
}

