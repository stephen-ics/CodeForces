//
// Created by Stephen Ni on 2024-01-06.
//

#include <iostream>
#include <string>

using namespace std;

int checkSum(string s, int l, int r) {

}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int len;
        cin >> len;

        string s;
        cin >> s;

        int num_a = 0;
        int num_b = 0;

        for(int j = 0; j < len; j++) {
            if(s[j] == '+') {
                num_a++;
            } else {
                num_b++;
            }
        }

        int output;
        if(num_a > num_b) {
            output = num_a - num_b;
        } else {
            output = num_b - num_a;
        }

        cout << output << endl;
    }


    return 0;
}

// loop minimum amount of times you have "+" or "-"