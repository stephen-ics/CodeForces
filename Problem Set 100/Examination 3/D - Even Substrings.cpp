//
// Created by Stephen Ni on 2024-01-12.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    int output = 0;

    for(int i = 0; i < n; i++) {
        if(str[i] % 2 == 0) {
            output += i + 1;
        }
    }

    cout << output;

    return 0;
}