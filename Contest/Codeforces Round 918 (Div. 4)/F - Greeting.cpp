//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <vector>

using namespace std;

bool checkOverlap(int a1, int b1, int a2, int b2) {
    if(a1 < a2) {
        if(b1 < b2) {
            return false;
        } else {
            return true;
        }
    }

    else if(a1 > a2) {
        if(b1 > b2) {
            return false;
        } else {
            return true;
        }
    }

    else if(b2 < a1) {
        return false;
    } else if(b1 < a2) {
        return false;
    } else if(b1 <= b2) {
        return true;
    } else if(b2 <= b1) {
        return true;
    } else {
        return false;
    }
}

bool checkAlready(vector<vector<int> > arr, int i1, int i2) {
    if(i1 == i2) {
        return true;
    }
    for(int i = 0; i < arr.size(); i++) {
        int a1 = arr[i][0];
        int a2 = arr[i][1];

        if(a1 == i1 && a2 == i2 || a2 == i1 && a1 == i2) {
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int destinations[n][2];

        vector<vector<int> > alreadyChecked;

        for(int i = 0; i < n; i++) {
            int d1, d2;
            cin >> d1 >> d2;

            destinations[i][0] = d1;
            destinations[i][1] = d2;
        }

        int count = 0;

        for(int i = 0; i < n-1;  i++) {
            for(int j = 0; j < n; j++) {
                if(!checkAlready(alreadyChecked, i, j)) {
                    if(checkOverlap(destinations[i][0], destinations[i][1], destinations[j][0], destinations[j][1])) {
                        count++;
                    }

                    vector<int> ac;
                    ac.push_back(i);
                    ac.push_back(j);
                    alreadyChecked.push_back(ac);
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}