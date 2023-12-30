//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int max;
    cin >> max;

    vector<int> fib_vector;

    fib_vector.push_back(0);
    fib_vector.push_back(1);
    fib_vector.push_back(1);
    fib_vector.push_back(2);

    while(fib_vector[fib_vector.size() - 1] < max) {
        fib_vector.push_back(fib_vector[fib_vector.size() - 1] + fib_vector[fib_vector.size() - 2]);
    }

    if(max == 3) {
        cout << 1 << " " << 1 << " " << 1;
    } else if(max == 2) {
        cout << 1 << " " << 1 << " " << 0;
    } else if(max == 1) {
        cout << 1 << " " << 0 << " " << 0;
    } else if(max == 0) {
        cout << 0 << " " << 0 << " " << 0;
    }  else {
        cout << fib_vector[fib_vector.size() - 2] << " " << fib_vector[fib_vector.size() - 4] << " " << fib_vector[fib_vector.size() - 5];
    }

    return 0;
}