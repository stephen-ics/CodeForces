//
// Created by Stephen Ni on 2023-12-29.
//

#include <iostream>
#include <string>

using namespace std;

// use bit manipulating to do intervals of 32??? --> this will be solution v2
// create hash map to not check over pieces that are already checked?

int calculateSum(string a, string b) {
    int sum = 0;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] - '0' != b[i] - '0') {
            sum++;
        }
    }

    return sum;
}

int main() {
    string a, b;
    cin >> a >> b;

    int sum = 0;
    int length = b.length() - a.length() + 1;

    for(int i = 0; i < length; i++) {
        string s1;
        for(int j = i; j < i+a.length(); j++) {
            s1 += b[j];
        }

        sum += calculateSum(a, s1);
    }

    cout << sum;


    return 0;
}