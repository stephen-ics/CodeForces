//
// Created by Stephen Ni on 2023-12-27.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int index = 0;
    int indexLowestPrice = 0;
    long long lowestPrice = 10000000000;

    for(int i = 0; i < n; i++) {
        long long price;
        cin >> price;

        index++;

        if (price < lowestPrice) {
            lowestPrice = price;
            indexLowestPrice = index;
        }
    }

    cout << indexLowestPrice-1;

    return 0;
}