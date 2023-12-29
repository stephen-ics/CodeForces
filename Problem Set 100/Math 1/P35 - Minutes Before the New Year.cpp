//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int h, m;
        cin >> h >> m;

        int sum = 0;
        sum += (60 - m);
        sum += (24 - h)*60-60;

        cout << sum << endl;
    }

    return 0;
}