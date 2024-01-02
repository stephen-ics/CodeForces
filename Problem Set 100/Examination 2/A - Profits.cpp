//
// Created by Stephen Ni on 2024-01-02.
//

#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int sum = 0;;
    bool dream = false;
    for(int i = 0; i < n; i++) {
        int pay;
        cin >> pay;

        sum += pay;

        if(sum >= x) {
            cout << i + 1;
            dream = true;
            break;
        }
    }

    if(!dream) {
        cout << -1;
    }

    return 0;
}