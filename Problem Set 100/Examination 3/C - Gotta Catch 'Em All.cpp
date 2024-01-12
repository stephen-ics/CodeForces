//
// Created by Stephen Ni on 2024-01-11.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> pokemon;

    int count = 0;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if(pokemon.find(val) == pokemon.end()) {
            pokemon[val] = 1;
            count++;
        }

        cout << count << " ";
    }

    return 0;
}