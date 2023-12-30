//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>

using namespace std;

int cnt;

void findCode(int n, int length) {
    if (length == n) {
        cnt++;
    } else if(length + 1 == n) {
        cnt++;
    } else if(length + 2 == n) {
        cnt += 2;
    } else {
        findCode(n, length+1);
        findCode(n, length+2);
    }
}

int main() {
    int n;
    cin >> n;

    findCode(n, 0);

    cout << cnt;

    return 0;
}