//
// Created by Stephen Ni on 2023-12-30.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int benches[n];

    for(int i = 0; i < n; i++) {
        cin >> benches[i];
    }

    sort(benches, benches+n);

    int most = benches[n-1] + m;

    int least;
    for(int i = 0; i < m; i++) {
        benches[0]++;
        sort(benches, benches+n);
    }

    least = benches[n-1];


    cout << least << " " << most;
}