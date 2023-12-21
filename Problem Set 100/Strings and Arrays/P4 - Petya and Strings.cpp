//
// Created by Stephen Ni on 2023-12-21.
//

#include<iostream>
#include<string>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    int result = str1.compare(str2);

    if (result < 0) {
        cout << -1;
    }
    else if (result > 0){
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
