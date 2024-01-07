//
// Created by Stephen Ni on 2024-01-06.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        long long sum = a + b;

        if(sum % 2 == 0) {
            cout << "Bob";
        } else {
            cout << "Alice";
        }

        cout << endl;
    }


    return 0;
}