//
// Created by Stephen Ni on 2023-12-27.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        bool possible = false;
        string p, p_hashed;
        cin >> p >> p_hashed;

        int amountCode = p.length();
        int amountHash = p_hashed.length();
        int diff = amountHash - amountCode;

        for(int i = 1; i < amountCode; i++) {
            for(int j = 0; j < amountCode-1; j++) {
                if(p[j] > p[j+1]) {
                    swap(p[j], p[j+1]);
                }
            }
        }

        for(int i = 0; i <= diff; i++) {
            string currentHash;
            for(int j = i; j < amountCode+i; j++) {
                currentHash += p_hashed[j];
            }

            // sort new hash code
            for(int i = 1; i < amountCode; i++) {
                for(int j = 0; j < amountCode-1; j++) {
                    if(currentHash[j] > currentHash[j+1]) {
                        swap(currentHash[j], currentHash[j+1]);
                    }
                }
            }

            int count = 0;
            for(int i = 0; i < amountCode; i++) {
                if(currentHash[i] == p[count]) {
                    count++;
                }
            }

            if(count == p.length()) {
                possible = true;
                break;
            }
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }

    return 0;
}