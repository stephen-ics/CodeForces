//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(){
    // suppose a <= b when (b mod a != 0) the answer is suboptimal, this also means that b | a (b is divisible by a) --> this maximizes gcd(a, b) which minimizes LCM
    // b mod a = 0 implies that LCM(a, b) = b, therefore, the answer must be less than n (as a + b = n)
    // But if (b mod a != 0), then LCM(a, b) is at least 2b, and b is at least (n / 2), so in this case the answer is at least n

    // So if in the optimal answer b mod a = 0, this means that n mod a = 0 since n = a + b, so we only need to search for a among the divisors of n

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> divisors;

        divisors.push_back(1);

        for(int j = 2; j * j <= n; j++) {
            if(n % j == 0) {
                divisors.push_back(j);
                divisors.push_back(n / j);
            }
        }

        int min_a, min_b;
        int max_gcd = 0; // max gcd

        for(int j = 0; j < divisors.size(); j++) {
            int a = divisors[j];
            int b = n - a;

            int gcd_ab = gcd(a, b);

            if(gcd_ab > max_gcd) {
                min_a = a;
                min_b = b;
                max_gcd = gcd_ab;
            }

        }

        cout << min_a << " " << min_b << endl;
    }




    return 0;
}


