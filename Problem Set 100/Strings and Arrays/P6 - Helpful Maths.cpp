//
// Created by Stephen Ni on 2023-12-22.
//

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    s.erase(remove(s.begin(), s.end(), '+'), s.end());

    int arr[s.length()];

    for(int i = 0; i < s.length(); i++) {
        char currentChar = s[i];
        arr[i] = currentChar - '0';
    }

    sort(arr, arr+s.size());

    for(int i = 0; i < s.length(); i++) {
        cout << arr[i];

        if (i != s.length()-1) {
            cout << "+";
        }
    }

    return 0;
}