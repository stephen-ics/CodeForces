//
// Created by Stephen Ni on 2023-12-26.
//

//
// Created by Stephen Ni on 2023-12-26.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int count = 0;

    // if sqrt(x) < n; use sqrt(x) as the highest bound
    // else if sqrt(x) > n;  just use n as the higher bound

    if(sqrt(x) < n) {
        for(int i = 1; i <= sqrt(x); i++) {
            if(x % i == 0) {
                int div1 = i;
                int div2 = x / i;

                if(div1 == div2) {
                    count++;
                }
                else if(div2 <= n) {
                    count+= 2;
                }
            }
        }
    } else { // if sqrt(x) > n you need to iterate up to n
        for(int i = 1; i <= n; i++) {
            if(x % i == 0) {
                int div1 = i;
                int div2 = x / i;

                if(div1 == div2) {
                    count++;
                }
                else if(div2 <= n) {
                    count+= 2;
                }
            }
        }
    }

    cout << count;


    return 0;
}