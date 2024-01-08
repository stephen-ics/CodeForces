//
// Created by Stephen Ni on 2024-01-07.
//

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int days[n];

    for(int i = 0; i < n; i++) {
        cin >> days[i];
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += days[i];

        int diff = sum % m;
        if((sum - diff) / m > 0) {
            int div = sum / m;
            sum = sum % m;
            cout << div << " ";
        } else {
            cout << 0 << " ";
        }
    }

    return 0;
}

// use mod here to wrap around find remainder, subtract by mod to get number of times the page flips