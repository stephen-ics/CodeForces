//
// Created by Stephen Ni on 2023-12-24.
//

#include <iostream>

using namespace std;

int main()
{
    int n, l, a;
    cin >> n >> l >> a;

    int customers[n][2];

    for(int i = 0; i < n; i++) {
        int tl, li;
        cin >> tl >> li;

        customers[i][0] = tl;
        customers[i][1] = li;
    }

    for(int i = 0; i < n; i++) {
        int currentTime = 0;
        bool freeTime = true;
        int count = 0;

        for(int j = 0; j < n; j++) {
            if (currentTime == customers[j][0]) {
                currentTime += customers[j][1];
                count = 0;
                break;
            }
        }

        if(freeTime) {
            count++;
        }

        if(count == a) {
            cout << currentTime - 2 << " " << currentTime;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << customers[i][0] << " " << customers[i][1] << endl;
    }

    return 0;
}