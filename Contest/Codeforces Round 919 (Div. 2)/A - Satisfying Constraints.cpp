//
// Created by Stephen Ni on 2024-01-13.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<int> vec;

        int count = 0;
        int lowest = 0;
        int highest = 2000000000;

        for(int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;

            if(x == 1) {
                if(y > lowest) {
                    lowest = y;
                }

            } else if (x == 2) {
                if(y < highest) {
                    highest = y;
                }
            } else {
                vec.push_back(y); // we dont need a map because no two constraints are exactly the same
            }
        }

        for(int j = 0; j < vec.size(); j++) {
            if(vec[j] <= highest && vec[j] >= lowest) {
                count++;
            }
        }

        int result = highest - lowest - count + 1;

        if(result < 0) {
            result = 0;
        }

        cout << result;
        cout << endl;
    }


    return 0;
}