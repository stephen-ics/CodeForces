//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>

using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int leastLcm = 1000000000;
        int least_a, least_b;

        for(int j = 1; j <= n/2; j++) {
            int a = j;
            int b = n-j;

            int gcd_ab = gcd(a, b);
            int lcm = (a * b) / gcd_ab;

            if(lcm < leastLcm) {
                leastLcm = lcm;
                least_a = a;
                least_b = b;
            }
        }

        cout << least_a << " " << least_b << endl;
    }

    return 0;
}


// lcm(a, b) = (a * b) / gcd(a, b)
// so the question is what is the fastest way to calculate gcd?

// **ANNOTATE CHAPTER 21 NUMBER THEORY UP TO PAGE 206 (from page 197)