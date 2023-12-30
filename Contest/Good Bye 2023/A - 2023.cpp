//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        int product = 1;
        for(int j = 0; j < n; j++) {
            int num;
            cin >> num;
            product *= num;
        }

        if(2023 % product == 0) {
            cout << "YES" << endl;

            cout << 2023 / product << " ";

            for(int i = 1; i < k; i++) {
                cout << 1 << " ";
            }

        } else {
            cout << "NO";
        }

        cout << endl;
    }

    return 0;
}