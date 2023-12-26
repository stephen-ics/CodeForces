//
// Created by Stephen Ni on 2023-12-24.
//

#include <iostream>

using namespace std;

bool checkCustomer(int customers[][2], int size, int currentTime) {
    for(int i = 0; i < size; i++) {
        if(customers[i][0] == currentTime) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, l, a;
    cin >> n >> l >> a;

    int customers[n][2];

    for(int i = 0; i < n; i++) {
        int tl, li;
        cin >> tl >> li;

        customers[i][0] = tl;
        customers[i][1] = li;
    }

    bool hasCustomer;
    int time = 0;
    int count = 0;
    int numBreaks = 0;

    for(int i = 0; i < l; i++) {
        hasCustomer = checkCustomer(customers, n, time);

        if(hasCustomer) {
            time += customers[time][1];
            count = 0;
        }
        else {
            time++;
            count++;
            if(count >= a) {
                numBreaks++;
                count = 0;
            }
        }
    }

    cout << numBreaks << endl;

    return 0;
}