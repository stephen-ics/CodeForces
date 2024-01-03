//
// Created by Stephen Ni on 2024-01-03.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const std::pair<char, int>& a, const std::pair<char, int>& b)
{
    return a.second < b.second;
}

int main() {
    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    unordered_map<char, int> map;

    for(int i = 0; i < str.length(); i++) {
        if(map.find(str[i]) != map.end()) {
            map[str[i]]++;
        } else {
            map[str[i]] = 1;
        }
    }

    std::vector<std::pair<char, int> > vec(map.begin(), map.end()); // copy map into vector to allow it to be sorted

    std::sort(vec.begin(), vec.end(), cmp);

    if(vec[vec.size() - 1].second > k) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}