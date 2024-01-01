//
// Created by Stephen Ni on 2024-01-01.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> numbers;
    int bitNum =  0;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        bitNum ^= num;
    }

    cout << bitNum;

    return 0;
}