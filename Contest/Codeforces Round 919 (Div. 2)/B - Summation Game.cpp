//
// Created by Stephen Ni on 2024-01-13.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;

    for(int i = 0; i < k; i++) {
        int n, x, y;
        cin >> n >> x >> y;

        int nums[n];

        for(int j = 0; j < n; j++) {
            int val;
            cin >> val;

            nums[j] = val;
        }

        sort(nums, nums + n);

        int sums[n];

        sums[0] = nums[0];

        for(int j = 1; j < n; j++) {
            sums[j] = sums[j-1] + nums[j];
        }

        int output = 0;

        for(int j = 0; j <= x; j++) {
            int sub;
            int val;

            if(n - j <= 0) { // if you take them all
                val = 0;
            }
            else if(n - j < y) { // if the amount left is less than the amount they can turn negative
                val = sums[n - j] * -1;
            } else {
                val = sums[n - j - 1 - y];
                sub = sums[n - j - 1] - sums[n - j - 1 - y];

                val -= sub;
            }

            if(val > output) {
                output = val;
            }
        }

        cout << output << endl;



    }





    // sort the array then do prefix sums?
    // prefix sums array + Simulation
    // O(n)

    // two prefix sum arrays one from lowest val to highest val and one from highest val to lowest val
    // then loop through `n` times and for each loop take the 2nd array sum value and subtract it by the total value


    // then we loop through 'n' many times back around, but for each loop we simulate removing the 'k' elements
    // instead of removing 'k' elements we can mark them as false in a map

    // theres n for cases, one where u remove 1 ele, one for 2, one for 3 --> do them all?

    // basically it is free once you are finished with alice
    // sort the array, top elements become negative numbers for bob,


    return 0;
}
