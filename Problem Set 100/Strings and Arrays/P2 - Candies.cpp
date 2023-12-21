//
// Created by Stephen Ni on 2023-12-21.
//

//
// Created by Stephen Ni on 2023-12-21.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int candies[n];

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        candies[i] = val;

    }

    int a, b;
    cin >> a >> b;

    int sum = 0;

    for(int i = a; i <= b; i++) {
        sum += candies[i];
    }

    cout << sum;


    return 0;
}