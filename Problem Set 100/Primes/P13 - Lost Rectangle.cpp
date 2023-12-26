//
// Created by Stephen Ni on 2023-12-25.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long a;
    cin >> a;

    long long smallestPerimeter = 10000000000000;
    long long smallestPerimeterDifference = 10000000000000;

    for(long long i = 1; i <= sqrt(a); i++) {;
        if(a % i == 0) {
            long long diff = (a / i) - i;

            if(diff < smallestPerimeterDifference) {
                smallestPerimeterDifference = diff;
                smallestPerimeter = 2 * ((a / i) + i);
            }
        }
    }

    if(a == 1) {
        cout << 4;
    } else {
        cout << smallestPerimeter;
    }

    return 0;
}

// the smallest difference between length and width will minimize perimeter, there is no need to simulate every possibility
// division of an integer cuts off the decimal, this means the lower value is returned, this works well in our case as the upper/lower limit will both not have a possible answer to it so we can just take the lower one