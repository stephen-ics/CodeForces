//
// Created by Stephen Ni on 2023-12-27.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cubes[n];
    for(int i = 0; i < n; i++) {
        cin >> cubes[i];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(cubes[j] > cubes[j+1]) {
                swap(cubes[j], cubes[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << cubes[i] << " ";
    }

    return 0;
}