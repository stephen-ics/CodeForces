//
// Created by Stephen Ni on 2024-01-16.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> map;


    for(int i = 0; i < n; i++) {
        char query;
        string s1;
        string s2;

        cin >> query >> s1 >> s2;

        string s3 = s1 + '|' + s2;

        if(query == '?') {
            if(map.find(s3) != map.end()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        } else if(query == '+') {
            if(map.find(s3) == map.end()) {
                map[s3] = 1;
            }
        } else if(query == '-') {
            if(map.find(s3) != map.end()) {
                map.erase(s3);
            }
        }
    }

    return 0;
}