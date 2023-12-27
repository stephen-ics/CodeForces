//
// Created by Stephen Ni on 2023-12-27.
//

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b, c, r;
        cin >> a >> b >> c >> r;

        if(a > b) {
            int d = b;
            b = a;
            a = d;
        }

        if(c < b && c > a) {
            if(c - r < a && a + r > b) {
                int time = (b - a) - (c - a) - (b - c);
                if(time > 0) {
                    cout << time << endl;
                }
                else {
                    cout << 0 << endl;
                }
            }
            else if(c - r < a) {
                int time = (b - a) - r - (c - a);

                if(time > 0) {
                    cout << time << endl;
                }
                else {
                    cout << 0 << endl;
                }

            } else if (c + r > b) {
                int time = (b - a) - r - (b - c);
                if(time > 0) {
                    cout << time << endl;
                }
                else {
                    cout << 0 << endl;
                }

            } else {
                int time = (b - a) - (2*r);
                if(time > 0) {
                    cout << time << endl;
                } else {
                    cout << 0 << endl;
                }
            }
        } //3 -3 -2 3
        else if (c <= a) {
            if(c + r >= a) {
                int time = (b - a) - (r - (a - c));
                if(time > 0) {
                    cout << time << endl;
                } else {
                    cout << 0 << endl;
                }
            } else {
                cout << (b - a) << endl;
            }
        }
        else if (c >= b) {
            if(c - r <= b) {
                int time = (b - a) - (r - (c - b));

                if(time > 0) {
                    cout << time << endl;
                } else {
                    cout << 0 << endl;
                }
            }
            else {
                cout << (b - a) << endl;
            }
        }

    }

    return 0;
}