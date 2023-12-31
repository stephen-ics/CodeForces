//
// Created by Stephen Ni on 2023-12-31.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> map;


    for(int i = 1; i < n; i++) {
        int num;
        cin >> num;

        map[num]= 1;
    }

    for(int i = 1; i <= n; i++) {
        if(map.find(i) == map.end()) {
            cout << i;
        }
    }



    return 0;
}

