//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int max;
    cin >> max;

    unordered_map<int, int> fib_map;
    vector<int> fib_vector;

    fib_vector.push_back(0);
    fib_vector.push_back(1);
    fib_vector.push_back(1);
    fib_vector.push_back(2);

    while(fib_vector[fib_vector.size() - 1] < max) {
        fib_vector.push_back(fib_vector[fib_vector.size() - 1] + fib_vector[fib_vector.size() - 2]);
    }

    int count = 2;
    for(int i = 0; i <= max; i++) {
        if(i == fib_vector[count]) {
            count++;
            fib_map[i] = 1;
        }
    }

    for(int i = 1; i <= max; i++) {
        if(fib_map[i]) {
            cout << "O";
        } else {
            cout << "o";
        }
    }




    return 0;
}