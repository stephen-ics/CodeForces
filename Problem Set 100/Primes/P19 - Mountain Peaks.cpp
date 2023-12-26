//
// Created by Stephen Ni on 2023-12-26.
//

#include <iostream>

using namespace std;

bool checkChallenging(int peaks[], int location, int n) {
    if(location == 0 || location == n - 1) {
        return false;
    }

    int currentPeak = peaks[location];
    int lastPeak = peaks[location - 1];
    int nextPeak = peaks[location + 1];

    if(currentPeak > lastPeak && currentPeak > nextPeak) {
        return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    int peaks[n];
    for(int i = 0; i < n; i++) {
        cin >> peaks[i];
    }

    int highestDistance = 0;
    int numChallenging = 0;
    int count = 1;

    for(int i = 0; i < n; i++) {
        bool challenging = checkChallenging(peaks, i, n);

        if(challenging) {
            numChallenging++;
            if(count > highestDistance) {
                highestDistance = count;
            }

            count = 1;
        }

        count++;
    }

    if (highestDistance == 0)  {
        cout << 0;
    } else {
        while(n % highestDistance != 0) {
            highestDistance++;
        }

        cout << n / highestDistance << endl;
    }

    return 0;
}

// find minimum interval of gaps between challenging peaks where every challenging peak can be reached (cache one variable as minimum and compare)